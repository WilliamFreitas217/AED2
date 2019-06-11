#include <iostream>
#include<cstdlib>
#include <iomanip>
#include <limits.h>
#include<cmath>
#include<cfloat>
#define NIL -1
using namespace std;

enum Cor {branco, cinza, preto};

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
void troca(Tipo &itemA, Tipo &itemB){
    Tipo tmp = itemA;
    itemA =itemB;
    itemB=tmp;
}

template <class Tipo>
void printarVetor(Tipo *vetor, int tam){
    for(int i=1; i<=tam; i++){
        cout<<"["<<i<<"] :: "<< vetor[i]<<endl;
    }
}
template <class Tipo>
void printar(Tipo *vetor, int tam){
    for(int i=1; i<=tam; i++){
        cout<<"["<<i<<"] :: "<< vetor[i].getVertice()<<"\t|| "<<vetor[i].getPesoAresta()<<endl;
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

template <class Tipo>
class No{
private:
	Tipo item;
	No *prox;
public:
	No();
	No(Tipo&);
	void setItem(Tipo &);
	void setProx(No<Tipo> *);
	void cria();
	Tipo &getItem();
	No<Tipo> *getProx();
};

template <class Tipo>
No<Tipo>::No(){
 	this->prox = NULL;
}

template <class Tipo>
void No<Tipo>::cria(){
	this->prox = NULL;
}

template <class Tipo>
No<Tipo>::No(Tipo &item){
	this->item = item;
	this->prox = NULL;
}

template <class Tipo>
Tipo &No<Tipo>::getItem(){
	return this->item;
}

template <class Tipo>
No<Tipo> *No<Tipo>::getProx(){
	return prox;
}

template <class Tipo>
void No<Tipo>::setItem(Tipo &item){
	this->item = item;
}

template <class Tipo>
void No<Tipo>::setProx(No<Tipo> *no){
	this->prox = no;
}

template <class Tipo>
class Lista{
private:
	No<Tipo> *prim;
	No<Tipo> *ult;
    int tam;
public:
	Lista();
	void insere(Tipo&);
	void mostra();
	void setPrim(No<Tipo> *);
	void setUlt(No<Tipo> *);
	No<Tipo> *getPrim();
	No<Tipo> *getUlt();
	void destruir();
    int getTam();
};

template <class Tipo>
void Lista<Tipo>::setPrim(No<Tipo> *prim){
	this->prim = prim;
}

template <class Tipo>
void Lista<Tipo>::setUlt(No<Tipo> *ult){
	this->ult = ult;
}

template <class Tipo>
No<Tipo> *Lista<Tipo>::getPrim(){
	return prim;
}

template <class Tipo>
No<Tipo> *Lista<Tipo>::getUlt(){
	return ult;
}

template <class Tipo>
Lista<Tipo>::Lista(){
	prim = new No<Tipo>();
	ult = prim;
    tam=0;
}

template <class Tipo>
void Lista<Tipo>::insere(Tipo &item){
	ult->setProx(new No<Tipo>());
	ult = ult->getProx();
	ult->setItem(item);
    tam++;
}

template <class Tipo>
void Lista<Tipo>::mostra(){
	No<Tipo> *p = prim->getProx();
	while(p!= NULL){
    	cout<<p->getItem().getVertice();
    	p = p->getProx();
		if(p!=NULL){
			cout<<", ";
		}
    }
}

template <class Tipo>
void Lista<Tipo>::destruir(){
	No<Tipo> *p = prim->getProx();
	while(p!=NULL){
		delete p;
		p = p->getProx();
	}
}

template <class Tipo>
int Lista<Tipo>::getTam(){
    return tam;
}

template <class Tipo>
class PilhaDinamica{
private:
	No<Tipo> *topo;
	No<Tipo> *fundo;
public:
	PilhaDinamica();
	No<Tipo> *getTopo();
	No<Tipo> *getFundo();
	void empilha(Tipo*);
	Tipo* desempilha(Tipo *);
	void Mostra();
};
template <class Tipo>
PilhaDinamica<Tipo>::PilhaDinamica(){
	topo = new No<Tipo>();
	fundo = topo;
}
template <class Tipo>
void PilhaDinamica<Tipo>::empilha(Tipo *item){
	No<Tipo> *aux = new No<Tipo>();
	topo->setItem(item);
	aux->setNo(topo);
	topo = aux;
}

template <class Tipo>
No<Tipo> *PilhaDinamica<Tipo>::getTopo(){
	return topo;
}

template <class Tipo>
No<Tipo> *PilhaDinamica<Tipo>::getFundo(){
	return fundo;
}

template <class Tipo>
void PilhaDinamica<Tipo>::Mostra(){
	No<Tipo> *p = topo->getProx();
	while(p!= NULL){
    p->getItem()->print();
    p = p->getProx();
  	}
}

template <class Tipo>
Tipo *PilhaDinamica<Tipo>::desempilha(Tipo *item){
	No<Tipo> *aux = topo;
	item = new Tipo;
	topo = topo->getProx();
	item = topo->getItem();
	delete aux;
	return item;
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
};
int FilaDePrioridade::pai(int i){
    return floor(i/2);
}

int FilaDePrioridade::esq(int i){
    return 2*i;
}

int FilaDePrioridade::dir(int i){
    return 2*i+1;
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
    int menor = 1;
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
    if(par.getPesoAresta()>vetor[i].getPesoAresta()){
        cout<<"valor inferior \n ACAO NAO PERMITIDA \n Distancia: "<< par.getPesoAresta()<<endl;
    }
    else{
        vetor[i].setVertice(par.getVertice());
        vetor[i].setPesoAresta(par.getPesoAresta());
        while (i>1 && vetor[i/2].getPesoAresta()>vetor[i].getPesoAresta()) {
            troca(vetor[i/2], vetor[i]);
            i = i/2;
        }
    }
}

void FilaDePrioridade::insere(Par par){
    tamHeap++;
    vetor[tamHeap].setVertice(INT_MAX);
    vetor[tamHeap].setPesoAresta(FLT_MAX);
    decrescerMin(tamHeap, par);
}

Par FilaDePrioridade::extrairMin(){
    Par minimo = vetor[1];
    vetor[1] = vetor[tamHeap];
    tamHeap--;
    heapficaMin(1);
    return minimo;
}


void FilaDePrioridade::mostra(){
	for(int i=1; i<tamHeap+1; i++){
        cout<<"Vertice: "<<vetor[i].getVertice()<<" Peso: "<< vetor[i].getPesoAresta()<<endl;
    }
}

bool FilaDePrioridade::verificar(int chave){
    for(int i=1; i<tamHeap+1; i++){
        if(vetor[i].getVertice()==chave){
            return true;
        }
    }
    return false;
}

int FilaDePrioridade::getTamHeap(){
    return tamHeap;
}

typedef float Peso;
typedef int Vertice;
class UnionFind{
private:
    int *S;
    int ordem;
public:
    UnionFind();
    UnionFind(int ordem);
    int findSet(int x);
    void unionThis(int x, int y);
    void mostra();
};
UnionFind::UnionFind(){
}

UnionFind::UnionFind(int ordem){
    this->ordem = ordem;
    S = new int[ordem+1];
    for(int i=1; i<=ordem; i++){
        S[i]=NIL;
        // cout<<i<<endl;
    }
}

int UnionFind::findSet(int x){
    if(S[x]==NIL){
        return x;
    }
    return findSet(S[x]);
}
void UnionFind::unionThis(int x, int y){
    int A = findSet(x);
    int B = findSet(y);
    S[A]=B;
    // if(A!=B){
    //     S[x]=y;
    // }
}
void UnionFind::mostra(){
    for(int i=1; i<=ordem; i++){
        cout<<S[i]<<endl;
    }
}


class Trio{
private:
    int vertice;
    int vAdj;
    int pesoAresta;
public:
    Trio();
    Trio(int vertice, int vAdj, int pesoAresta);
    int getVertice();
    int getVAdj();
    int getPesoAresta();
    int getChave();
    void setVertice(int vertice);
    void setVAdj(int adj);
    void setPesoAresta(int pesoAresta);
};

Trio::Trio(){
}

Trio::Trio(int vertice, int vAdj, int pesoAresta){
    this->vertice = vertice;
    this->vAdj = vAdj;
    this->pesoAresta = pesoAresta;
}

int Trio::getVertice(){
    return vertice;
}

int Trio::getVAdj(){
    return vAdj;
}

int Trio::getPesoAresta(){
    return pesoAresta;
}
int Trio::getChave(){
    return pesoAresta;
}
void Trio::setVertice(int vertice){
    this->vertice = vertice;
}

void Trio::setVAdj(int adj){
    this->vAdj = adj;
}

void Trio::setPesoAresta(int pesoAresta){
    this->pesoAresta = pesoAresta;
}

class Grafo{
private:
    Peso **mat;
    int n;
    int m;
public:
	Grafo();
    Grafo(int n, int m);
	void inicializar(int n, int m);
    void inserirVertice(Vertice u, Vertice v, Peso w);
    void ordenarADJ();
    Peso **getMat();
    void mostra();
	void setN(int n);
	void setM(int m);
	int getM();
	int getN();
    Peso w(Vertice u, Vertice v);

};

Grafo::Grafo(){
}

Grafo::Grafo(int n, int m){
    this->n = n;
    mat = new Peso *[n+1];
    for(int i=0; i<=n; i++){
      mat[i] = new Peso[n+1];
    }
  	inicializar(n, m);
}


void Grafo::inicializar(int n, int m){
    this->m = m;
    this->n = n;
    mat = new Peso *[n+1];
    for(int i=0; i<=n; i++){
      mat[i] = new Peso[n+1];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
          mat[i][j]=0;
        }
    }
}

void Grafo::inserirVertice(Vertice u, Vertice v, Peso w){
    mat[u][v] = w;
    mat[v][u] = w;
    // mat[v-1][u-1] = w; //deve ser desativada caso o grafo seja direcionado
}

void Grafo::mostra(){
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

Peso **Grafo::getMat(){
	return mat;
}

void Grafo::setN(int n){
	this->n = n;
}

void Grafo::setM(int m){
	this->m = m;
}

int Grafo::getN(){
	return n;
}

int Grafo::getM(){
	return m;
}

Peso Grafo::w(Vertice u, Vertice v){
    return mat[u][v];
}

class BlocoNeuronio{
private:
    Peso **mat;
    int n;
    int m;
    int qtdNeuroniosDoentes;
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
    this->n = n;
    this->qtdNeuroniosDoentes = 0;
    // cout<<n<< " || " <<m<<endl;
    // cout<<this->n<< " || " <<this->m<<endl;
    mat = new Peso *[this->n+1];
    for(int i=0; i<=n; i++){
        // cout<<i<<endl;
        mat[i] = new Peso[n+1];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
          mat[i][j]=0;
        }
    }
}

void BlocoNeuronio::setQtdNeuroniosDoentes(int qtdNeuroniosDoentes){
    this->qtdNeuroniosDoentes = qtdNeuroniosDoentes;
    neuroniosDoentes = new int[n+1];
    // cout<<"aquiiiii::: "<<n+1<<endl;
    for(int i=1; i<=n; i++){
        // cout<<i<<endl;
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
    // cout<<"aqui"<<endl;
    // printarVetor(neuroniosDoentes, n);
    if(neuroniosDoentes[neuronio]==1){
        qtdNeuroniosDoentes--;
    }
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

void procurarMenorComTalPesoDeAresta(Trio *vetor, int peso, int tam, int indiceAtual){
    for(int i=indiceAtual+1; i<tam; i++){
        if(peso == vetor[i].getPesoAresta()){
            if(vetor[i].getVAdj()<vetor[indiceAtual].getVAdj()){
                troca(vetor[i], vetor[indiceAtual]);
            }
        }
    }
}

bool verificar(int v1, int v2, Trio *vetor, int tam){
    for(int k=1; k<=tam; k++){
        if(vetor[k].getVertice()==v2 && vetor[k].getVAdj()==v1){
            return true;
        }
    }
    return false;
}

class Kruskal{
private:
    Lista<Trio> *A;
    float custoDoPercurso;
public:
    void mstKruskal(BlocoNeuronio &blocoDeNeuronio);
    Lista<Trio> *getA();
    float getCustoDoPercurso();
};
void Kruskal::mstKruskal(BlocoNeuronio &blocoDeNeuronio){
    A = new Lista<Trio>[blocoDeNeuronio.getM()+1];
    int tamVetorArestas = blocoDeNeuronio.getM()+1;
    Trio *arestas = new Trio[tamVetorArestas];
    for(int i = 1; i<tamVetorArestas/2; i++){
        arestas[i].setVertice(-1);
        arestas[i].setVAdj(-1);
        arestas[i].setPesoAresta(INT_MAX);
    }
    int indice = 1;
    for(int i=1; i<=blocoDeNeuronio.getN(); i++){
        for(int j=1; j<=blocoDeNeuronio.getN(); j++){
            if(blocoDeNeuronio.w(i, j)!=0 && !verificar(j, i, arestas, tamVetorArestas)){
                arestas[indice].setVertice(j);
                arestas[indice].setVAdj(i);
                arestas[indice].setPesoAresta(blocoDeNeuronio.w(i, j));
                indice++;
            }
        }
    }
    UnionFind uniao(blocoDeNeuronio.getN());
    Heap<Trio> heap;
    heap.heapSort(arestas, tamVetorArestas); //ordenar as arestas não-decrescentemente de acordo com o peso das Arestas;
    for(int i=1; i<tamVetorArestas; i++){
        // cout<<"u: "<<arestas[i].getVAdj()<<" || v: "<<arestas[i].getVertice()<<" || p: "<<arestas[i].getPesoAresta()<<endl;
        procurarMenorComTalPesoDeAresta(arestas, arestas[i].getPesoAresta(), tamVetorArestas, i);
    }
    indice = 1;
    custoDoPercurso = 0;
    for(int i=1; i<tamVetorArestas; i++){
        if(arestas[i].getVAdj() != 0 && arestas[i].getVertice()!=0){
            int u = uniao.findSet(arestas[i].getVAdj());
            int v = uniao.findSet(arestas[i].getVertice());
            if(u!=v){
                Trio aSerInserido(arestas[i].getVertice(), arestas[i].getVAdj(), arestas[i].getPesoAresta());
                A[indice].insere(aSerInserido);
                uniao.unionThis(u, v);
                // cout<<blocoDeNeuronio.getN()<<endl;
                // cout<<arestas[i].getVertice()<<endl;
                blocoDeNeuronio.curarNeuronio(arestas[i].getVertice());
                custoDoPercurso += arestas[i].getPesoAresta();
                indice++;
            }
        }
    }
}

Lista<Trio> *Kruskal::getA(){
    return A;
}

float Kruskal::getCustoDoPercurso(){
    return custoDoPercurso;
}

class Dijkstra{
private:
	Lista<Par> S;
    int *predecessores;
    int *distancias;
    int distancia;
    FilaDePrioridade Q;
public:
    Dijkstra();
    Dijkstra(Grafo g, int s);
    void inicializar(Grafo g, int s);
    void relaxa(Grafo g, int u, int v);
	Lista<Par> *getS();
    int *getPredecessores();
    int *getDistancias();
};

Dijkstra::Dijkstra(){
}

Dijkstra::Dijkstra(Grafo g, int s){
	inicializar(g, s);
	while(Q.getTamHeap()>0){
        Par u = Q.extrairMin();
        // cout<<"aqui"<<endl;
		S.insere(u);
        for(int v=1; v<=g.getN(); v++){
            if(g.w(u.getVertice(), v)!=0){
                relaxa(g, u.getVertice(), v);
            }
        }
	}
    // Par *pares = new Par[S.getTam()+1];
    // int i=1;
    // No<Par> *p = S.getPrim()->getProx();
    // while (p!=NULL) {
    //     pares[i]=p->getItem();
    //     i++;
    //     p= p->getProx();
    // }
    // quickSort(pares, 1, S.getTam());
    // printar(pares, S.getTam());
}

void Dijkstra::inicializar(Grafo g, int s){
	predecessores = new int[g.getN()+1];
	distancias = new int[g.getN()+1];
	for(int v=1; v<=g.getN(); v++){
		distancias[v] = INT_MAX;
		predecessores[v] = NIL;
	}
    Q.inicializar(g.getN());
	distancias[s]=0;
    Par par(s, distancias[s]);
    Q.insere(par);
}

void Dijkstra::relaxa(Grafo g, int u, int v){
	if(distancias[v]>distancias[u]+g.w(u, v)){
		distancias[v]=distancias[u]+g.w(u, v);
		predecessores[v]=u;
        Par par(v, distancias[v]);
        Q.insere(par);
	}
}

Lista<Par> *Dijkstra::getS(){
    return &S;
}

int *Dijkstra::getPredecessores(){
    return predecessores;
}

int *Dijkstra::getDistancias(){
    return distancias;
}

void inicializarCerebro(Grafo &g){
    for(int i=1; i<=g.getM(); i++){
        int u, v;
        float w;
        cin>>u;
        cin>>v;
        scanf("%f\n", &w);
        g.inserirVertice(u, v, w);
    }
    // cout<<"aqui"<<endl;
}

void inicializarBloco(BlocoNeuronio &bloco){
    for(int j=1; j<=bloco.getM(); j++){
        // cout<<"j: "<<j<<endl;
        int u, v;
        float w;
        cin>>u>>v;
        // cout<<u<<" || "<< v<< " || ";
        scanf("%f\n", &w);
        // printf("%1.f\n", w);
        bloco.inserirVertice(u, v, w);
    }
    // bloco.mostra();
}

void inicializarBlocosDeNeuronios(BlocoNeuronio *blocosDeNeuronios, int n){
    for(int i=1; i<=n; i++){
        int ordem, tam;
        cin>>ordem;
        cin>>tam;
        int qtdNeuroniosDoentes;
        cin>>qtdNeuroniosDoentes;
        // cout<<"ordem: "<<ordem<<"\ttam: "<< tam<< "\t\ti: "<<i<<"\tqtd Doentes: "<< qtdNeuroniosDoentes<<endl;
        blocosDeNeuronios[i].inicializar(ordem, tam);
        if(qtdNeuroniosDoentes!=0){
            blocosDeNeuronios[i].setQtdNeuroniosDoentes(qtdNeuroniosDoentes);
            for(int j=1; j<=qtdNeuroniosDoentes; j++){
                int neuronio;
                cin>>neuronio;
                // cout<<" neuronio:: "<<neuronio<<endl;
                blocosDeNeuronios[i].addNeuronioDoente(neuronio);
            }
            // printarVetor(blocosDeNeuronios[i].getNeuroniosDoentes(), ordem);
        }
        inicializarBloco(blocosDeNeuronios[i]);
    }
}

float visitarBlocoDeNeuronio(BlocoNeuronio blocoDeNeuronio){
    float valorDoCaminho = 0;
    Kruskal kruskal;
    kruskal.mstKruskal(blocoDeNeuronio);
    valorDoCaminho+=kruskal.getCustoDoPercurso();
    return valorDoCaminho;
}

void percorrerCerebro(Grafo &cerebro, BlocoNeuronio *blocosDeNeuronios, int blocoEntrada, int blocoSaida){
    Dijkstra *dijkstra;
    dijkstra = new Dijkstra(cerebro, blocoEntrada);
    int *vetorDePercurso = dijkstra->getPredecessores();
    printarVetor(vetorDePercurso, cerebro.getN());
    float custoTotal = 0;
    if(blocosDeNeuronios[blocoSaida].estaDoente())
        custoTotal += visitarBlocoDeNeuronio(blocosDeNeuronios[blocoSaida]);
    // cout<<"aqui"<<endl;
    int verificador = blocoSaida, i = vetorDePercurso[blocoSaida];
    while(verificador!=blocoEntrada){
        if(i==-1){
            break;
        }
        if(blocosDeNeuronios[i].estaDoente()){
            // cout<<"indice::: "<<i<<endl;
            custoTotal += visitarBlocoDeNeuronio(blocosDeNeuronios[i]);
        }
        verificador = i;
        i = vetorDePercurso[i];
    }
    cout<<custoTotal<<endl;

}

int main(int argc, char const *argv[]) {
    int N, M;
    cin>>N>>M;
    Grafo cerebro(N, M);
    inicializarCerebro(cerebro);
    // cerebro.mostra();
    BlocoNeuronio *blocosDeNeuronios = new BlocoNeuronio[N+1];
    int blocoEntrada, blocoSaida;
    cin>>blocoEntrada>>blocoSaida;
    inicializarBlocosDeNeuronios(blocosDeNeuronios, N);
    // cout<<"blocoEntrada:: "<< blocoEntrada<<"\tblocoSaida :"<<blocoSaida<<endl;
    percorrerCerebro(cerebro, blocosDeNeuronios, blocoEntrada, blocoSaida);
    return 0;
}
