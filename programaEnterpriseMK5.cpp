#include <iostream>
#include <limits.h>
#define NIL -1
using namespace std;

enum Cor {branco, cinza, preto};

bool verificar(int i, int *inimigos, int tam){
    for(int k=1; k<=tam; k++){
        if(inimigos[k]==i){
            return true;
        }
    }
    return false;
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
class FilaDinamica{
private:
	No<Tipo> *frente;
	No<Tipo> *tras;
    int tam;
public:
	FilaDinamica();
	No<Tipo> *getFrente();
	No<Tipo> *getTras();
	void enfileira(Tipo);
	Tipo desenfileira(Tipo);
    int getTam();
	void Mostra();
};

template <class Tipo>
FilaDinamica<Tipo>::FilaDinamica(){
	frente = new No<Tipo>();
	tras= frente;
    tam = 0;
}
template <class Tipo>
No<Tipo> *FilaDinamica<Tipo>::getFrente(){
	return frente;
}
template <class Tipo>
No<Tipo> *FilaDinamica<Tipo>::getTras(){
	return tras;
}
template <class Tipo>
int FilaDinamica<Tipo>::getTam(){
	return tam;
}
template <class Tipo>
void FilaDinamica<Tipo>::enfileira(Tipo item){
	tras->setProx(new No<Tipo>());
	tras = tras->getProx();
	tras->setItem(item);
    tam++;
}

template <class Tipo>
Tipo FilaDinamica<Tipo>::desenfileira(Tipo item){
 	No<Tipo> *p = frente;
 	frente = frente->getProx();
	item = frente->getItem();
	delete p;
    tam--;
	return item;
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

class BuscaProfundidade{
private:
    int tempo;
    Cor *cores;
    int *tempoD;
    int *tempoF;
    int *predecessores;
    float custoDoPercurso;
public:
    BuscaProfundidade();
    void dfs(Grafo &g);
    void dfsVisita(Grafo &g, int u);
    float getCustoDoPercurso();
    int *getPredecessores();
    int *getTempoD();
    int *getTempoF();
};
BuscaProfundidade::BuscaProfundidade(){

}

float BuscaProfundidade::getCustoDoPercurso(){
    return custoDoPercurso;
}

int *BuscaProfundidade::getPredecessores(){
    return predecessores;
}

int *BuscaProfundidade::getTempoD(){
    return tempoD;
}

int *BuscaProfundidade::getTempoF(){
    return tempoF;
}


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

class BuscaLargura{
private:
    int distancia;
    Cor *cores;
    int *distancias;
    int *predecessor;
public:
    BuscaLargura();
    void BFS(Grafo g, int s, int *inimigos, int quantidadeDeInimigos);
    int *getPredecessores();
    int *getDistancias();
};

BuscaLargura::BuscaLargura(){

}

int *BuscaLargura::getDistancias(){
    return distancias;
}

int *BuscaLargura::getPredecessores(){
    return predecessor;
}

void BuscaLargura::BFS(Grafo g, int s, int *inimigos, int quantidadeDeInimigos){
    this->cores  = new Cor[g.getN()+1];
    this->distancias = new int[g.getN()+1];
    this->predecessor = new int[g.getN()+1];
    this->distancia = 0;
    for(int i=1; i<=g.getN(); i++){
      cores[i]=branco;
      distancias[i]= INT_MAX;
      predecessor[i]=0;
    }
    cores[s] = cinza;
    distancias[s] = 0;
    predecessor[s]=0;
    FilaDinamica<int> q;
    q.enfileira(s);
    while(q.getTam()!=0){
        int u = q.desenfileira(u);
        Lista<Par> vertices = g.getAdj()[u];
        No<Par> *v = vertices.getPrim()->getProx();
        while(v!=NULL){
            if(cores[v->getItem().getChave()]==branco && !verificar(u, inimigos, quantidadeDeInimigos)){
                cores[v->getItem().getChave()]=cinza;
                distancias[v->getItem().getChave()]=distancias[u]+1;
                predecessor[v->getItem().getChave()]=u;
                q.enfileira(v->getItem().getChave());
            }
            v = v->getProx();
        }
        cores[u]=preto;
    }
}

void inicializarGrafo(Grafo &g){
    for(int i=1; i<=g.getM(); i++){
        int u, v;
        cin>>u;
        cin>>v;
        g.inserirVertice(u, v, 0);
    }
}

void inicializarSistemaPlanetario(Grafo &sistema){
    for(int j=1; j<=sistema.getM(); j++){
        int u, v;
        float w;
        cin>>u;
        cin>>v;
        scanf("%f\n", &w);
        sistema.inserirVertice(u, v, w);
    }
}

void inicializarSistemasPlanetarios(Grafo *sistemas, int n){
    for(int i=1; i<=n; i++){
        int ordem, tam;
        cin>>ordem;
        cin>>tam;
        sistemas[i].inicializar(ordem, tam);
        inicializarSistemaPlanetario(sistemas[i]);
    }
}

float explorarSistema(Grafo &sistema, int n, int *inimigos, int quantidadeDeInimigos){
    float valorDoCaminho = 0;
    BuscaProfundidade buscaProfundidade;
    buscaProfundidade.dfs(sistema);
    valorDoCaminho+=buscaProfundidade.getCustoDoPercurso();
    return valorDoCaminho;
}

void explorarUniverso(Grafo &g, Grafo *sistemas, int *inimigos, int quantidadeDeInimigos, int sistemaInicial, int sistemaFinal){
    BuscaLargura buscaLargura;
    buscaLargura.BFS(g, sistemaInicial, inimigos, quantidadeDeInimigos);
    int *sistemasASeremVisitados = buscaLargura.getPredecessores();
    int n = g.getN();
    float custoTotal = 0;
    custoTotal += explorarSistema(sistemas[sistemaFinal], n, inimigos, quantidadeDeInimigos);
    int verificador = sistemaFinal, i = sistemasASeremVisitados[sistemaFinal];
    while(verificador!=sistemaInicial){
        custoTotal += explorarSistema(sistemas[i], n, inimigos, quantidadeDeInimigos);
        verificador = i;
        i = sistemasASeremVisitados[i];
    }
    printf("%.1f\n", custoTotal);
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
    inicializarSistemasPlanetarios(sistemas, N);
    explorarUniverso(g, sistemas, inimigos, quantidadeDeInimigos, sistemaInicial, sistemaFinal);
    return 0;
}
