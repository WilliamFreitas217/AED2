#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[]) {
    double A =1;
    double s =2;
    while(s>1){
        A = A/2;
        s = 1+A;
    }
    float A2 =1;
    float s2 =2;
    while(s2>1){
        A2 = A2/2;
        s2 = 1+A2;
    }
    double precisao = 2*A;
    float precisao2 = 2*A2;
    cout<<"PrecisaoD: "<<precisao<<endl;
    cout<<"PrecisaoF: "<<precisao2<<endl;
    // printf("%f", precisao);
    return 0;
}
