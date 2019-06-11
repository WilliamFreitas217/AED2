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
    if(l<=tamHeap && vetor[l].getPesoAresta()>vetor[i].getPesoAresta()){
        maior =l;
    }
    else{
        maior = i;
    }
    if(r<=tamHeap && vetor[r].getPesoAresta()>vetor[maior].getPesoAresta()){
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
	void setNo(No<Tipo> *);
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
void No<Tipo>::setNo(No<Tipo> *no){
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
	ult->setNo(new No<Tipo>());
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
  	p->setNo(Busca(r->getItem())->getProx());
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
	// cout<<"aqui"<<endl;
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

typedef float Peso;
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

typedef float Peso;
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

void Grafo::ordenarADJ(){
    for(int i=1; i<=n; i++){
        Par *vetor = new Par[adj[i].getTam()+1];
        int k = 1;
        No<Par> *v = adj[i].getPrim()->getProx();
        while (v!=NULL) {
            vetor[k] = v->getItem();
            k++;
            v = v->getProx();
        }
        Heap<Par> heap;
        heap.heapSort(vetor, k);
        k = 1;
        v = adj[i].getPrim()->getProx();
        while (v!=NULL) {
            v->setItem(vetor[k]);
            k++;
            v = v->getProx();
        }
    }
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

class BuscaProfundidade{
private:
    int tempo;
    Cor *cores;
    int *tempoD;
    int *tempoF;
    int *predecessores;
    int custoDoPercurso;
public:
    void dfs(Grafo &g);
    void dfsVisita(Grafo &g, int u);
    int getCustoDoPercurso();
    int *getPredecessores();
};

void BuscaProfundidade::dfs(Grafo &g){
    this->cores  = new Cor[g.getN()+1];
    this->tempoD = new int[g.getN()+1];
    this->tempoF = new int[g.getN()+1];
    this->predecessores = new int[g.getN()+1];
    this->custoDoPercurso = 0;
    for(int i=1; i<=g.getN(); i++){
        cores[i]=branco;
        predecessores[i]=-1;
    }
    tempo = 0;
    for(int i=1; i<=g.getN(); i++){
      if(cores[i] == branco){
          dfsVisita(g, i);
      }
    }
}

void BuscaProfundidade::dfsVisita(Grafo &g, int u){
    tempo++;
    tempoD[u] = tempo;
    cores[u] = cinza;
    int i = 1;
    Lista<Par> adj = g.getAdj()[u];
    No<Par> *vertice = adj.getPrim()->getProx();
    while(i<=adj.getTam()){
        int v = vertice->getItem().getChave();
        if(cores[v]==branco){
            predecessores[v] =u;
            custoDoPercurso+=vertice->getItem().getPesoAresta();
            dfsVisita(g, v);
        }
        vertice = vertice->getProx();
        i++;
    }
    cores[u] = preto;
    tempo++;
    tempoF[u] = tempo;
}

int BuscaProfundidade::getCustoDoPercurso(){
    return custoDoPercurso;
}

int *BuscaProfundidade::getPredecessores(){
    return predecessores;
}

template <class Tipo>
void printarVetor(Tipo *v, int n){
    for(int i=1; i<=n; i++){
        cout<<"I: "<< i<<": "<<v[i]<<endl;
    }
}

void inicializarGrafo(Grafo &g){
    for(int i=1; i<=g.getM(); i++){
        int u, v;
        cin>>u;
        cin>>v;
        g.inserirVertice(u, v, 0);
    }
    // g.mostra();
    // g.ordenarADJ();
    g.mostra();
    BuscaProfundidade busca;
    busca.dfs(g);
    int *v = busca.getPredecessores();
    printarVetor(v, g.getN());
    // cout<<"Criando Sistemas Planetarios"<<endl;
}

void inicializarSistemaPlanetario(Grafo &sistema){
    // cout<<sistema.getM()<<endl;
    for(int j=1; j<=sistema.getM(); j++){
        int u, v;
        float w;
        cin>>u;
        cin>>v;
        cin>>w;
        // cout<<j
        sistema.inserirVertice(u, v, w);
    }
    // sistema.mostra();
    // sistema.ordenarADJ();
    sistema.mostra();
}

void inicializarSistemasPlanetarios(Grafo *sistemas, int n){
    for(int i=1; i<=n; i++){
        int ordem, tam;
        cin>>ordem;
        cin>>tam;
        sistemas[i].inicializar(ordem, tam);
        cout<<"Sistema "<<i<<endl;
        inicializarSistemaPlanetario(sistemas[i]);
    }
}
bool confere(int *v, int chave, int tam){
    for(int i=1; i<=tam; i++){
        if(v[i]==chave && chave!=-1){
            return true;
        }
    }
    return false;
}

bool verificar(int i, int *inimigos, int tam){
    for(int k=1; i<=tam; i++){
        if(inimigos[k]==i && i!=-1){
            cout<<i<<endl;
            return true;
        }
    }
    return false;
}

float explorarSistema(Grafo &sistema, int n, int *inimigos, int quantidadeDeInimigos){
    float valorDoCaminho = 0;
    BuscaProfundidade busca;
    busca.dfs(sistema);
    valorDoCaminho+=busca.getCustoDoPercurso();
    return valorDoCaminho;
}

void explorarUniverso(Grafo &g, Grafo *sistemas, int *inimigos, int quantidadeDeInimigos){
    BuscaProfundidade busca;
    busca.dfs(g);
    int *sistemasASeremVisitados = busca.getPredecessores();
    printarVetor(sistemasASeremVisitados, g.getN());
    float custoTotal = 0;
    for(int sistemaPlanetario = 1; sistemaPlanetario<=g.getN(); sistemaPlanetario++){
        if(!verificar(sistemaPlanetario, inimigos, quantidadeDeInimigos) && confere(sistemasASeremVisitados, sistemaPlanetario, g.getN())){
            custoTotal += explorarSistema(sistemas[sistemaPlanetario], g.getN(), inimigos, quantidadeDeInimigos);
        }
    }
    cout<<custoTotal<<endl;
}

int main(int argc, char const *argv[]) {
    int N, M;
    cin>>N;
    cin>>M;
    Grafo g(N, M);
    Grafo *sistemas = new Grafo[N+1];
    int quantidadeDeInimigos, *inimigos, sistemaInicial, sistemaFinal;
    inicializarGrafo(g);
    cin>>quantidadeDeInimigos;
    inimigos = new int[quantidadeDeInimigos+1];
    for(int i=1; i<=quantidadeDeInimigos; i++){
        cin>>inimigos[i];
    }
    cin>>sistemaInicial>>sistemaFinal;
    inicializarSistemasPlanetarios(sistemas, N);
    explorarUniverso(g, sistemas, inimigos, quantidadeDeInimigos);
    return 0;
}
