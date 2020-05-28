// main.c - meniu utilizator si comportament global
#include "util.h"
#include "bd.h"

#include <stdio.h>

int main()
{
    char nume[MAX_NUME];
    char sex[1];
    float salariu;
    Persoana *p;

    incarca();
    for(;;){
        printf("1. adaugare\n");
        printf("2. stergere\n");
        printf("3. listare\n");
        printf("4. iesire\n");
        int op;            // optiunea
        printf("optiune: ");scanf("%d",&op);
        switch(op){
            case 1:
                getchar();
                citesteText("nume",nume,MAX_NUME);
                salariu=citesteFloat("salariu");
                citesteText("sex",sex,1);
                adauga(nume,salariu,sex);
                break;
            case 2:
                getchar();
                citesteText("nume",nume,MAX_NUME);
                if(sterge(nume)){
                    printf("%s a fost sters din baza de date\n",nume);
                    }else{
                    printf("%s nu exista in baza de date\n",nume);
                    }
                break;
            case 3:
                for(p=bd;p;p=p->urm){
                    printf("%s\t%g\n%s\t",p->nume,p->salariu,p->sex);
                    }
                break;
            case 4:
                salveaza();
                elibereaza();
                return 0;
            default:printf("optiune invalida\n");
            }
        }
}
