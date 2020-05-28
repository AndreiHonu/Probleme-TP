#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nume[28];
float pret;
}Produs;


Produs produse[1000];
int nProduse;


void adaugare()
{
  Produs p;
  printf("nume: ");
  fgets(p.nume,28,stdin);
  p.nume[strcspn(p.nume,"\r\n")]='\0';
  printf("pret: ");
  scanf("%g",&p.pret);
  produse[nProduse]=p;
  nProduse++;
}

void afisare()
{
  int i;
  for(i=0;i<nProduse;i++){
    printf("%s: %g\n",produse[i].nume,produse[i].pret);
  }
}


int main(int argc, char *argv[])
{
  if(argc > 2)
  {
      printf("Sunt prea multe argumente in linia de comanda\n" );
      return 0;
  }
  FILE *fis;
  if((fis=fopen(argv[1],"w"))==NULL){
    printf("nu se poate deschide fisierul\n");
    exit(EXIT_FAILURE);
    }
  int nr;

  int optiune;
  do{
    printf("optiune: ");
    scanf("%d",&optiune);
    getchar();
    switch(optiune){
        case 1:adaugare();break;
        case 2:afisare();break;
        case 3:{
          nr = nProduse;
          fwrite(&nr,sizeof(nr),nr,fis);
          fwrite(produse,sizeof(Produs),nProduse,fis);
          break;
        }
        default:printf("optiune invalida\n");
    }
  }while(optiune!=3);
  fclose(fis);
  return 0;
}
