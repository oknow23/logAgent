/*Easy and convenient combine print and log recode
 * oknow: [2017/03/01]
 * Description:
 *	#print format message
 *	#automatic write log file like "test_20170301.log"
 *	#use date as the log name
 *	#delete log file when expired ten date,and you can configure in aglog.h
 *	#change day to check expired log
 * 
 * How to build:
 * 	make
 * 
 * How to use:(add below example)
 * 	#include "aglog.h"
 * 	printa(stderr,"only print\n");
 * 	printl(stderr,"print and write to log\n");
 * 	
 * 	resulet:
 * 		oknow[test.c:14] only print
 * 		oknow[test.c:15] print and write to log
 * 
 *  cat test_20170302.log 
 * 		09:56:09 oknow[test.c:15] hello world!!
 * 		09:56:13 oknow[test.c:15] hello world!!
 * 		09:56:15 oknow[test.c:15] hello world!!
 * 		10:24:04 oknow[test.c:15] hello world!!
 *		10:30:37 oknow[test.c:15] print and write to log
 * 		10:35:28 oknow[test.c:15] print and write to log
*/

/*configure option*/
#define LOGAG_VERSION			0.0.1
#define EXPIRED_DAY		10			//delete log file time
#define LOG_HEAD		""			//if empty,use file name
#define AUTHOR			""		//show name in message
#define	LOGDBG			0
#define FILE_NAME 		"RuleEngine"

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/*printa (print agnent )*/
#define printa(type,message) fprintf(type,"%s[%s:%d] %s",AUTHOR, __FILENAME__, __LINE__, message)
/*printl (print and log )*/
#define printl(type,message) printa(type,message);writeLog(message, __FILENAME__, __LINE__);