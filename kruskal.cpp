#include <iostream>
#include<cstdlib>
#include <iomanip>
#include <limits.h>
#include<cmath>
#define NIL -1
using namespace std;
enum Cor {branco, cinza, preto};

template <class Tipo>
void troca(Tipo &itemA, Tipo &itemB){
    Tipo tmp = itemA;
    itemA =itemB;
    itemB=tmp;
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
    return floor(i);
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
    for(int i = floor(tamHeap); i>=1; i--){
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

class Item{
private:
    string nome;
public:
    Item();
    Item(string nome);
    string getNome();
    void setNome(string nome);
};

Item::Item(){
}

Item::Item(string nome){
    this->nome = nome;
}

string Item::getNome(){
    return nome;
}

void Item::setNome(string nome){
    this->nome = nome;
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
	void Remove(No<Tipo>*);
	No<Tipo> *Busca(Tipo);
	void mostra();
	No<Tipo>* PredecessorDe(No<Tipo>*);
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
    	// cout<<" v: "<<p->getItem().getVertice()<< " || peso: "<<p->getItem().getPesoAresta();
        cout<<p->getItem().getVertice();
    	p = p->getProx();
		if(p!=NULL){
			cout<<", ";
		}
    }
}

template <class Tipo>
No<Tipo> *Lista<Tipo>::PredecessorDe(No<Tipo> *r){
	No<Tipo> *p = prim;
	while(p->getProx()->getItem() != r->getItem()){
    	p = p->getProx();
	}
  return p;
}

template <class Tipo>
void Lista<Tipo>::Remove(No<Tipo> *r){
	if((r==prim)||(r==NULL)){
    	cout<<"vazia"<< endl;
  }
	else{
  	No<Tipo> *p = PredecessorDe(r);
  	p->setProx(Busca(r->getItem())->getProx());
  	if(p==NULL){
    		ult = p;
  	}
	if((p ==prim)&&(p->getProx()==ult)){
		ult=prim;
	}
  	delete r;
	}
}

template <class Tipo>
No<Tipo> *Lista<Tipo>::Busca(Tipo objeto){
	No<Tipo> *p = prim->getProx();
	while((p->getItem() != objeto)&&(p!=NULL)){
    	p = p->getProx();
  	}
  	return p;
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

typedef int Peso;
typedef int Vertice;
class Par{
private:
    Vertice vertice;
    Peso pesoAresta;
public:
    Par();
    Par(Vertice vertice, Peso pesoAresta);
    Vertice getVertice();
    Vertice getChave();
    Peso getPesoAresta();
    void setVertice(Vertice vertice);
    void setPesoAresta(Peso pesoAresta);
};

Par::Par(){
}

Par::Par(Vertice vertice, Peso pesoAresta){
    this->vertice = vertice;
    this->pesoAresta = pesoAresta;
}

Vertice Par::getVertice(){
    return vertice;
}
Vertice Par::getChave(){
    return vertice;
}
Peso Par::getPesoAresta(){
    return pesoAresta;
}

void Par::setVertice(Vertice vertice){
    this->vertice = vertice;
}

void Par::setPesoAresta(Peso pesoAresta){
    this->pesoAresta = pesoAresta;
}

typedef int Peso;
typedef int Vertice;
class Grafo{
private:
    Lista<Par> *adj;
    int n;
    int m;
    void destruir();
public:
	Grafo();
    Grafo(int n, int m);
	void inicializar(int n, int m);
    void inserirVertice(Vertice u, Vertice v, Peso w);
    void ordenarADJ();
    Lista<Par> *getAdj();
    void mostra();
	void setN(int n);
	void setM(int m);
	int getM();
	int getN();
    int w(Vertice u, Vertice v);

};

Grafo::Grafo(){
}

Grafo::Grafo(int n, int m){
    this->n = 0;
    this->m = 0;
	inicializar(n, m);
}


void Grafo::inicializar(int n, int m){
	if(this->n != 0){
		destruir();
	}
	this->n = n;
    this->m = m;
	adj = new Lista<Par>[n+1];
}

void Grafo::inserirVertice(Vertice u, Vertice v, Peso w){
    Par x(v, w);
	adj[u].insere(x);
	x.setVertice(u);
    x.setPesoAresta(w);
	adj[v].insere(x);
}

void Grafo::mostra(){
    cout<<" Listas de Adjacências \t"<<endl;
	for(int i=1; i<=n; i++){
		cout<<"v["<<i<<"] = {";
		adj[i].mostra();
		cout<<"}"<<endl;
	}
}

void Grafo::destruir(){
	for(int i=0; i<=n; i++){
		adj[i].destruir();
	}
	delete[] adj;
	n=m=0;
}

Lista<Par> *Grafo::getAdj(){
	return adj;
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

int Grafo::w(Vertice u, Vertice v){
    for(int i=1; i<=n; i++){
        if(i==u){
            No<Par> *p = adj[i].getPrim()->getProx();
            while(p!=NULL){
                if(p->getItem().getVertice()==v){
                    return p->getItem().getPesoAresta();
                }
                p = p->getProx();
            }
        }
    }
    return INT_MAX;
}

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
    // int setChave(int chave);
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
    // this->chave = pesoAresta;
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
public:
    void mstKruskal(Grafo &g);
    Lista<Trio> *getA();
};
void Kruskal::mstKruskal(Grafo &g){
    A = new Lista<Trio>[g.getM()+1];
    int tamVetorArestas = g.getM()+1;
    Trio *arestas = new Trio[tamVetorArestas];
    for(int i = 1; i<tamVetorArestas; i++){
        arestas[i].setVertice(-1);
        arestas[i].setVAdj(-1);
        arestas[i].setPesoAresta(INT_MAX);
    }
    int indice = 1;
    for(int i=1; i<=g.getN(); i++){
        No<Par> *p = g.getAdj()[i].getPrim()->getProx();
        while(p!=NULL){
            if(!verificar(p->getItem().getVertice(), i, arestas, tamVetorArestas)){
                arestas[indice].setVertice(p->getItem().getVertice());
                arestas[indice].setVAdj(i);
                arestas[indice].setPesoAresta(p->getItem().getPesoAresta());
                // arestas[indice].setChave(p->getItem().getPesoAresta());
                indice++;
            }
            p = p->getProx();
        }
    }
    UnionFind uniao(g.getN());
    Heap<Trio> heap;
    heap.heapSort(arestas, tamVetorArestas); //ordenar as arestas não-decrescentemente de acordo com o peso das Arestas;
    for(int i=1; i<tamVetorArestas; i++){
        procurarMenorComTalPesoDeAresta(arestas, arestas[i].getPesoAresta(), tamVetorArestas, i);
        // cout<<"u: "<<arestas[i].getVAdj()<<" || v: "<<arestas[i].getVertice()<<" || p: "<<arestas[i].getPesoAresta()<<endl;
    }
    indice = 1;
    for(int i=1; i<tamVetorArestas; i++){
        cout<<"u: "<<arestas[i].getVAdj()<<" || v: "<<arestas[i].getVertice()<<" || p: "<<arestas[i].getPesoAresta()<<endl;
        int u = uniao.findSet(arestas[i].getVAdj());
        int v = uniao.findSet(arestas[i].getVertice());
        if(u!=v){
            Trio aSerInserido(arestas[i].getVertice(), arestas[i].getVAdj(), arestas[i].getPesoAresta());
            A[indice].insere(aSerInserido);
            // cout<<"u111====> "<<u<<" ||v111====> "<<v<<endl;
            uniao.unionThis(u, v);
            indice++;
        }
    }
    cout<<"-------------------------------------------"<<endl;
    cout<<"Árvore minima geradora"<<endl;
    for(int i=1; i<=g.getN(); i++){
        No<Trio> *p = A[i].getPrim()->getProx();
        while (p!=NULL) {
            cout<<"u: "<<p->getItem().getVAdj()<<" || v: "<<p->getItem().getVertice()<<" || p: "<<p->getItem().getPesoAresta()<<endl;
            p=p->getProx();
        }
    }
}

Lista<Trio> *Kruskal::getA(){
    return A;
}

void testaGrafo(Grafo &g){
    Kruskal kruskal;
    for(int i=1; i<=g.getM(); i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.inserirVertice(u, v, w);
    }
    g.mostra();
    kruskal.mstKruskal(g);
}
int main(){
    int n, m;
	n=8;
    m=18;
	Grafo g(n, m);
	testaGrafo(g);
    return 0;
}
