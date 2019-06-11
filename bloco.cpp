#include <iostream>
#include<cstdlib>
#include <iomanip>
#include <limits.h>
#include<cmath>
#define NIL -1
using namespace std;
typedef int Peso;
typedef int Vertice;
class BlocoNeuronio{
private:
    Peso **mat;
    int n;
    int m;
    int qtdNeuroniosDoentes;
    int qtdNDA;
    int *neuroniosDoentes;
public:
	BlocoNeuronio();
    BlocoNeuronio(int n, int m);
	void inicializar(int n, int m);
    void inserirVertice(Vertice u, Vertice v, Peso w);
    void setQtdNeuroniosDoentes(int qtdNeuroniosDoentes);
    int getQtdNeuroniosDoentes();
    void addNeuronioDoente(int neuronio);
    int *getNeuroniosDoentes();
    void curarNeuronio(int neuronio);
    Peso **getMat();
    void mostra();
	void setN(int n);
	void setM(int m);
	int getM();
	int getN();
    Peso w(Vertice u, Vertice v);
    bool estaDoente();
};

BlocoNeuronio::BlocoNeuronio(){
}

BlocoNeuronio::BlocoNeuronio(int n, int m){
    this->n = n;
    this->qtdNeuroniosDoentes = 0;
    mat = new Peso *[n+1];
    for(int i=0; i<=n; i++){
      mat[i] = new Peso[n+1];
    }
  	inicializar(n, m);
}


void BlocoNeuronio::inicializar(int n, int m){
    this->m = m;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
          mat[i][j]=0;
        }
    }
}

void BlocoNeuronio::setQtdNeuroniosDoentes(int qtdNeuroniosDoentes){
    this->qtdNeuroniosDoentes = qtdNeuroniosDoentes;
    neuroniosDoentes = new int[n+1];
    for(int i=1; i<=n; i++){
        neuroniosDoentes[i]=0;
    }
}

int BlocoNeuronio::getQtdNeuroniosDoentes(){
    return qtdNeuroniosDoentes;
}

int *BlocoNeuronio::getNeuroniosDoentes(){
    return neuroniosDoentes;
}

void BlocoNeuronio::addNeuronioDoente(int neuronio){
    neuroniosDoentes[neuronio]=1;
}

void BlocoNeuronio::curarNeuronio(int neuronio){
    neuroniosDoentes[neuronio]=0;
}

bool BlocoNeuronio::estaDoente(){
    if(qtdNeuroniosDoentes!=0){
        return true;
    }
    return false;
}

void BlocoNeuronio::inserirVertice(Vertice u, Vertice v, Peso w){
    mat[u][v] = w;
    mat[v][u] = w;
    // mat[v-1][u-1] = w; //deve ser desativada caso o grafo seja direcionado
}

void BlocoNeuronio::mostra(){
    int k = 3;
    cout<<" ";
    for(int j=1; j<= n; j++){
        cout<< setw(k)<<j;
    }
    cout<<endl;
    for(int j=0; j< n*k+3; j++){
        cout<<"-";
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<setw(1)<<i;
        cout<<"|";
        for(int j=1; j<=n; j++){
            cout<<setw(k)<<mat[i][j];
        }
        cout<<endl;
    }
}

Peso **BlocoNeuronio::getMat(){
	return mat;
}

void BlocoNeuronio::setN(int n){
	this->n = n;
}

void BlocoNeuronio::setM(int m){
	this->m = m;
}

int BlocoNeuronio::getN(){
	return n;
}

int BlocoNeuronio::getM(){
	return m;
}

Peso BlocoNeuronio::w(Vertice u, Vertice v){
    return mat[u][v];
}
int main(int argc, char const *argv[]) {
    int n, m;
    cin>>n>>m;
    BlocoNeuronio bloco(n, m);
    for(int i=1; i<=n; i++){
        int v1, v2;
        float w;
        cin>>v1>>v2;
        scanf("%f\n", &w);
        bloco.inserirVertice(v1, v2, w);
    }
    bloco.mostra();
    return 0;
}
