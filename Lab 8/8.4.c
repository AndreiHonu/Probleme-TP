#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int crescator(int n,char tip,...)
{
    va_list va;   ///lista de argumente variabile
    va_start(va,tip);   ///initializare cu ultimul argument fix

    int valI,valcurrI,valinitI;         ///initializari pt variabile de tip int
    double valD,valcurrD,valinitD;      ///initializari pt variabile de tip float
    int ok = 0;   ///float

    if(tip == 'd')        ///verifica ce tip de variabile sunt int/float si intra in caz
    {
        valinitI = va_arg(va,int);   ///retine prima valoare din va ca si val init
        while(tip && n)        /// o bucla care trece prin fiecare variabila
        {
            valI = va_arg(va,int);   ///preia urm valoare din va
            valcurrI = valI;    ///memoram valoare ca si valoare curenta
            if(valinitI <= valcurrI)    ///conditie pt sir crescator
            {
                valinitI = valcurrI;    ///retine val curenta ca si cea initiala pt repetare verif
                ok = 1; ///contor trece pe 1
            }
            else
            {
                ok = 0;     ///cum nu s-a indeplinit conditia contor trece pe 0 si se returneaza valoarea
                return ok;
            }
            n--;

        }
    }

    if(tip == 'f')    ///cazul in care sunt variabile de tip float
    {
        valinitD = va_arg(va,double);
        while(tip && n)
        {
            valD = va_arg(va,double);
            valcurrD = valD;
            if(valinitD <= valcurrD)
            {
                valinitD = valcurrD;
                ok = 1;
            }
            else
            {
                ok = 0;
                return ok;
            }
            n--;
        }
    }
    va_end(va);
    return ok;   ///returneaza contor pe 1 dupa ce a trecut prin toate verificarile
}
/**


*/
int main()
{
    printf("%d",crescator(3,'d',-1,7,9));
    return 0;
}

