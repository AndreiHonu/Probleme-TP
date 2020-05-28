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

elem *inversare(elem *lista)
{
    elem *curr = lista;
    elem *prev = NULL;
    elem *urmat = NULL;

    while(curr != NULL)
    {
        urmat = curr->urm;
        curr->urm = prev;
        prev = curr;
        curr = urmat;
    }
    return prev;
}

int main()
{
    elem *lista = nou(108,nou(-1,nou(49,NULL)));
    afisare(lista);
    afisare(inversare(lista));
    eliberare(lista);






    return 0;
}

