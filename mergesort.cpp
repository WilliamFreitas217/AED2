#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;
template <class Tipo>
void print(Tipo *vetor, int tam){
    for(int i=1; i<tam; i++){
        cout<<vetor[i]<<endl;
    }
}
template <class Tipo>
void merge(Tipo *&vetorA, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    Tipo vetorL[n1+2], vetorR[n2+2];
    for(int i=1; i<=n1; i++){
        vetorL[i]=vetorA[p+i-1];
    }
    for(int j=1; j<=n2; j++){
        vetorR[j]=vetorA[q+j];
    }
    vetorL[n1+1]=INT_MAX;
    vetorR[n2+1]=INT_MAX;
    // print(vetorL, n1+2);
    // print(vetorR, n2+2);
    int i = 1;
    int j = 1;
    for(int k=p; k<=r; k++){
        if(vetorL[i]<=vetorR[j]){
            vetorA[k] = vetorL[i];
            i++;
        }
        else{
            vetorA[k] = vetorR[j];
            j++;
        }
    }
}
template <class Tipo>
void mergeSort(Tipo *&vetor, int p, int r){
    if(p<r){
        int q = floor((p+r)/2);
        mergeSort(vetor, p, q);
        mergeSort(vetor, q+1, r);
        merge(vetor, p, q, r);
    }
}
int main(int argc, char const *argv[]) {
    int *v = new int[6];
    const int NIL = -1;
    v[0] = NIL;
    v[1]=5;
    v[2]=4;
    v[3]=3;
    v[4]=2;
    v[5]=1;
    // merge(v, 1, 3, 6);
    mergeSort(v, 1, 6);
    print(v, 6);
    return 0;
}
