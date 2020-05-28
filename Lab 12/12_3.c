
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int m,n;
    int i,j;
    int **a;
    int reducere;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int min;

    printf("Introduceti nr m de linii:");
    scanf("%d",&m);
    printf("Introduceti nr n de coloane:");
    scanf("%d",&n);

    if(m == 0 && n == 0)
    {
        reducere = 0;
        printf("Reducerea este %d\n",reducere);
        return 0;
    }

    a = (int **)malloc(m * sizeof(int *));
    if(a == NULL)
    {
        printf("alocare a nereusita");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        if(a[i] == NULL)
        {
            printf("alocare a[i] nereusita");
            exit(EXIT_FAILURE);
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    if(m == 1 && n == 1)
    {
        reducere = a[0][0];
        printf("Reducerea este %d\n",reducere);
        for(i = 0; i < m; i++)
        {
            free(a[i]);
        }
        free(a);
        return 0;
    }

    for(i = 0; i < m/2; i++)
    {
        for(j = 0; j < n/2; j++)
        {
            if(a[i][j] >= max1) max1 = a[i][j];
        }
    }
    for(i = 0; i < m/2; i++)
    {
        for(j = n/2; j < n; j++)
        {
            if(a[i][j] >= max2) max2 = a[i][j];
        }
    }
    for(i = m/2; i < m; i++)
    {
        for(j = 0; j < n/2; j++)
        {
            if(a[i][j] <= min1) min1 = a[i][j];
        }
    }
    for(i = m/2; i < m; i++)
    {
        for(j = n/2; j < n; j++)
        {
            if(a[i][j] <= min2) min2 = a[i][j];
        }
    }
    if(max1 > max2) max = max1;
    else max = max2;

    if(min1 < min2) min = min1;
    else min = min2;

    reducere = max - min;
    printf("Reducerea este %d",reducere);



    for(i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
    return 0;
}
