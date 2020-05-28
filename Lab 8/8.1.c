#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void err(int cond,const char *fmt,...) ///prima variabila este cond
{
    va_list va;      ///lista de argumente variabile
    va_start(va,fmt);      ///initializare cu ultimul argument fix
    if(cond == 1)
    {
        fprintf(stderr,"eroare: ");
        vfprintf(stderr,fmt,va);
    }
    else return 0;
    va_end(va);
    fputc('\n',stderr);
    exit(EXIT_FAILURE);
}

int main()
{
    int i,n;
    float x,y,e,min,max;

    printf("n=");scanf("%d",&n);
    err(n<=0||n>100,"n invalid: %d\n",n);
    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);
    err(x>=y,"x=%g nu este mai mic decat y=%g\n",x,y);
    max=x;
    min=y;
    for(i=0;i<n;i++){
        printf("e=");scanf("%g",&e);
        err(e<x||e>y,"element invalid: %g\n",e);
        if(e<min)min=e;
        if(e>max)max=e;
        }
    printf("min: %g, max: %g\n",min,max);
    return 0;
}

