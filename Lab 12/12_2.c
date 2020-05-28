/// Divide & Conquer
#include <stdio.h>
#include <stdlib.h>
#define G 6.674e-11

float forta(float m1,float m2,float d)
{
    float F = 0;

    F = (G * m1 * m2) / (d * d);

    return F;
}
/// Functia calculeaza forta dupa formula data
int nr_puncte(int n,float d)
{
    int nr_pct;
    nr_pct = d / n;
    return nr_pct;
}
/// Functie care calculeaza cate puncte de distante egale sunt
int main()
{
    int n;
    int nr,i;
    int aux;
    float ma,mb,m,d;
    float F;

    printf("numarul de pasi n = ");
    scanf("%d",&n);
    if(n <= 0)
    {
        printf("n nu este strict pozitiv, introduceti alt n:");
        scanf("%d",&n);
    }
    printf("Masa corpului a este: ");
    scanf("%f",&ma);
    printf("Masa corpului b este: ");
    scanf("%f",&mb);
    printf("Masa corpului m care porneste din a si ajunge in b: ");
    scanf("%f",&m);
    printf("Distanta dintre a si b:");
    scanf("%f",&d);

    F = forta(ma,mb,d);
    if(F < 0)
    {
        printf("m este atras de catre ma\n");
    }
    else
    {
        printf("m este atras de catre mb\n");
    }

    nr = nr_puncte(n,d);
    aux = nr-1;

    for(i = 0; i < nr; i++)
    {
        F = forta(ma,mb, d - ( aux * ( d / nr ) ) );
        printf("Forta este %.2f Newtoni\n",F);
        aux--;
    }
/// Pt fiecare punct se afiseaza forta calculata cu distanta potrivita
    return 0;
}

