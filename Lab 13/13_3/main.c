#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

float max = INT_MIN;

void solve(float *vobiect,int n,float v)
{
    int i;
    if(max > v) return 0;
    for(i = 0; i < n; i++)
    {
        if(vobiect[i] > max && vobiect[i] <= v)
        {
            max = vobiect[i];
            printf("%.2f",max);
            solve(vobiect,n,v-max);
        }
    }


}

int main()
{
    int n;
    int i;
    float *vobiect;
    float v;
    printf("n = ");
    scanf("%d",&n);
    if(n <= 0 || n > 100)
    {
        printf("n nu se afla intre parametrii conditii,introduceti un alt n\n n = ");
        scanf("%d",&n);
    }

    vobiect = (float *)malloc(n*sizeof(float));
    if(vobiect == NULL)
    {
        printf("alocare vobiect nereusita");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++)
    {
        printf("vobiect[%d] = ",i);
        scanf("%f",&vobiect[i]);
    }
    printf("v volumul cutiei este = ");
    scanf("%f",&v);

    solve(vobiect,n,v);

    free(vobiect);
    return 0;
}
