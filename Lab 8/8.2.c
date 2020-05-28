#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double *allocVec(int n,...)
{
    va_list va;         ///lista de argumente variabile
    va_start(va,n);      ///initializare cu ultimul argument fix
    double *a;
    int contor = 0;

    a = (double*)malloc(n * sizeof(double));
    if(a == NULL)
    {
        printf("alocare a nereusita");
        exit(EXIT_FAILURE);
    }
    while(n)
    {
        a[contor] = va_arg(va,double);
        contor++;
        n--;

    }
    va_end(va);
    return a;
}
/**
    Functia primeste ca prim argument cate elemente va avea vectorul, il aloca dinamic si apoi pornind de la arg n, cu ajutorul
    unui contor pune fiecare valoare in vector.
*/
int main()
{
    double *v;
    int i;
    int n;
    printf("n = ");
    scanf("%d",&n);

    v = allocVec(n,7.2,-1.0,25.0,5.0);
    for(i = 0; i < n; i++)
    {
        printf("v[%d] = %.2lf\n",i,v[i]);
    }
    free(v);
    return 0;
}

