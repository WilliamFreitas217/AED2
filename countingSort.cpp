#include <iostream>
using namespace std;
template <class Tipo>
void countingSort(Tipo *&vetorA, Tipo *&vetorB, int k, int tam){
    Tipo vetorC[k+1];
    for(int i=0; i<=k; i++){
        vetorC[i]=0;
    }
    for(int j=1; j<tam; j++){
        vetorC[vetorA[j]]=vetorC[vetorA[j]]+1;
    }
    for(int i=1; i<=k; i++){
        vetorC[i]=vetorC[i]+vetorC[i-1];
    }
    for(int j=tam-1; j>=1; j--){
        vetorB[vetorC[vetorA[j]]]=vetorA[j];
        vetorC[vetorA[j]]=vetorC[vetorA[j]]-1;
    }
}
template <class Tipo>
void print(Tipo *vetor, int tam){
    for(int i=1; i<tam; i++){
        cout<<vetor[i]<<endl;
    }
}
int main(int argc, char const *argv[]) {
    int *v = new int[11];
    const int NIL = -1;
    int *v2 = new int[11];
    v[0] = NIL;
    v[1]=4;
    v[2]=1;
    v[3]=3;
    v[4]=2;
    v[5]=8;
    v[6]=14;
    v[7]=16;
    v[8]=7;
    v[9]=9;
    v[10]=10;
    countingSort(v, v2, 16, 11);
    print(v2, 11);
    return 0;
}
