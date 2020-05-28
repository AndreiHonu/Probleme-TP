#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void absN(int n,...)
{
    va_list va;         ///lista de argumente variabile
    va_start(va,n);      ///initializare cu ultimul argument fix
    float *val;
    int contor = 1;
    while(n)
    {
        val = va_arg(va,float*);
        contor++;
        printf("Valoare absoluta a %d numar  este %d\n",contor,abs(val));
        n--;
    }
    va_end(va);
}
/**
    Se primeste nr de adrese si apoi intr-o variabila de tip float se primesc acele adrese, si se afiseaza valoarea absoluta;
*/
int main()
{
    int x,y;
    absN(2,&x,&y);
    return 0;
}

