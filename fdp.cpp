#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cmath>
#include <cfloat>
#define NIL -1
using namespace std;
template <class Tipo>
void troca(Tipo &itemA, Tipo &itemB){
    Tipo tmp = itemA;
    itemA =itemB;
    itemB=tmp;
}

template <class Tipo>
void printarVetor(Tipo *vetor, int tam){
    for(int i=1; i<=tam; i++){
        cout<<"["<<i<<"] :: "<< vetor[i].getVertice()<<"\t|| "<<vetor[i].getPesoAresta()<<endl;
    }
}
template <class Tipo>
int particao(Tipo *vetor, int p, int r){
  Tipo x = vetor[p];
  Tipo temp = vetor[r+1];
  vetor[r+1]=x;
  int i = p;
  int j = r+1;
  while(true){
    do{
      i++;
    }while(vetor[i].getPesoAresta()<x.getPesoAresta());
    do{
      j--;
    }while(vetor[j].getPesoAresta()>x.getPesoAresta());
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
class Heap{
private:
    int pai(int i);
    int esq(int i);
    int dir(int i);
public:
    void heapfica(Tipo *&vetor, int i, int tamHeap);
    void constroiHeap(Tipo*&vetor, int &tamHeap, int tam);
    void heapSort(Tipo *&vetor, int tam);
    void print(Tipo *vetor, int tam);
};

template <class Tipo>
int Heap<Tipo>::pai(int i){
    return floor(i/2);
}

template <class Tipo>
int Heap<Tipo>::esq(int i){
    return 2*i;
}

template <class Tipo>
int Heap<Tipo>::dir(int i){
    return 2*i+1;
}

template <class Tipo>
void Heap<Tipo>::heapfica(Tipo *&vetor, int i, int tamHeap){
    int l = esq(i), r =dir(i);
    int maior = 1;
    if(l<=tamHeap && vetor[l].getChave()>vetor[i].getChave()){
        maior =l;
    }
    else{
        maior = i;
    }
    if(r<=tamHeap && vetor[r].getChave()>vetor[maior].getChave()){
        maior = r;
    }
    if(maior != i){
        troca(vetor[i], vetor[maior]);
        heapfica(vetor,maior, tamHeap);
    }
}
template <class Tipo>
void Heap<Tipo>::constroiHeap(Tipo*&vetor, int &tamHeap, int tam){
    tamHeap = tam-1;
    for(int i = floor(tamHeap/2); i>=1; i--){
        heapfica(vetor,i, tamHeap);
    }
}
template <class Tipo>
void Heap<Tipo>::heapSort(Tipo *&vetor, int tam){
    int tamHeap = 0;
    constroiHeap(vetor, tamHeap, tam);
    for(int i = tam-1; i>=2; i--){
        troca(vetor[1], vetor[i]);
        tamHeap--;
        heapfica(vetor, 1, tamHeap);
    }
}
template <class Tipo>
void Heap<Tipo>::print(Tipo *vetor, int tam){
    for(int i=1; i<tam; i++){
        cout<<vetor[i]<<endl;
    }
}

class Par{
private:
    int vertice;
    float pesoAresta;
public:
    Par();
    Par(int vertice, float pesoAresta);
    int getVertice();
    int getChave();
    float getPesoAresta();
    void setVertice(int vertice);
    void setPesoAresta(float pesoAresta);
};

Par::Par(){
}

Par::Par(int vertice, float pesoAresta){
    this->vertice = vertice;
    this->pesoAresta = pesoAresta;
}

int Par::getVertice(){
    return vertice;
}
int Par::getChave(){
    return vertice;
}
float Par::getPesoAresta(){
    return pesoAresta;
}

void Par::setVertice(int vertice){
    this->vertice = vertice;
}

void Par::setPesoAresta(float pesoAresta){
    this->pesoAresta = pesoAresta;
}

class FilaDePrioridade{
private:
    int tamHeap;
    Par *vetor;
    int pai(int i);
    int esq(int i);
    int dir(int i);
public:
    FilaDePrioridade();
    FilaDePrioridade(int tam);
    void inicializar(int tam);
    void heapficaMin(int i);
    Par minimo();
    void decrescerMin(int i, Par par);
    void insere(Par par);
    void atualizar(Par par);
    Par extrairMin();
    int getTamHeap();
    bool verificar(int chave);
	void mostra();
    void atualizar(int chave, float w);
    void deletar(int i);
};
int FilaDePrioridade::pai(int i){
    return floor((i)/2);
}

int FilaDePrioridade::esq(int i){
    return (2*i);
}

int FilaDePrioridade::dir(int i){
    return (2*i+1);
}


FilaDePrioridade::FilaDePrioridade(){
}

FilaDePrioridade::FilaDePrioridade(int tam){
    inicializar(tam);
}

void FilaDePrioridade::inicializar(int tam){
    this->tamHeap = 0;
    vetor = new Par[tam+1];
}

void FilaDePrioridade::heapficaMin(int i){
    int l = esq(i), r =dir(i);
    int menor=i;
    if(l<=tamHeap && vetor[l].getPesoAresta()<vetor[i].getPesoAresta()){
        menor =l;
    }
    else{
        menor = i;
    }
    if(r<=tamHeap && vetor[r].getPesoAresta()<vetor[menor].getPesoAresta()){
        menor = r;
    }
    if(menor != i){
        troca(vetor[i], vetor[menor]);
        heapficaMin(menor);
    }
}

Par FilaDePrioridade::minimo(){
    return vetor[1];
}

void FilaDePrioridade::decrescerMin(int i, Par par){
    vetor[i].setVertice(par.getVertice());
    vetor[i].setPesoAresta(par.getPesoAresta());
    quickSort(vetor, 1,tamHeap);
}

void FilaDePrioridade::insere(Par par){
    tamHeap++;
    vetor[tamHeap].setVertice(par.getVertice());
    vetor[tamHeap].setPesoAresta(par.getPesoAresta());
    quickSort(vetor, 1,tamHeap);
    // printarVetor(vetor, tamHeap);
    // cout<<"================================="<<endl;
}

Par FilaDePrioridade::extrairMin(){
    if(tamHeap==1){
        tamHeap--;
        return vetor[1];
    }
    Par minimo = vetor[1];
    vetor[1] = vetor[tamHeap];
    tamHeap--;
    heapficaMin(1);
    return minimo;
}

void FilaDePrioridade::deletar(int i){
    Par par(0, INT_MIN);
    decrescerMin(i, par);
    extrairMin();
}

void FilaDePrioridade::mostra(){
	for(int i=1; i<=tamHeap; i++){
        cout<<"\tVertice: "<<vetor[i].getVertice()<<"\tPeso: "<< vetor[i].getPesoAresta()<<endl;
    }
}

int FilaDePrioridade::getTamHeap(){
    return tamHeap;
}
void FilaDePrioridade::atualizar(int chave, float w){
    for(int i=1; i<=tamHeap; i++){
        if(vetor[i].getVertice()==chave){
            vetor[i].setPesoAresta(w);
        }
    }
    quickSort(vetor, 1,tamHeap);
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin>>n>>m;
    FilaDePrioridade Q(n);
    for(int i=1; i<=n; i++){
        Par par(i, INT_MAX);
        Q.insere(par);
    }
    Q.atualizar(5, 0);
    Q.atualizar(2, 0.5);
    Q.extrairMin();
    // Par *vetor = new Par[m+1];
    // for(int i=1; i<=m; i++){
    //     int u, v;
    //     float w;
    //     cin>>u>>v;
    //     scanf("%f\n", &w);
    //     vetor[i].setVertice(v);
    //     vetor[i].setPesoAresta(w);
    //     Q.insere(vetor[i]);
    // }
    // Q.extrairMin();
    Q.mostra();
    return 0;
}
