#include <stdio.h>
#include "replace.h"

extern FILE* mystdin;

void driver(int tc_number, int argc, char  *argv[])
{
   string pat, sub;
   bool result;
   FILE* fp;
 

   switch (tc_number)
   {
        case 0:
	    result = getpat(argv[1], pat);
 	    result = getsub(argv[2], sub);
	    fp = fopen(argv[3], "r");
	    mystdin = fp;
   	    change(pat, sub);
        break;
   }
}
