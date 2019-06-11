#include <iostream>
#include <limits.h>
#define NIL -1
using namespace std;
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
    void inserirVertice(int u, int v, float w);
    Lista<Par> *getAdj();
    void mostra();
	void setN(int n);
	void setM(int m);
	int getM();
	int getN();
    float w(int u, int v);

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

void Grafo::inserirVertice(int u, int v, float w){
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

float Grafo::w(int u, int v){
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
    return 0;
}

class Dijkstra{
private:
	Lista<Trio> *S;
    int *predecessores;
    int *distancias;
    int distancia;
public:
    Dijkstra();
    Dijkstra(Grafo g, int s);
    void inicializar(Grafo g, int s);
    void relaxa(Grafo g, int u, int v);
    int *getPredecessores();
    int *getDistancias();
};

Dijkstra(){
}

Dijkstra(Grafo g, int s){
	inicializar(g, s);
	FilaDePrioridade Q(g.getN());
    for(int i=1; i<=g.getN(); i++){
        Q.insere(i);
    }
	while(Q.getTamHeap()>0){
        int u = Q.extrairMin();
        Lista<Par> vetor = g.getAdj()[u];
        No<Par> *v = vetor.getPrim()->getProx();
	}
}

void Dijkstra::inicializar(Grafo g, int s){
	predecessores = new int[g.getN()+1];
	distancias = new int[g.getN()+1];
	for(int v=1; v<=g.getN(); v++){
		distancias = INT_MAX;
		predecessores = NIL;
	}
	distancias[s]=0;
}

void Dijkstra::relaxa(Grafo g, int u, int v){
	if(distancias[v]>distancias[u]+g.w(u, v)){
		distancias[v]=distancias[u]+g.w(u, v);
		predecessor[v]=u;
	}
}
