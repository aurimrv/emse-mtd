#include <stdio.h>
#include <stdlib.h>



double Phi2(double, double, double);
double phi01(double);
double PhiInverse(double);
double Phi201(double);
double phi(double, double, double);
double PhiInverse02(double, double, double, double);


void driver(int tc_number, int argc, char *argv[])
{
double z, mu, sigma;

    switch (tc_number)
    {
        case 0:
        {
            double y;
            
            z = atof(argv[1]);
            mu = atof(argv[2]);
            sigma = atof(argv[3]);
            printf("%20.16lf %20.16lf\n" , phi01(z), phi(z, mu, sigma));
        }
        break;
        case 1:
        {
            double y;
            
            z = atof(argv[3]);
            mu = atof(argv[4]);
            sigma = atof(argv[5]);
            printf("%20.16lf %20.16lf\n" , Phi201(z), Phi2(z, mu, sigma));
        }
        break;
        case 2:
        {
            double y;
            
            z = atof(argv[3]);
            printf("%20.16lf %20.16lf %20.16lf\n" , Phi201(z), PhiInverse(Phi201(z)), PhiInverse(z));
        }
        break;
        case 3:
        {
            double y, lo, delta, hi;
            z = atof(argv[3]);
            delta = atof(argv[4]);
            lo = atof(argv[5]);
            hi = atof(argv[6]);
            printf("%20.16lf %20.16lf %20.16lf\n" , Phi201(z), PhiInverse02(Phi201(z), delta, lo, hi),
                                                    PhiInverse02(z, delta, lo, hi));
        }
        break;
    }
}
