#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define FN_SORTARE(TIP)                                   \
    void sort_##TIP(TIP *p, int n)                        \
    {                                                     \
        int i,j;                                          \
        int aux;                                          \
        for(i = 0; i < n - 1; i++){                       \
            for(j = 0; j < n - i - 1; j++){               \
                if( p[j] > p[j+1]){                       \
                    aux = p[j];                           \
                    p[j] = p[j+1];                        \
                    p[j+1] = aux;                         \
                }                                         \
            }                                             \
        }                                                 \
    }                                                     \


/**
    Acest macro sorteaza vectorul pe care il primeste folosind bubble sort.
*/

FN_SORTARE(int)

///Citirea vectorului
void citire(int *p, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("v[%d] = ",i);
        scanf("%d",&p[i]);
    }
}

/// Afisare
void afisare(int *p, int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d  ",p[i]);

}
int main()
{
    int n;
    int *v;

    printf("Introduceti dimensiunea vect : ");
    scanf("%d",&n);

    v =(int *)malloc(n*sizeof(int));
    if(v == NULL)
    {
        perror("alocare nereusita");
        return errno;
    }

    printf("Introducere vector :\n");
    citire(v,n);

    sort_int(v,n);

    printf("Vectorul dupa sortare:\n");
    afisare(v,n);


    free(v);

    return 0;
}


