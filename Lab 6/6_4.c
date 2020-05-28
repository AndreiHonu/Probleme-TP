#include <stdio.h>
#include <stdlib.h>

#define CITIRE(TEXT,g,VAR,MIN,MAX)    \
    do{         \
        printf(TEXT":");        \
        scanf("%" #g, &VAR);       \
    }while( VAR < MIN && VAR > MAX) \


/**
    Macro-ul ar trebui sa ceara de la tastatura valoare pt x atat timp cat x nu este in interval
*/
int main()
{
    float x;
    CITIRE("x = ",g,x,0,10);

    return 0;
}
