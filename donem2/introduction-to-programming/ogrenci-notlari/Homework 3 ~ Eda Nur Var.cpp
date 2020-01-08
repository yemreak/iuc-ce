#include <iostream>

 using namespace std;

 int main(){
    char kelimeDizisi[5][10];
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 10; ++j){
            kelimeDizisi[i][j] = 'a';
        }
    }
    for(int i = 0; i < 5; ++i){
        cout<<i + 1<<". kelimeyi giriniz"<<endl;
        cin>>kelimeDizisi[i];
    }
    char arananKelime[10];
    for(int i = 0; i < 10; ++i){
        arananKelime[i] = 'a';
    }
    cout<<"Dizide aramak istediginiz kelimeyi giriniz"<<endl;
    cin>>arananKelime;
    int sayac;
    for(int i = 0; i < 5; ++i){
        sayac = 0;
        for(int j = 0; j < 10; ++j){
          if(arananKelime[j] == kelimeDizisi[i][j]){
            sayac++;
          }else{
            break;
          }
        }
        if (sayac == 10){
            cout<<"Aradiginiz kelime dizide bulunuyor."<<endl;
            break;
        }
    }
    if(sayac != 10){
        cout<<"Aradiginiz kelime dizide bulunmuyor."<<endl;
    }

    system("pause");
    return 0;
 }