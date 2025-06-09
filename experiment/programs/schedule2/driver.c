#include <stdio.h>


#include "schedule2.h"


extern FILE* mystdin;

void driver(int tc_number, int argc, char  *argv[])
{
   FILE* fp;
   int nprocs, status, pid, prio;


   switch (tc_number)
   {
        case 0:
	        
    		for(prio = MAXPRIO; prio > 0; prio--)
    		{
			if((nprocs = atoi(argv[MAXPRIO + 1 - prio])) < 0) exit_here(BADARG);
			for(; nprocs > 0; nprocs--)
			{
			    if(status = new_job(prio)) exit_here(status);
			}
		}
		fp = fopen(argv[MAXPRIO+1], "r");
		mystdin = fp;

		dispatch();
        break;
        case 1:
	        
    		for(prio = MAXPRIO; prio > 0; prio--)
    		{
			if((nprocs = atoi(argv[MAXPRIO + 1 - prio])) < 0) exit_here(BADARG);
			for(; nprocs > 0; nprocs--)
			{
			    if(status = new_job(prio)) exit_here(status);
			}
		}
		printf("\n%d\n", get_process(4, 0.5, 0));
        break;
        case 2:
	        
    		for(prio = MAXPRIO; prio > 0; prio--)
    		{
			if((nprocs = atoi(argv[MAXPRIO + 1 - prio])) < 0) exit_here(BADARG);
			for(; nprocs > 0; nprocs--)
			{
			    if(status = new_job(prio)) exit_here(status);
			}
		}
		printf("\n%d\n", get_process(-1, 0.5, 0));
        break;
        case 3:
	        
    		for(prio = MAXPRIO; prio > 0; prio--)
    		{
			if((nprocs = atoi(argv[MAXPRIO + 1 - prio])) < 0) exit_here(BADARG);
			for(; nprocs > 0; nprocs--)
			{
			    if(status = new_job(prio)) exit_here(status);
			}
		}
		printf("\n%d\n", get_process(2, -0.5, 0));
        break;
        case 4:
	        
    		for(prio = MAXPRIO; prio > 0; prio--)
    		{
			if((nprocs = atoi(argv[MAXPRIO + 1 - prio])) < 0) exit_here(BADARG);
			for(; nprocs > 0; nprocs--)
			{
			    if(status = new_job(prio)) exit_here(status);
			}
		}
		printf("\n%d\n", get_process(2, 1.5, 0));
        break;
   }
}
