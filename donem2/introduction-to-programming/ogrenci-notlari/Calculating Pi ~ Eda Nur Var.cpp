#include <iostream>
using namespace std;

//RECURSIVE FUNCTION FOR FINDING PI
float giveMePi(int k){
    int isaret;
    if((k % 2) == 0){
        isaret = 1;
    }else{
        isaret = -1;
    }
    if(k == 0){
        return (3.0 + 4 * (1.0 / 24.0));
    }else{
        return  ((4.0 * isaret) / (((2.0 * (float)k) + 2.0) * ((2.0 * (float)k) + 3.0) * ((2.0 * (float)k) + 4.0))) + giveMePi(k - 1);
    }
}

//NORMAL FUNCTION
float pi(){
    float toplam = 3.0;
    int isaret;
    for (int k = 0; k < 1000000; ++k){
        if((k % 2) == 0){
            isaret = 1;
        }else{
            isaret = -1;
        }
        toplam += ((4.0 * isaret) / (((2.0 * (float)k) + 2.0) * ((2.0 * (float)k) + 3.0) * ((2.0 * (float)k) + 4.0)));
    }
    return toplam;

}

int main(){
    cout<<"result of recursive function: "<<giveMePi(1000)<<endl;
    cout<<"result of other function: "<<pi();
}
