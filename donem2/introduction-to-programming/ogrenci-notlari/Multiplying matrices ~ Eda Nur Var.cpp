#include <iostream>
using namespace std;

void matrisOlustur(int matris[][10], int kacinciMatris);
void matrisCarp(int matris1[][10], int matris2[][10], int matrisCarpimi[][10]);
void yazdir(int matrisCarpimi[][10]);

int main(void){
    int matris1[10][10];
    int matris2[10][10];
    int matrisCarpimi[10][10];

    matrisOlustur(matris1, 1);
    matrisOlustur(matris2, 2);
    matrisCarp(matris1, matris2, matrisCarpimi);
    yazdir(matrisCarpimi);
    system("PAUSE");
    return 0;
}


void matrisOlustur(int matris[][10], int kacinciMatris){
int i;
int j;
cout<<kacinciMatris<<". matrisin elemanlarini giriniz."<<endl;
for(i = 0; i < 10; ++i){
    for(j = 0; j < 10; ++j){
        cout<<i + 1<<". satirin "<<j + 1<<". sutunundaki elemani giriniz."<<endl;
        cin>>matris[i][j];
    }
}

}

void matrisCarp(int matris1[][10], int matris2[][10], int matrisCarpimi[][10]){
int i;
int j;
int k;
for(i = 0; i < 10; ++i){
    for(j = 0; j < 10; ++j){
        for(k = 0; k < 10; ++k){
            matrisCarpimi[i][j] += matris1[i][k] * matris2[k][j];
        }
    }
}
}

void yazdir(int matrisCarpimi[][10]){
int i;
int j;
for(i = 0; i < 10; ++i){
    for(j = 0; j < 10; ++j){
        cout<<matrisCarpimi[i][j]<<" ";
    }
    cout<<endl;
}
}
