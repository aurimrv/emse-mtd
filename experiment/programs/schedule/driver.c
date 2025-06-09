#include <stdio.h>


#include "schedule.h"


extern FILE* mystdin;
extern int num_processes;

void driver(int tc_number, int argc, char  *argv[])
{
   FILE* fp;
   int prio;

   switch (tc_number)
   {
        case 0:
	        
    		initialize();
    		for (prio=MAXPRIO; prio >= 1; prio--)
    		{
			init_prio_queue(prio, atoi(argv[prio]));
    		}
		fp = fopen(argv[MAXPRIO+1], "r");
		mystdin = fp;
		dispatch();
        	break;
       case 1:	        
    		initialize();
    		for (prio=MAXPRIO; prio >= 1; prio--)
    		{
			init_prio_queue(prio, atoi(argv[prio+2]));
    		}
		fp = fopen(argv[MAXPRIO+3], "r");
		mystdin = fp;
		dispatch();
		printf("Remaining processes: %d\n", num_processes);
        	break;   
       case 2:	        
    		initialize();
    		for (prio=MAXPRIO; prio >= 1; prio--)
    		{
			init_prio_queue(prio, atoi(argv[prio+2]));
    		}
		fp = fopen(argv[MAXPRIO+3], "r");
		mystdin = fp;
		dispatch();
		printf("Remaining processes: %d\n", num_processes);
 
   		initialize();
    		for (prio=MAXPRIO; prio >= 1; prio--)
    		{
			init_prio_queue(prio, atoi(argv[prio+2]));
    		}
		fp = fopen(argv[MAXPRIO+3], "r");
		mystdin = fp;
		dispatch();
		printf("Remaining processes: %d\n", num_processes);
        	break;   
   }
}
