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
    printf("----------------\n");
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
elem *addend(elem *lista,int n)
{
    if(!lista)return nou(n,NULL);
    elem *p = lista, *urm;
    for(urm = p->urm;urm;p = urm,urm = p->urm){}
    p->urm = nou(n,NULL);
    return lista;
}
int verif(elem *lista, int x)
{
    int ok = 0;
    for(; lista; lista = lista -> urm)
    {
        if(lista -> n == x)
            ok = 1;
    }
    return ok;
}
elem *combinare(elem *lista1, elem *lista2)
{
    elem *combinat = NULL;
    for(; lista1; lista1 = lista1 -> urm)
    {
        if(verif(combinat,lista1 -> n) == 0){
            addend(combinat,lista1 -> n);
        }
    }
    for(; lista2; lista2 = lista2 -> urm)
    {
        if(verif(combinat,lista2 -> n) == 0){
            addend(combinat,lista2 -> n);
        }
    }
    return combinat;
}


int main()
{
    elem *lista1 = nou(108,nou(-1,nou(49,NULL)));
    elem *lista2 = nou(107,nou(-2,nou(50,NULL)));
    elem *reuniune = NULL;
    afisare(lista1);
    afisare(lista2);
    reuniune = combinare(lista1,lista2);
    afisare(reuniune);
    eliberare(lista1);
    eliberare(lista2);
    eliberare(reuniune);






    return 0;
}

