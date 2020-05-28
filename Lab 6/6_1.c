#include <stdio.h>
#include <stdlib.h>

#define MAX3(a,b,c) ((a)>(b)?(a)>(c)?(a):(c):(b)>(c)?(b):(c))

/**
   Acest macro contine o expresie conditionala care verifica daca primul argument este mai
   mare decat al 2 -lea, daca da verifica daca este mai mare si decat al 3-lea si apoi va
   fi maximul daca primul este mai mare daca nu al 3 -lea arg va fi maximul;
   daca nu verifica daca al 2 -lea este mai mare decat al 3-lea, daca da al 2 -lea este maximul
   daca nu al 3 -lea este maximul
*/


int main()
{
    int x,y,z;

    printf("x = ");
    scanf("%d",&x);
    printf("y = ");
    scanf("%d",&y);
    printf("z = ");
    scanf("%d",&z);

    printf("Maximul este %d\n",MAX3(x,y,z));

    return 0;
}
