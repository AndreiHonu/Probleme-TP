#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define STRINGIFY_AUX(val)  #val
#define STRINGIFY(txt)  STRINGIFY_AUX(txt)
/// Definirea assertului
#ifdef NDEBUG
    #define myassert(cond)
#else
    #define myassert(cond)  do{     \
        if(!(cond)){      \
            fprintf(stderr,"Assertion failed: " #cond ", file " __FILE__ ", line " STRINGIFY(__LINE__) "\n");    \
            abort();        \
            }       \
        }while(0)
#endif


double vmax(double *v,int n)
{

    int i;
    double m = v[0];

    for(i = 1; i < n; i++)
    {
        if(m < v[i]) m = v[i];
    }
    return m;

}
/// Functia test care verifica daca maximul este egal cu X care a fost transmis ca parametru
int test(double *v, int n, double x)
{
    int i;
    double maxim;

    maxim = v[0];

    for(i = 1; i < n; i++)
    {
        if(maxim < v[i]) maxim = v[i];
    }

    if(x == maxim) return 1;
    return 0;
}

int main()
{
    double *v;
    int i,n;
    double maxim;

    printf("n=");
    scanf("%d", &n);

    v=(double*)malloc(n*sizeof(double));
    if (v == NULL)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++)
    {
        printf("v[%d] = ", i);
        scanf("%lg", &v[i]);
    }

    maxim = vmax(v,n);

    assert(test(v,n,maxim));       /// Daca functia test va avea output 0 atunci prg se va termina, altfel va continua

    printf("maximul este: %lg\n", maxim);
    free(v);

    return 0;
}

