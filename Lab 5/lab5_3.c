#include <stdio.h>
#include <stdlib.h>
void citirematrice(int m,int n,int a[10][10])
{
    int i,j;
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
      {
         printf("a[%d][%d] = ",i,j);
         scanf("%d",&a[i][j]);
      }

    }
}
void afisare(int m,int n, int b[10][10])
{
    int i,j;
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
      {
        printf("%3d  ",b[i][j]);
      }
      printf("\n" );
    }
}
int main(int argc, char const *argv[]) {
  if(argc != 2)
  {
    printf("nr gresit de argumente\n");
    return 0;
  }
  FILE *fis;
  int m,n;
  int i,j;
  int a[10][10];
  int b[10][10];

  printf("m = ");
  scanf("%d",&m);
  printf("n = ");
  scanf("%d",&n);

  citirematrice(m,n,a);

  if((fis=fopen(argv[1],"w"))==NULL){
    printf("eror fopen fis\n");
    return 0;
  }

  fwrite(&m,sizeof(int),1,fis);
  fwrite(&n,sizeof(int),1,fis);

  for(i = 0; i < m; i++)
  {
    for(j = 0; j < n; j++)
    {
        fwrite(&a[i][j],sizeof(int),1,fis);
    }
  }
  fclose(fis);
  if((fis = fopen(argv[1],"r"))==NULL){
    printf("error fopen fis\n");
    return 0;
  }

  for(i = 0; i < m; i++)
  {
    for(j = 0; j < n; j++)
    {
        fread(&b[i][j],sizeof(int),1,fis);
    }
  }

  fclose(fis);


  return 0;
}
