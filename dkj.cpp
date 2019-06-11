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
        cout<<"["<<i-1<<"] :: "<< vetor[i].getVertice()-1<<"\t|| "<<vetor[i].getPesoAresta()<<endl;
    }
}

template <class Tipo>
void printar(Tipo *vetor, int tam){
    for(int i=1; i<=tam; i++){
        cout<<"["<<i-1<<"] :: "<< vetor[i]-1<<endl;
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
    while (i != 0 && vetor[pai(i)].getPesoAresta() > vetor[i].getPesoAresta())
	{
    	troca(vetor[i], vetor[pai(i)]);
    	i = pai(i);
	}
}

void FilaDePrioridade::insere(Par par){
    tamHeap++;
    vetor[tamHeap].setVertice(par.getVertice());
    vetor[tamHeap].setPesoAresta(par.getPesoAresta());
    int i = tamHeap;
    while (i != 0 && vetor[pai(i)].getPesoAresta() > vetor[i].getPesoAresta())
	{
    	troca(vetor[i], vetor[pai(i)]);
    	i = pai(i);
	}
    // quickSort(vetor, 1,tamHeap);
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
    // printarVetor(vetor, 28);
	for(int i=1; i<=tamHeap; i++){
        cout<<"\tVertice: "<<vetor[i].getVertice()<<"\tPeso: "<< vetor[i].getPesoAresta()<<endl;
    }
}

int FilaDePrioridade::getTamHeap(){
    return tamHeap;
}
void FilaDePrioridade::atualizar(int chave, float w){
    for(int i=1; i<=tamHeap; i++){
        if(vetor[i].getVertice()==chave && vetor[i].getPesoAresta() >w){
            vetor[i].setPesoAresta(w);
        }
    }
    quickSort(vetor, 1,tamHeap);
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
    	cout<<p->getItem().getVertice()<<" ("<<p->getItem().getPesoAresta()<<")";
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
	x.setVertice(u); //deve
    x.setPesoAresta(w); //ser
	adj[v].insere(x); //desativada caso seja direcionado
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
	Lista<Par> S;
    int *predecessores;
    float *distancias;
    float distancia;
    FilaDePrioridade Q;
public:
    Dijkstra();
    Dijkstra(Grafo g, int s);
    void inicializar(Grafo g, int s);
    void relaxa(Grafo g, int u, int v);
	Lista<Par> *getS();
    int *getPredecessores();
    float *getDistancias();
};

Dijkstra::Dijkstra(){
}

Dijkstra::Dijkstra(Grafo g, int s){
	inicializar(g, s);
	while(Q.getTamHeap()!=0){
        Par u = Q.extrairMin();
        Lista<Par> vetor = g.getAdj()[u.getVertice()];
        No<Par> *v = vetor.getPrim()->getProx();
		while(v!=NULL){
			relaxa(g, u.getVertice(), v->getItem().getVertice());
			v= v->getProx();
		}
	}
}

void Dijkstra::inicializar(Grafo g, int s){
	predecessores = new int[g.getN()+1];
	distancias = new float[g.getN()+1];
    Q.inicializar(g.getN());
	for(int v=1; v<=g.getN(); v++){
		distancias[v] = INT_MAX;
		predecessores[v] = NIL;
        Par par(v, distancias[v]);
        Q.insere(par);
	}

    distancias[s]=0;
    Q.atualizar(s, 0);
}

void Dijkstra::relaxa(Grafo g, int u, int v){
	if(distancias[v]>distancias[u]+g.w(u, v)){
		distancias[v]=distancias[u]+g.w(u, v);
		predecessores[v]=u;
        Q.atualizar(v, distancias[v]);
        // Q.mostra();
	}
}

Lista<Par> *Dijkstra::getS(){
    return &S;
}

int *Dijkstra::getPredecessores(){
    return predecessores;
}

float *Dijkstra::getDistancias(){
    return distancias;
}

void testaGrafo(Grafo &g){
    Dijkstra *dijkstra;
    for(int i=1; i<=g.getM(); i++){
        int u, v;
        float w;
        cin>>u>>v;
        scanf("%f\n", &w);
        g.inserirVertice(u, v, w);
    }
	// g.mostra();
    dijkstra = new Dijkstra(g, 18);
    printar(dijkstra->getPredecessores(), g.getN());
    cout<<"==============================="<<endl;
    // printar(dijkstra->getDistancias(), g.getN());
}

int main(int argc, char const *argv[]) {
    int n, m;
	cin>>n>>m;
	Grafo g(n, m);
	testaGrafo(g);
    return 0;
}
