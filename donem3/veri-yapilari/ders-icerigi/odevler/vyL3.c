#include <stdio.h>

#define    SATIR   4
#define    SUTUN   4

int main()
{
      FILE *p = NULL;
      int mat1[SATIR][SUTUN];
      int mat2[SATIR][SUTUN];
      int sonuc[SATIR][SUTUN];
      char *okunacakdosya = "matrisler.txt";
      char *yeni = "sonuc.txt";
      int i, j,k,l;



    if((p = fopen("matrisler.txt", "r")) != NULL){
         for(i = 0; i < SATIR; i++){
            for(j = 0; j < SUTUN; j++){
                fscanf(p, "%d", &mat1[i][j]);
                printf("%d ", mat1[i][j]);
            }
          printf("\n");
      }

 for(int i=0;i<16;i++){
        int *p=mat1[0];
        printf("%d",p[i]);
              }

 printf("\n");

        for(k = 0; k < SATIR; k++){
            for(l = 0; l < SUTUN; l++){
                fscanf(p, "%d", &mat2[k][l]);
                printf("%d ", mat2[k][l]);
                 }
          printf("\n");
      }
for(int i=0;i<16;i++){
        int *k=mat2[0];
        printf("%d",k[i]);
              }

      }else{

        printf("%s dosyasi bulunamadi!", okunacakdosya);
    }
    fclose(p);


   printf("\n");
   FILE *dosya1;
   dosya1 = fopen("sonuc.txt","w");


    for(i=0;i<SATIR;i++){
      for(j=0;j<SUTUN;j++){
        int toplam=0;
          for(k=0;k<4;k++){
    toplam+=mat1[i][k]*mat2[k][j];
    }
    sonuc[i][j]=toplam;
    fprintf(dosya1,"%4d",sonuc[i][j]);
    printf("%4d",sonuc[i][j]);
    }
    fprintf(dosya1,"\n");
    printf("\n");
}
  fclose(dosya1);

return 0;
}
