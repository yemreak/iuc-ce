#include <iostream>
#include <cmath>

using namespace std;

double faktoriyel(double n){
    double sonuc = 1;
    for(int i = 1; i <= n; i++){
        sonuc *= (double)i;
    }
    return sonuc;
}

 float taylorSin(float aci){
    float toplam = 0;
    int sayac = 1;
    int isaret;
    float yeni = 0.1;
    int us;
    while(0.000001 < abs(yeni)){
        if((sayac % 2) == 0){
            isaret = -1;
        }else{
            isaret = 1;
        }
        us = (2 * sayac) - 1;
        yeni = (isaret * pow(aci , us)) / (float)faktoriyel(us);
        toplam += yeni;
        sayac++;
    }
    return toplam;

}

int main(){
    cout<<"sin: "<<taylorSin(0.5);
    return 0;
}
