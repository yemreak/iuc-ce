
#include <stdio.h>
#include <conio.h>
#include <sys/time.h>
#include <time.h>
void InsertionSort(int dizi[],int diziboyu){

for(int i=1;i<=diziboyu;i++){
    for(int j=i;j>0;j--){
        if (dizi[j]<dizi[j-1]){
            yerdegis(&dizi[j],&dizi[j-1]);
}
    }
        }
            }

void StraightInsertionSort (int dizi[],int diziboyu){
for(int i=1;i<diziboyu;i++){
    int T=dizi[i];
    int j=i;
    while(j>0 && dizi[j-1]>T){
        dizi[j]=dizi[j-1];
        j--;
    }
    dizi[j]=T;
}
}

void BinaryInsertionSort(int dizi[], int diziboyu){
for(int i=1;i<diziboyu;i++){
    int x=dizi[i];
    int alt=0;
    int ust=i-1;
    while(alt<=ust){
        int pivot=(alt+ust)/2;
        if(x<dizi[pivot])
            ust=pivot-1;
        else
            ust=pivot-1;
    }
    for(int j=i-1;j>=alt;--j){
        dizi[j+1]=dizi[j];
        dizi[alt]=x;
    }
}
}

void SelectionSort(int dizi[],int diziboyu){
for(int i=0;i<diziboyu;i++){
    int min=i;
    for(int j=i+1;j<diziboyu;j++){
        if(dizi[j]<dizi[min])
            min=j;
        yerdegis(&dizi[min],&dizi[i]);
    }
}
}

void BubbleSort(int dizi[],int diziboyu){
 for(int i=diziboyu;i>1;i--){
    for(int j=0;j<i;j++){
        if(dizi[j]>dizi[j+1])
            yerdegis(&dizi[j],&dizi[j+1]);
    }
 }
}

void yerdegis(int *birincideger , int *ikincideger){

int gecici=*birincideger;
*birincideger=*ikincideger;
*ikincideger=gecici;

}

void yazdir(int dizi[],int diziboyu){
for(int i=0;i<=diziboyu;i++){
    printf("%d ",dizi[i]);
}
}

float gecensure(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000000.0f + (t1.tv_usec - t0.tv_usec) / 1000000.0f;
}

int main(){

 int dizi[1000];
 int diziboyu = sizeof(dizi) / sizeof(dizi[0]);
 for(int i=0;i<=1000;i++){
    dizi[i]=rand()%500;
 }
    struct timeval t0,t1,t2,t3,t4,t5;
    float sure1,sure2,sure3,sure4,sure5;

    gettimeofday(&t0, 0);
    InsertionSort(dizi, diziboyu);
    yazdir(dizi, diziboyu);
    gettimeofday(&t1, 0);
    sure1 = gecensure(t0, t1);
    //printf("\nInsertion Sort icin gecen sure %f saniye.\n", sure1);

    gettimeofday(&t1, 0);
    StraightInsertionSort(dizi, diziboyu);
    yazdir(dizi, diziboyu);
    gettimeofday(&t2, 0);
    sure2 = gecensure(t1, t2);
    //printf("\nStraight Insertion Sort icin gecen sure %f saniye.\n",sure2);

    gettimeofday(&t2, 0);
    BinaryInsertionSort(dizi, diziboyu);
    yazdir(dizi, diziboyu);
    gettimeofday(&t3, 0);
    sure3 = gecensure(t2, t3);
    //printf("\nBinary Insertion Sort icin gecen sure %f saniye.\n",sure3);

    gettimeofday(&t3, 0);
    SelectionSort(dizi, diziboyu);
    yazdir(dizi, diziboyu);
    gettimeofday(&t4, 0);
    sure4 = gecensure(t3, t4);
    //printf("\n Selection Sort icin gecen sure %f saniye.\n",sure4);

    gettimeofday(&t4, 0);
    BubbleSort(dizi, diziboyu);
    yazdir(dizi, diziboyu);
    gettimeofday(&t5, 0);
    sure5 = gecensure(t3, t4);
    //printf("\n Bubble Sort icin gecen sure %f saniye.\n",sure5);

   printf("\n");
   printf("\nInsertion Sort icin gecen sure %f saniye.\n", sure1);
   printf("\nStraight Insertion Sort icin gecen sure %f saniye.\n",sure2);
   printf("\nBinary Insertion Sort icin gecen sure %f saniye.\n",sure3);
   printf("\nSelection Sort icin gecen sure %f saniye.\n",sure4);
   printf("\nBubble Sort icin gecen sure %f saniye.\n",sure5);
}
