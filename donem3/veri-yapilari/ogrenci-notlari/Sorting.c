#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[],int size) {
    for (int i = 0; i < size; i++)
        printf("%d  ", a[i]);
    printf("\n");
    
}

void insertionSort(int dizi[], int size){
    int i,j;
    
    for(i=0;i<size;i++)
    {
        j = i;
        while(j>0)
        {
            //not in order
            if(dizi[j-1] > dizi[j])
            {
                //swapping
                int temp = dizi[j-1];
                dizi[j-1] = dizi[j];
                dizi[j] = temp;
            }
            //in order
            else
            {
                break;
            }
            j--;
        }
    }
}




int partition(int dizi[],int p,int q){
    int j, temp;
    int x=dizi[p];
    int i=p;
    
    for(int j=p+1;j<q;j++){
        if(dizi[j]<=x){
            i=i+1;
            temp=dizi[i];
            dizi[i]=dizi[j];
            dizi[j]=temp;}
    }
    temp=dizi[i];
    dizi[i]=dizi[p];
    dizi[p]=temp;
    return i;
}

void quicksort(int dizi[],int p,int r){
    int pivot,j,temp,i;
    
    if(p<r){
        int q= partition(dizi,p,r);
        quicksort(dizi,p,q-1);
        quicksort(dizi,q+1,r);
        
    }
}


void shell(int dizi[],int ust) {
    int h = 1;
    while ((h * 3 + 1) < ust)
        h = 3 * h + 1;
    
    
    while (h > 0) {
        for (int i = h - 1; i < ust; i++) {
            int B = dizi[i];
            int J = i;
            for (J = i; (J >= h) && (dizi[J - h] > B); J -= h)
                dizi[J] = dizi[J - h];
            dizi[J] = B;
        }
        h = (h-1)/3;
    }
}

int main() {
    int size=100;
    clock_t begin,end;
    double duration;
    
    //random bir dizi olusturma
    int dizi[size];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++)
        dizi[i]=rand()%200; // %50 ile 0-49 arasi sayilar uret demÄ±s oluyoruz
    
    //siralama algoritmalarinda uzerinde calÄ±sacagimiz diziler
    //(mevcut dizinin 3 kopyasini olusturduk)
    int d1[size];
    int d2[size];
    int d3[size];
    for (int i = 0; i < size; i++)
        d1[i]= d2[i]= d3[i]=dizi[i];
    
    printf("--- --- *** --- ---\n\n");
    printf("Siralamadan once:\n");
    printArray(dizi,size);
    
    printf("\nInsertion Sort:\n");
    begin=clock();
    insertionSort(d1,size);
    end=clock();
    printArray(d1,size);
    duration=(double)(end-begin)/ CLOCKS_PER_SEC;
    printf("Toplam sure:%f sn\n", duration);

    printf("\nShell Sort:\n");
    begin=clock();
    shell(d2,size);
    end=clock();
    duration=(double)(end-begin)/ CLOCKS_PER_SEC;
    printArray(d2,size);
    printf("Toplam sure:%f sn\n", duration);
    
    printf("\nQuick Sort:\n");
    begin=clock();
    quicksort   (d3,0,size-1);
    end=clock();
    duration=(double)(end-begin)/ CLOCKS_PER_SEC;
    printArray(d3,size);
    printf("Toplam sure:%f sn\n", duration);
    
    printf("\n--- --- *** --- ---\n\n");
    return 0;
}