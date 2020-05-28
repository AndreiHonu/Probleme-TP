#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int n;
    struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e = (elem*)malloc(sizeof(elem));
    if(!e)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e -> n = n;
    e -> urm = urm;
    return e;
}



void afisare(elem * lista)
{
    for(; lista; lista = lista -> urm)
    {
        printf("%d,",lista -> n);
    }
    putchar('\n');
}

void eliberare(elem *lista)
{
    elem *p;
    while(lista)
    {
        p = lista->urm;
        free(lista);
        lista = p;
    }
}

int compare(elem *lista1, elem *lista2)
{
    int ok = 0;
    for(; lista1; lista1 = lista1 ->urm)
    {
        for(; lista2; lista2 = lista2 -> urm)
        {
            if(lista1 -> n == lista2 -> n)
            {
                ok = 1;
                break;
            }
            else ok = 0;
        }
    }
    return ok;
}

int main()
{
    elem *lista1 = nou(108,nou(-1,nou(49,NULL)));
    elem *lista2 = nou(108,nou(-1,nou(49,NULL)));
    afisare(lista1);
    afisare(lista2);
    printf("|  %d  |",compare(lista1,lista2));
    eliberare(lista1);
    eliberare(lista2);





    return 0;
}

