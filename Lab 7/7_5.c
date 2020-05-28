#include <stdio.h>
#include <stdlib.h>

void functie(char *v,int n)
{
    int i,j;
    #if !__GNUC__
        return 0;
    #endif

    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        for(i = 0; i < n; i++)
        {
            for(j = 0; j <= sizeof(v[i]) * 8 - 1; j++)
            {
                printf("%d", (v[i]>>j) & 1);
            }
            printf("\n");
        }
    #endif // __BYTE_ORDER__

    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        for(i = 0; i < n; i++)
        {
            for(j = sizeof(v[i]) * 8 - 1; j >= 0; j--)
            {
                printf("%d",(v[i] >> i) & 1);
            }
            printf("\n");
        }
    #endif // __BYTE_ORDER__


}


int main()
{
    int n;
    int i;
    char *v;

    printf("n = ");
    scanf("%d", &n);

    v = (char *)malloc(n * sizeof(char));
    if(v == NULL)
    {
        printf("alocare v nereusita");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++)
    {
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }

    functie(v,n);

    return 0;
}

