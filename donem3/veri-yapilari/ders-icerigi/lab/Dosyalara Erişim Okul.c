#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct student
{
    int id;
    char name[20];
    int score;
};


int main()
{
    struct student s;
    FILE *fp,*f;
    int n,rec;
    
    int selection;
    while (1)
    {
        printf("*** *** ***\n");
        printf("      1    -->    Dosyaya kayit ekle                             \n");
        printf("      2    -->    Dosyadan kayit oku(sirali erisim ile)          \n");
        printf("      3    -->    Dosyadan kayit oku(dogrudan erisim ile)        \n");
        printf("      4    -->    Sonlandir                                      \n");
        printf("      5    -->    Erisim surelerini kiyasla                      \n");
        printf("*** *** ***\n");
        
        printf("Seciminizi girin: ");
        scanf("%d", &selection);
        
        switch (selection) {
            case 1:
                //dosyayÄ± append modunda hem okuma hem yazma icin acalim
                fp=fopen("students.txt","a+");
                //kullanicidn bilgi alarak dosyaya eklenecek kayiti olusturma
                printf("\n\nid:");
                scanf("%d",&s.id);
                printf("Name:");
                scanf("%s",s.name);
                printf("Score:");
                scanf("%d",&s.score);
                //kaydi dosyaya yazma
                fwrite(&s,sizeof(s),1,fp);
                fclose(fp);
                break;
            case 2:
                fp=fopen("students.txt","a+");
                printf("\nDosyadaki kacinci kaydi okumak istiyorsunuz:");
                scanf("%d",&rec);
                //gecerli bir sayi girdigini farzedelim
                fseek(fp,SEEK_SET,0); //dosyanin basini isaret ediyor
                int count=0;
                while(count!=rec-1){
                    fread(&s,sizeof(s),1,fp);
                    count++;
                }
                //rec-1 kadar kayit okundu, simdi okunacak kayit bizim ulasmak istedigimiz kayit
                fread(&s,sizeof(s),1,fp);
                printf("id:%d\nName:%s\nScore:%d\n",s.id,s.name,s.score);
                fclose(fp);
                break;
            case 3:
                fp=fopen("students.txt","a+");
                printf("\nDosyadaki kacinci kaydi okumak istiyorsunuz:");
                scanf("%d",&rec);
                //gecerli bir sayi girdigini farzedelim
                fseek(fp,(rec-1)*sizeof(s),0); //dogrudan kaydin oldugu yeri isaret ediyoruz
                fread(&s,sizeof(s),1,fp);
                printf("id:%d\nName:%s\nScore:%d\n",s.id,s.name,s.score);
                fclose(fp);
                break;
            case 4:
                return 0;
            case 5:
                f=fopen("test.txt","a+");
                clock_t begin,end;
                double duration;
                struct student test;
                test.id=10;
                strcpy(test.name,"ali");
                test.score=50;
                
                int counter=1000;
                int record=counter-1;
                printf("Test amacli %d kayit iceren test.txt adli dosya olusturuldu\n",counter);
                printf("%d. kayda erisim icin gecen sureler hesaplandi\n",record);
                while(counter--){
                    fwrite(&test,sizeof(test),1,f);
                }
                fseek(f,SEEK_SET,0);
                counter=1000;
                //sonuncu kaydi okumak istedigini varsayalim yani counter.kayit
                
                //sirali erisimle okuma
                /*******************************/
                begin=clock();
                count=0;
                while(count!=record-1){
                    fread(&test,sizeof(test),1,f);
                    count++;
                }
                //bizim ulasmak istedigimiz kayit
                fread(&test,sizeof(test),1,f);
                end=clock();
                duration=(double)(end-begin)/ CLOCKS_PER_SEC;
                printf("Sirali erisimle:%f sn\n", duration);
                /*******************************/
                
                fseek(f,SEEK_SET,0);
                //dogrudan erisimle okuma
                /*******************************/
                begin=clock();
                fseek(f,(record-1)*sizeof(test),0); //dogrudan kaydin oldugu yeri isaret ediyoruz
                fread(&test,sizeof(test),1,f);
                end=clock();
                duration=(double)(end-begin)/ CLOCKS_PER_SEC;
                printf("Dogrudan erisimle:%f sn\n", duration);
                /*******************************/
                fclose(f);
                break;
                
        }
    }
    
    return 0;
}