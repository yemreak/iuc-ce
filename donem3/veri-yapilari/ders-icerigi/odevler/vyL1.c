#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define kapasite 100


int stack[kapasite - 1];//stack veri yapisinin tutulacagi dizi
int soneleman = -1;//son eklenen eleman soneleman degiskeninde tutulacak

bool DoluMu() //yiginin dolu olup olmadigini kontrol eden fonksiyon
{
    if(soneleman >= kapasite - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BosMu()//yiginin bos olup olmadigini kontrol eden fonksiyon
{
    if(soneleman < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int veri)//yigina eleman ekleyen fonksiyon
{
    bool kontrol = DoluMu();
    if(kontrol == false)
    {
        soneleman = soneleman + 1;
        stack[soneleman] = veri;
    }
    else
    {
        printf("\nYiginda yer yok ");
    }
}
void pop()//yigindan eleman cikaran fonksiyon
{
    bool kontrol = BosMu();
    if(kontrol == false)
    {
        soneleman = soneleman - 1;
    }
    else
    {
        printf("\nStack bos");
    }
}


void yazdir()//listeleme fonksiyonu
{
    int i;
    printf("\n Stack Listesi\n");
    for( i = 0; i < soneleman + 1; i++)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    int secim, veri;
    while(1 == 1)
    {
        printf("\n 1- Eleman ekle");
        printf("\n 2- Eleman cikar");
        printf("\n 3- Eleman listele ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
                printf("\n Eklemek istediginiz sayiyi giriniz ");
                scanf("%d", &veri);
                push(veri);
                break;
            case 2:
                pop();
                break;
            case 3:
               yazdir();
                break;
        }
    }
}

