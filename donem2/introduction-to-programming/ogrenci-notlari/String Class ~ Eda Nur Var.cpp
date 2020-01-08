#include <iostream>
using namespace std;

class String {
public:
    char *text;
    String(){
        text = "noText";
    }

    String(char* p){
        text = p;
    }

    void operator = (char *p) {
         text = p;
    }

    String operator + (const String &s){
        String dondur;
        int sayac1 = 0;
        while(text[sayac1] != '\0'){
            sayac1++;
        }
        int sayac2 = 0;
        while(s.text[sayac2] != '\0'){
            sayac2++;
        }

        dondur.text = new char[sayac1 + sayac2 +1];
        for(int i = 0; i < sayac1; ++i){
            dondur.text[i] = text[i];
        }
        int index = 0;
        for(int i = sayac1; i < sayac1 + sayac2 + 1; ++i){
            dondur.text[i] = s.text[index];
            index++;
        }
        return dondur;

    }

    String operator + (char* p){
        String dondur;
        int sayac1 = 0;
        while(text[sayac1] != '\0'){
            sayac1++;
        }
        int sayac2 = 0;
        while(p[sayac2] != '\0'){
            sayac2++;
        }
        dondur.text = new char[sayac1 + sayac2 + 1];
        for(int i = 0; i < sayac1; i++){
            dondur.text[i] = text[i];
        }
        int index = 0;
        for(int i = sayac1; i < sayac1 + sayac2 + 1; ++i){
            dondur.text[i] = p[index];
            index++;
        }
        return dondur;
    }

    friend ostream &operator<<( ostream &output, const String &s ) {
        int sayac1 = 0;
        while(s.text[sayac1] != '\0'){
            sayac1++;
        }
        for(int i = 0; i < sayac1 + 1; ++i){
            output<<s.text[i];
        }
         return output;
      }
};

int main(){
    String s1, s2 = "Ahmet", s3 = "Nalbant";
    s1 = s2 + " " + s3;
    cout << s1;
    return 0;
}