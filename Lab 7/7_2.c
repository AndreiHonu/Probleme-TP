#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMPLICIT 1

#ifdef IMPLICIT
    #define FN_ABS                       \
        double abs_real(double a){         \
                return fabs(a);                \
    }                                          \

#endif

#ifndef IMPLICIT
   #define FN_ABS             \
   double abs_real(double a){         \
                return 1;                      \
    }                                          \

#endif // IMPLICIT


FN_ABS

int main()
{

    double a;

    printf("a = ");
    scanf("%lg", &a);

    printf("Valoare absoluta a lui a este : %d", abs_real(a));

    return 0;
}

