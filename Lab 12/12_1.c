#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
///Greedy
typedef struct{
    float x;
    float y;

}Punct;

float distanta(Punct p,Punct origine)
{
    float dist;

    dist = sqrt((p.x - origine.x)*(p.x - origine.x) + (p.y -origine.y)*(p.y -origine.y));

    return dist;

}
void stergere(Punct *p,int pos,int n)
{
    int i;
    for(i = pos; i < n-1; i++)
    {
        p[i] = p[i+1];
    }
    n--;
}
int main()
{
    int n;
    int i,pos;
    int contor;
    float min = INT_MAX;
    float dist;
    Punct *p;
    Punct origine;

    printf("n = ");
    scanf("%d",&n);
    if(n >=100)
    {
        printf("n nu este mai mica decat 100");
        scanf("%d",&n);
    }
    contor = n;
    p = (Punct *)malloc(n*sizeof(Punct));
    if(p == NULL)
    {
        printf("alocare p nereusita");
        exit(EXIT_FAILURE);
    }
    origine.x = 0.0;
    origine.y = 0.0;

    for(i = 0; i < n; i++)
    {
        printf("coordonata x[%d]:",i);
        scanf("%f",&p[i].x);
        printf("coordonata y[%d]:",i);
        scanf("%f",&p[i].y);
    }

    do
    {
        for(i = 0; i < n; i++)
        {
            dist = distanta(p[i],origine);
            if(distanta <= min)
            {
                min = distanta;
                pos = i;
            }
        }
        printf("Punctul are coord %.2f si %.2f\n",p[pos].x,p[pos].y);
        stergere(p,pos,n);
        contor--;
    }while(contor);


    return 0;
}

