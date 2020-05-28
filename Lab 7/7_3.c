#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(DEBUG) || defined(_DEBUG)
    #define DBG(...)		fprintf(stderr,__VA_ARGS__)
#else
    #define DBG(...)
#endif


double vmax(double *v,int n)
{

    int i;
    double m = v[0];
    /// Aceasta bucla va fi activa numa dac exista DBG
    for(i = 0; i < n; i++)
    {
        DBG("v[%d] = %lg\n",i,v[i]);
    }

    for(i = 1; i < n; i++){
        if(m < v[i]) m = v[i];
        }
    return m;

}

int main()
{
    double *v;
    int i,n;

    printf("n=");
    scanf("%d", &n);

    v=(double*)malloc(n*sizeof(double));
    if (v == NULL){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }

    for(i = 0; i < n; i++){

        printf("v[%d]=",i);
        scanf("%lg", &v[i]);
        }

    printf("maximul este: %lg\n", vmax(v,n));
    free(v);

    return 0;
}
