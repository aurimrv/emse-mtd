

#include <stdio.h>
#include <stdlib.h>

extern FILE* mystdin;
extern int r,c;
extern long f[];

double
InfoTbl( int, int, long *, int *);

double QGamma(double, double);
double LGamma(double);
double QChiSq(double, int);

void driver(int tc_number, int argc, char  *argv[])
{
   FILE* fp;
   int k = k;

   switch (tc_number)
   {
        case 0:
	    fp = fopen(argv[1], "r");
	    mystdin = fp;
   	    printf("%d\n", dispatch());
        break;
        case 1:
	    fp = fopen(argv[3], "r");
	    mystdin = fp;
   	    printf("%d\n", dispatch());
            printf("%lf %d\n", InfoTbl(r, c, f, &k), k);
        break;
        case 2:
         {
            double a, x;
            
	    a = atof(argv[3]);
            x = atof(argv[4]);
            printf("%15.10lf\n", QGamma(a,x));
            break;
         }
        case 3:
         {
            double x;
            
	    x = atof(argv[3]);
            printf("%lf\n", LGamma(x));
            break;
         }
         case 4:
         {
            double a;
            int x;
            
	    a = atof(argv[3]);
            x = atoi(argv[4]);
            printf("%lf\n", QChiSq(a,x));
            break;
         }

   }
}
