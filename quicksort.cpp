#include <iostream>
using namespace std;
template <class Tipo>
int particao(Tipo *vetor, int p, int r){
  Tipo x = vetor[p];
  int temp = vetor[r+1];
  vetor[r+1]=x;
  int i = p;
  int j = r+1;
  while(true){
    do{
      i++;
    }while(vetor[i]<x);
    do{
      j--;
    }while(vetor[j]>x);
    if(i<j){
      Tipo aux= vetor[j];
      vetor[j] = vetor[i];
      vetor[i] = aux;
    }
    else{
      Tipo aux= vetor[j];
      vetor[j] = vetor[p];
      vetor[p] = aux;
      vetor[r+1] = temp;
      break;
    }
  }
  return j;
}
template <class Tipo>
void quickSort(Tipo *vetor, int p, int r){
  if(p<r){
    int q = particao(vetor, p, r);
    quickSort(vetor,p, q-1);
    quickSort(vetor, q+1, r);
  }
}
template <class Tipo>
void imprime(Tipo *vetor, int tam){
  for(int i = 0; i<tam-1; i++){
    cout<<vetor[i]<<endl;
  }
}
int main(int argc, char const *argv[]) {
  int vetor[100];
  int size = 100;
  for(int i=0; i<size; i++){
      int item = 0;
      cin>> item;
      vetor[i] =item;

  }
  quickSort(vetor, 0, size);
  imprime(vetor, size);
  return 0;
}
