#include <iostream>
using namespace std;
template <class Tipo>
void troca(Tipo &itemA, Tipo &itemB){
    Tipo tmp = itemA;
    itemA =itemB;
    itemB=tmp;
}
template <class Tipo>
void shellsort(Tipo *&vetor, int tam){
    int h = 1;
    while(h<tam/3)
        h =3*h + 1;
    while(h>=1){
        for(int i=h; i<=tam-1; i++){
            int j=i;
            while(j>=h && vetor[j]<vetor[j-h]){
                troca(vetor[j], vetor[j-h]);
                j=j-h;
            }
        }
        h = h/3;
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
    shellsort(v, 11);
    print(v, 11);
    return 0;
}
