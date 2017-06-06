/*print and log agent
 * 
 * 
 * 
 * */

#include <stdio.h>
#include <string.h>

#include "../logAgent.h"

int writeLog(char *msg,char *file_name,int line);

void main(void)
{
	char tmp_msg[1024];
	int i;

	printa(stderr,"only print\n");
	printl(stderr,"print and write to log\n");
	for(i = 0 ;i < 10;i++){
		sprintf(tmp_msg,"count = %d\n",i);printl(stdout,tmp_msg);
	}
}
