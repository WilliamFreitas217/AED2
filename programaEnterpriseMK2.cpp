#include <iostream>
#include<cstdlib>
#include <iomanip>
#include <limits.h>
#include<cmath>
#define NIL -1
using namespace std;
enum Cor {branco, cinza, preto};
template <class Tipo>
void printarVetor(Tipo *v, int n){
    for(int i=1; i<=n; i++){
        cout<<"I: "<< i<<": "<<v[i]<<endl;
    }
}
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

// template <class Tipo>
// class FilaDinamica{
// private:
// 	No<Tipo> *frente;
// 	No<Tipo> *tras;
//     int tam;
// public:
// 	FilaDinamica();
// 	No<Tipo> *getFrente();
// 	No<Tipo> *getTras();
// 	void enfileira(Tipo);
// 	Tipo desenfileira(Tipo);
//     int getTam();
// 	void Mostra();
// };
//
// template <class Tipo>
// FilaDinamica<Tipo>::FilaDinamica(){
// 	frente = new No<Tipo>();
// 	tras= frente;
//     tam = 0;
// }
// template <class Tipo>
// No<Tipo> *FilaDinamica<Tipo>::getFrente(){
// 	return frente;
// }
// template <class Tipo>
// No<Tipo> *FilaDinamica<Tipo>::getTras(){
// 	return tras;
// }
// template <class Tipo>
// int FilaDinamica<Tipo>::getTam(){
// 	return tam;
// }
// template <class Tipo>
// void FilaDinamica<Tipo>::enfileira(Tipo item){
// 	tras->setProx(new No<Tipo>());
// 	tras = tras->getProx();
// 	tras->setItem(item);
//     tam++;
// }
//
// template <class Tipo>
// Tipo FilaDinamica<Tipo>::desenfileira(Tipo item){
//  	No<Tipo> *p = frente;
// 	// item = new Tipo;
//  	frente = frente->getProx();
// 	item = frente->getItem();
// 	delete p;
//     tam--;
// 	return item;
// }

template<class  Tipo>
class FilaDinamica{
private:
  No<Tipo> *frente, *tras;
public:
  FilaDinamica();
  No<Tipo> * getFrente();
  void setFrente(No<Tipo> * frente);
  No<Tipo> * getTras();
  void setTras(No<Tipo> * tras);
  bool filaVazia();
  void enfileira(Tipo);
  void desenfileira();
  void mostra();
};
template<class  Tipo>
No<Tipo> * FilaDinamica<Tipo>::getFrente(){
  return frente;
}
template<class  Tipo>
void FilaDinamica<Tipo>::setFrente(No<Tipo> * frente){
  this->frete = frente;
}
template<class  Tipo>
No<Tipo> * FilaDinamica<Tipo>::getTras(){
  return tras;
}
template<class  Tipo>
void FilaDinamica<Tipo>::setTras(No<Tipo> * tras){
  this->tras = tras;
}
template<class  Tipo>
bool FilaDinamica<Tipo>::filaVazia(){
  return frente == tras;
}
template<class  Tipo>
FilaDinamica<Tipo>::FilaDinamica(){
  frente = new No<Tipo>();
  frente->setProx(NULL);
  tras = frente;
}

template<class  Tipo>
void FilaDinamica <Tipo>::enfileira(Tipo x){
  tras->setProx(new No<Tipo>());
  tras = tras->getProx();
  tras->setItem(x);
  tras->setProx(NULL);
}

template<class  Tipo>
void FilaDinamica <Tipo>::desenfileira(){
  No<Tipo> * aux  = frente;
  if(frente!=tras){
    frente = frente->getProx();
    delete aux;
  }else cout << "Fila Vazia" << endl;
}

template<class  Tipo>
void FilaDinamica <Tipo>::mostra(){
  No<Tipo> * i  =  frente->getProx();
  while(i!=NULL){
    cout << i->getItem() << endl;
    i = i->getProx();
  }
}

template <class Tipo>
class PilhaDinamica{
private:
	No<Tipo> *topo;
	No<Tipo> *fundo;
  int tam;
public:
	PilhaDinamica();
	No<Tipo> *getTopo();
	No<Tipo> *getFundo();
	void empilha(Tipo &item);
	Tipo desempilha(Tipo &item);
	void mostra();
  int getTam();
};
template <class Tipo>
PilhaDinamica<Tipo>::PilhaDinamica(){
	topo = new No<Tipo>();
	fundo = topo;
  tam=0;
}
template <class Tipo>
void PilhaDinamica<Tipo>::empilha(Tipo &item){
	No<Tipo> *aux = new No<Tipo>();
	topo->setItem(item);
	aux->setProx(topo);
	topo = aux;
  tam++;
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
void PilhaDinamica<Tipo>::mostra(){
	No<Tipo> *p = topo->getProx();
	while(p!= NULL){
      cout<<p->getItem()<<endl;
      p = p->getProx();
  	}
}

template <class Tipo>
Tipo PilhaDinamica<Tipo>::desempilha(Tipo &item){
	No<Tipo> *aux = topo;
	topo = topo->getProx();
	item = topo->getItem();
	delete aux;
  tam--;
	return item;
}

template <class Tipo>
int PilhaDinamica<Tipo>::getTam(){
  return tam;
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

class BuscaLargura{
private:
    int distancia;
    Cor *cores;
    int *distancias;
    int *predecessor;
public:
    void BFS(Grafo g, int s);
    int *getPredecessores();
};
void BuscaLargura::BFS(Grafo g, int s){
  FilaDinamica<int> * q = new FilaDinamica<int>();
  this->cores  = new Cor[g.getN()+1];
  this->distancias = new int[g.getN()+1];
  this->predecessor = new int[g.getN()+1];
  for(int i = 1; i <= g.getN(); i++) cores[i] = branco;
  cores[s] = cinza;
  distancia = 0;
  q->enfileira(s);
  int u ;
  while(!q->filaVazia()){
    u = q->getFrente()->getProx()->getItem();
    No<Par> * i= g.getAdj()[u].getPrim()->getProx();
    q->desenfileira();
    while(i != NULL){
      int aux = i->getItem().getVertice();
      if(cores[aux] == branco){
        cores[aux] = cinza;
        distancia++;
        predecessor[aux] = u;
        q->enfileira(aux);
      }
      i = i->getProx();
    }
    cores[u] = preto;
  }
}
// void BuscaLargura::BFS(Grafo g, int s){
//     this->cores  = new Cor[g.getN()+1];
//     this->distancias = new int[g.getN()+1];
//     this->predecessor = new int[g.getN()+1];
//     this->distancia = 0;
//     for(int i=1; i<=g.getN(); i++){
//       cores[i]=branco;
//       distancias[i]= INT_MAX;
//       predecessor[i]=0;
//       // cout<<i<<endl;
//     }
//     cores[s] = cinza;
//     distancias[s] = 0;
//     predecessor[s]=0;
//     FilaDinamica<int> q;
//     // cout<<s<<endl;
//     q.enfileira(s);
//     while(q.getTam()!=0){
//         int u = q.desenfileira(u);
//         cout<<u<<endl;
//         Lista<Par> vertices = g.getAdj()[u];
//         No<Par> *v = vertices.getPrim()->getProx();
//         int i=0;
//         while(v!=NULL){
//             if(cores[v->getItem().getChave()]==branco){
//                 // cout<<v->getItem().getChave()<<endl;
//                 cores[v->getItem().getChave()]=cinza;
//                 distancias[v->getItem().getChave()]=distancias[u]+1;
//                 predecessor[v->getItem().getChave()]=u;
//                 q.enfileira(v->getItem().getChave());
//             }
//             v = v->getProx();
//         }
//         cores[u]=preto;
//     }
//     // for(int i=1; i<=g.getN(); i++){
//     //     cout<<"{"<<i<<"} = "<<predecessor[i]<<endl;
//     // }
// }
int *BuscaLargura::getPredecessores(){
    return predecessor;
}

void inicializarGrafo(Grafo &g){
    for(int i=1; i<=g.getM(); i++){
        int u, v;
        cin>>u;
        cin>>v;
        g.inserirVertice(u, v, 0);
    }
    g.mostra();
    cout<<"Criando Sistemas Planetarios"<<endl;
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
    // sistema.mostra();
}

void inicializarSistemasPlanetarios(Grafo *sistemas, int n){
    for(int i=1; i<=n; i++){
        int ordem, tam;
        cin>>ordem;
        cin>>tam;
        sistemas[i].inicializar(ordem, tam);
        // cout<<"Sistema "<<i<<endl;
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
int buscaNoVetor(int *vetor, int chave, int tam){
    // for(int i=1; i<=tam; i++){
    //     if(vetor[i]==chave){
    //         return i;
    //     }
    // }
    // return -1;
    return vetor[chave];
}

void explorarUniverso(Grafo &g, Grafo *sistemas, int *inimigos, int quantidadeDeInimigos, int sistemaInicial, int sistemaFinal){
    BuscaLargura busca;
    busca.BFS(g, sistemaInicial);
    cout<<"Criando Sistemas Planetarios"<<endl;
    int *sistemasASeremVisitados = busca.getPredecessores();
    int n = g.getN();
    float *vetor = new float[n+1];
    for(int i=1; i<=n; i++){
        vetor[i] = explorarSistema(sistemas[i], n, inimigos, quantidadeDeInimigos);
    }
    printarVetor(vetor, n);
    cout<<"------------------------------------------"<<endl;
    printarVetor(sistemasASeremVisitados, n);
    float custoTotal = 0;
    cout<<"Sistema inicial: "<<sistemaInicial<<" || Sistema Final: "<< sistemaFinal<<endl;
    custoTotal += explorarSistema(sistemas[sistemaFinal], n, inimigos, quantidadeDeInimigos);
    int verificador = sistemaFinal, i = sistemasASeremVisitados[sistemaFinal];
    while(verificador!=sistemaInicial){
        custoTotal += explorarSistema(sistemas[i], n, inimigos, quantidadeDeInimigos);
        verificador = i;
        i = sistemasASeremVisitados[i];
    }
    cout<<custoTotal<<endl;
}

int main(int argc, char const *argv[]) {
    int N, M;
    cin>>N;
    cin>>M;
    Grafo g(N, M);
    Grafo *sistemas = new Grafo[N+1];
    inicializarGrafo(g);
    int quantidadeDeInimigos, *inimigos, sistemaInicial, sistemaFinal;
    cin>>quantidadeDeInimigos;
    inimigos = new int[quantidadeDeInimigos+1];
    for(int i=1; i<=quantidadeDeInimigos; i++){
        cin>>inimigos[i];
    }
    cin>>sistemaInicial>>sistemaFinal;
    // cout<<"Sistema inicial: "<<sistemaInicial<<" || Sistema Final: "<< sistemaFinal<<endl;
    inicializarSistemasPlanetarios(sistemas, N);
    explorarUniverso(g, sistemas, inimigos, quantidadeDeInimigos, sistemaInicial, sistemaFinal);
    return 0;
}
