#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

#include "logAgent.h"
#define LOGLIST_PATH	"/tmp/loglist.txt"

static char date[64];

int getTime(char *p) {
	time_t lt;
	time(&lt);

	struct tm* tm_1 = localtime(&lt);
//	sprintf(p, "%d%02d%02d%02d%02d%02d", tm_1->tm_year -100, tm_1->tm_mon + 1,
//			tm_1->tm_mday, tm_1->tm_hour, tm_1->tm_min, tm_1->tm_sec);
	sprintf(p, "%02d:%02d:%02d",  tm_1->tm_hour, tm_1->tm_min, tm_1->tm_sec);
	
	return 1;
}

int writeLog(char *msg,char *file_name,int line)
{
	char buf[1024];
	char fn[64];
	char time[64];
	
	system("mkdir -p log");
	check_log_expried(fn,file_name);
	getTime(time);
	sprintf(buf,"echo -n '%s %s[%s:%d] %s' >> %s",time,AUTHOR, file_name, line,msg,fn);
	if(LOGDBG)fprintf(stdout,"billy[%s:%d,%s] buf = %s\n",__FILE__, line, __FUNCTION__,buf);
	system(buf);

	return 1;
}

int remove_sub_name(char *log_name,char *file_name){
	char *p;
	
	/*deside use file name or define name*/
	sprintf(log_name,"log/%s",(strlen(FILE_NAME) > 1)?FILE_NAME:file_name);
	p = strchr(log_name,'.');
	if(p!= NULL)
		*p = '\0';
}

int getLogName(char *date,char *file_name)
{
	char log_name[128];
	time_t lt;
	time(&lt);

	if(strlen(LOG_HEAD) == 0){
		remove_sub_name(log_name,file_name);
	}
	
	struct tm* tm_1 = localtime(&lt);
	sprintf(date, "%s_%d%02d%02d.log",log_name, tm_1->tm_year + 1900, tm_1->tm_mon + 1,
			tm_1->tm_mday);
	return 0;
}

int delExpiredLog(char *file_name){
	FILE *fp;
	char log_name[64];
	char cmd[128];
	int i = 0;
	
	remove_sub_name(log_name,file_name);
	sprintf(cmd,"ls -r %s*.log > %s 2>/tmp/lserror.log",log_name,LOGLIST_PATH);
	system(cmd);
	if((fp = fopen(LOGLIST_PATH,"r"))){
		while(fgets(log_name,64,fp)){
			i++;
//			printf("billy[%s:%d,%s] log_name = %s i = %d\n", __FILENAME__, __LINE__, __FUNCTION__,log_name,i);
			if(i >= EXPIRED_DAY){
				sprintf(cmd,"rm -f %s",log_name);
//				printf("billy[%d,%s] cmd = %s\n",  __LINE__, __FUNCTION__,cmd);
				system(cmd);
			}
		}
		fclose(fp);
	}
	else
		printf("billy[%d,%s] open loglist error\n", __LINE__, __FUNCTION__);
	return 0;
}

int check_log_expried(char *fn,char *file_name){
	
	getLogName(fn,file_name);
	if(strcmp(date,fn) == 0){
//		printf("billy[%d,%s] the same\n",  __LINE__, __FUNCTION__);
	}
	else{
//		printf("billy[%d,%s] not same\n",  __LINE__, __FUNCTION__);
		delExpiredLog(file_name);
		sprintf(date,"%s",fn);
	
	}
	return 0;
}
