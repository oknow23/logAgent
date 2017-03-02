# logAgent
Easy and convenient combine print and log recode for debug
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
