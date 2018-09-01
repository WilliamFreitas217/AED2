#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int val[] = {10, 100, 184, 1000, 1575, 10000, 17893};
    double A =1;
    double s =val[0]+A;
    int i=1;
    while(s>val[i-1]){
        A = A/2;
        s = val[i]+A;
        cout<<"Val1: "<<val[i]<<endl;
        i++;
    }
    // cout<<A<<endl;
    float A2 =1;
    float s2=val[0]+A2;
    i=1;
    while(s2>val[i-1]){
        A2 = A2/2;
        s2 = val[i]+A2;
        cout<<"Val2: "<<val[i]<<endl;
        i++;
    }
    // cout<<A2<<endl;
    double precisao = 2*A;
    float precisao2 = 2*A2;
    cout<<"PrecisaoD: "<<precisao<<endl;
    cout<<"PrecisaoF: "<<precisao2<<endl;
    // printf("%f", precisao);
    return 0;
}
