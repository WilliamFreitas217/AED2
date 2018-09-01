#include <iostream>
using namespace std;
void bubleSort(int *vetor, int tam){
    for(int i= tam-1; i>=1; i--){
        for(int j=1; j<i; j++){
            if(vetor[j]>vetor[j+1]){
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}
void selectionSort(int *vetor, int tam){
    for(int i=1; i<tam-1; i++){
        int min = i;
        for(int j= i+1; j<tam; j++){
            if(vetor[j]<vetor[min]){
                min = j;
            }
        }
        int temp = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = temp;
    }
}
void insetionSort(int *vetor, int tam){
    for(int i=2; i<=tam; i++){
        int x = vetor[i];
        int j = i-1;
        vetor[0]=x;
        while(x<vetor[j]){
            vetor[j+1]= vetor[j];
            j = j-1;
        }
        vetor[j+1]=x;
    }
}
bool taOrdenado(int *vetor, int tam){
    int p = vetor[0];
    int cont = 0;
    for(int i=2; i<tam; i++){
        if(vetor[i-1]>vetor[i]){
            return false;
        }
    }
    return true;
}
void imprime(int *vetor, int tam){
    for(int i=1; i<tam; i++){
        cout<<vetor[i]<<endl;
    }
}
int main(int argc, char const *argv[]) {
    int vetor[6];
    vetor[1] = 5;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 2;
    vetor[5] = 7;
    // bubleSort(vetor, 6);
    // selectionSort(vetor, 6);
    insetionSort(vetor, 6);
    imprime(vetor, 6);
    if(taOrdenado(vetor, 6)){
        cout<<"Ta ordendado"<<endl;
    }
    else{
        cout<<"Nao ta ordendado"<<endl;
    }
    return 0;
}
