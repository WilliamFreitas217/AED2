#include <iostream>
#include <limits.h>
#include<cmath>
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
	// item = new Tipo;
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
    	// cout<<p->getItem().getItem().getNome();
    	cout<<p->getItem().getChave();
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
	while((p->getItem()->getChave() != objeto->getChave())&&(p!=NULL)){
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
class Vertice{
private:
    int verticePredesc; //vertice Predecessor
    Item item;
    int chave;
public:
    Vertice();
    Vertice(int chave);
    Item getItem();
    int getChave();
    int getVerticePredesc();
    void setVerticePredesc(int vertice);
    void setChave(int chave);
    void setItem(Item &item);
};

Vertice::Vertice(){
}

Vertice::Vertice(int chave){
    this->chave = chave;
}

Item Vertice::getItem(){
    return item;
}

int Vertice::getChave(){
    return chave;
}

int Vertice::getVerticePredesc(){
    return verticePredesc;
}

void Vertice::setVerticePredesc(int vertice){
    this->verticePredesc = vertice;
}

void Vertice::setChave(int chave){
    this->chave = chave;
}

void Vertice::setItem(Item &item){
    this->item = item;
}

template <class Tipo>
class Grafo{
private:
    Lista<Tipo> *adj;
    int n; //ordem
    int m; //tam
    void destruir();
public:
	Grafo();
    Grafo(int n);
	void inicializar(int n);
    void inserirVertice(Vertice u, Vertice v);
    void ordenarADJ();
    Lista<Tipo> *getAdj();
    void mostra();
	void setN(int n);
	void setM(int m);
	int getM();
	int getN();

};

template <class Tipo>
Grafo<Tipo>::Grafo(){
}

template <class Tipo>
Grafo<Tipo>::Grafo(int n){
    this->n = 0;
    this->m = 0;
	inicializar(n);
}

template <class Tipo>
void Grafo<Tipo>::inicializar(int n){
	if(this->n != 0){
		destruir();
	}
	this->n = n;
	adj = new Lista<Vertice>[n+1];
}

template <class Tipo>
void Grafo<Tipo>::inserirVertice(Vertice u, Vertice v){
	Tipo x = v;
	adj[u.getChave()].insere(x);
	x = u;
	adj[v.getChave()].insere(x);
	m++;
}

template <class Tipo>
void Grafo<Tipo>::mostra(){
	for(int i=1; i<=n; i++){
		cout<<"v["<<i<<"] = {";
		adj[i].mostra();
		cout<<"}"<<endl;
	}
}

template <class Tipo>
void Grafo<Tipo>::destruir(){
	for(int i=0; i<=n; i++){
		adj[i].destruir();
	}
	delete[] adj;
	n=m=0;
}

template <class Tipo>
Lista<Tipo> *Grafo<Tipo>::getAdj(){
	return adj;
}

template <class Tipo>
void Grafo<Tipo>::setN(int n){
	this->n = n;
}

template <class Tipo>
void Grafo<Tipo>::setM(int m){
	this->m = m;
}

template <class Tipo>
int Grafo<Tipo>::getN(){
	return n;
}

template <class Tipo>
int Grafo<Tipo>::getM(){
	return m;
}

template <class Tipo>
void Grafo<Tipo>::ordenarADJ(){
    for(int i=1; i<=n; i++){
        Vertice *vetor = new Vertice[adj[i].getTam()+1];
        int k = 1;
        No<Vertice> *v = adj[i].getPrim()->getProx();
        while (v!=NULL) {
            vetor[k] = v->getItem();
            k++;
            v = v->getProx();
        }
        Heap<Vertice> heap;
        heap.heapSort(vetor, k);
        k = 1;
        v = adj[i].getPrim()->getProx();
        while (v!=NULL) {
            v->getItem()=vetor[k];
            k++;
            v = v->getProx();
        }
    }
}

class BuscaLargura{
private:
    int distancia;
    Cor *cores;
    int *distancias;
    int *predecessor;
public:
    void BFS(Grafo<Vertice> g, int s);
};
void BuscaLargura::BFS(Grafo<Vertice> g, int s){
    this->cores  = new Cor[g.getN()+1];
    this->distancias = new int[g.getN()+1];
    this->predecessor = new int[g.getN()+1];
    this->distancia = 0;
    for(int i=1; i<=g.getN(); i++){
      cores[i]=branco;
      distancias[i]= INT_MAX;
      predecessor[i]=0;
      // cout<<i<<endl;
    }
    cores[s] = cinza;
    distancias[s] = 0;
    predecessor[s]=0;
    FilaDinamica<int> q;
    // cout<<s<<endl;
    q.enfileira(s);
    while(q.getTam()!=0){
        int u = q.desenfileira(u);
        // cout<<u<<endl<<endl;
        Lista<Vertice> vertices = g.getAdj()[u];
        No<Vertice> *v = vertices.getPrim()->getProx();
        int i=0;
        while(v!=NULL){
            if(cores[v->getItem().getChave()]==branco){
                // cout<<v->getItem().getChave()<<endl;
                cores[v->getItem().getChave()]=cinza;
                distancias[v->getItem().getChave()]=distancias[u]+1;
                predecessor[v->getItem().getChave()]=u;
                q.enfileira(v->getItem().getChave());
            }
            v = v->getProx();
        }
        cores[u]=preto;
    }
    for(int i=1; i<=g.getN(); i++){
        cout<<"{"<<i<<"} = "<<predecessor[i]<<endl;
    }
}
template <class Tipo>
void testaGrafo(Grafo<Tipo> &g){
    Item a, b, c, d, e, f, h;
    a.setNome("Will");
    b.setNome("Artur");
    c.setNome("Gian");
    d.setNome("Lucas");
    e.setNome("Arthur");
    f.setNome("Leticia");
    h.setNome("Mari");
    BuscaLargura busca;
    Vertice a1, b1, c1, d1, e1;
    a1.setChave(1);
    a1.setItem(e);
    b1.setChave(2);
    b1.setItem(f);
    c1.setChave(3);
    c1.setItem(c);
    d1.setChave(4);
    d1.setItem(d);
    e1.setChave(5);
    e1.setItem(a);
  	g.inserirVertice(a1, b1);
  	g.inserirVertice(b1, c1);
  	g.inserirVertice(c1, d1);
  	g.inserirVertice(d1, e1);
  	g.inserirVertice(e1, a1);
  	g.inserirVertice(e1, b1);
  	g.inserirVertice(b1, d1);
  	g.mostra();
    busca.BFS(g, 1);
    g.ordenarADJ();
    cout<<"-----------------------------------"<<endl;
    g.mostra();
    busca.BFS(g, 1);
    // g.mostra();
}
int main(){
    int n;
	  n=5;
	  Grafo<Vertice> g(n);
	  testaGrafo(g);
    return 0;
}
