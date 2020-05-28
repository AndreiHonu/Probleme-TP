#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  //if (argc != 3)return 0;
  FILE *fis;
  FILE *fit;

  int n,aux;
  int i;

  if((fis=fopen(argv[1],"r"))==NULL){
    printf("eror fopen fis\n");
    return 0;
  }
  if((fit=fopen(argv[2],"w"))==NULL){
    printf("eror fopen fit\n");
    return 0;
  }
  for(;;){
    if(fread(&n,sizeof(int),1,fis)==0)
    {
      fclose(fis);
      fclose(fit);
      return 0;
    }
    fread(&aux,sizeof(int),n,fis);
    i++;
  }

  fwrite(&aux,sizeof(int),i,fit);

  fclose(fis);
  fclose(fit);

  return 0;
}
