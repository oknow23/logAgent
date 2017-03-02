/*print and log agent
 * 
 * 
 * 
 * */

#include <stdio.h>
#include <string.h>

#include "../logAgent.h"

void main(void)
{
	printa(stderr,"only print\n");
	printl(stderr,"print and write to log\n");
}
