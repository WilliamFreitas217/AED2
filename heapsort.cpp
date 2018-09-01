#include <iostream>
#include<cmath>
using namespace std;
template <class Tipo>
void troca(Tipo &itemA, Tipo &itemB){
    Tipo tmp = itemA;
    itemA =itemB;
    itemB=tmp;
}

int pai(int i){
    return floor(i/2);
}
int esq(int i){
    return 2*i;
}
int dir(int i){
    return 2*i+1;
}
template <class Tipo>
void heapfica(Tipo *&vetor, int i, int tamHeap){
    int l = esq(i), r =dir(i);
    int maior = 1;
    if(l<=tamHeap && vetor[l]>vetor[i]){
        maior =l;
    }
    else{
        maior = i;
    }
    if(r<=tamHeap && vetor[r]>vetor[maior]){
        maior = r;
    }
    if(maior != i){
        troca(vetor[i], vetor[maior]);
        heapfica(vetor,maior, tamHeap);
    }
}
template <class Tipo>
void constroiHeap(Tipo*&vetor, int &tamHeap, int tam){
    tamHeap = tam-1;
    for(int i = floor(tamHeap/2); i>=1; i--){
        heapfica(vetor,i, tamHeap);
    }
}
template <class Tipo>
void heapSort(Tipo *&vetor, int tam){
    int tamHeap = 0;
    constroiHeap(vetor, tamHeap, tam);
    for(int i = tam-1; i>=2; i--){
        troca(vetor[1], vetor[i]);
        tamHeap--;
        heapfica(vetor, 1, tamHeap);
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
    heapSort(v, 11);
    print(v, 11);
    return 0;
}
