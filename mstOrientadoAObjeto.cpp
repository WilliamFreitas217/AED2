#include <iostream>
#include<cstdlib>
#include <iomanip>
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
class FilaDePrioridade{
private:
    No<Tipo> *prim;
	No<Tipo> *ult;
    int tam;
public:
    FilaDePrioridade();
    No<Tipo> *getPrim();
    No<Tipo> *getUlt();
    int getTam();
    Tipo extrairMin(Tipo &item);
	void insere(Tipo&);
    void decrescerMin(int chave, int chaveNova);
	No<Tipo> *minimo();
	void runHeap();
    bool verificar(int chaveDoVertice);
	void mostra();
};

template <class Tipo>
FilaDePrioridade<Tipo>::FilaDePrioridade(){
    prim = new No<Tipo>();
	ult = prim;
    tam=0;
}

template <class Tipo>
void FilaDePrioridade<Tipo>::insere(Tipo &item){
	ult->setProx(new No<Tipo>());
	ult = ult->getProx();
	ult->setItem(item);
    tam++;
    runHeap();
}

template <class Tipo>
No<Tipo> *FilaDePrioridade<Tipo>::minimo(){
    No<Tipo> *p = prim->getProx();
    No<Tipo> *menor = p;
    while(p!=NULL){
        if(menor->getItem().getChave()>=p->getItem().getChave()){
            menor = p;
        }
        p = p->getProx();
    }
    return menor;
}

template <class Tipo>
void FilaDePrioridade<Tipo>::runHeap(){
    Tipo *vetor = new Tipo[tam+1];
    No<Tipo> *v = prim->getProx();
    int k =1;
    while (v!=NULL) {
        vetor[k] = v->getItem();
        k++;
        v = v->getProx();
    }
    Heap<Vertice> heap;
    heap.heapSort(vetor, tam);
    k = 1;
    v = prim->getProx();
    while (v!=NULL) {
        v->getItem()=vetor[k];
        k++;
        v = v->getProx();
    }
}

template <class Tipo>
Tipo FilaDePrioridade<Tipo>::extrairMin(Tipo &item){
 	No<Tipo> *p = prim;
	// item = new Tipo;
 	prim = prim->getProx();
	item = prim->getItem();
	delete p;
    tam--;
	return item;
}

template <class Tipo>
void FilaDePrioridade<Tipo>::mostra(){
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
void FilaDePrioridade<Tipo>::decrescerMin(int chave, int chaveNova){
    No<Tipo> *p = prim->getProx();
	while(p!= NULL){
        if(p->getItem()==chave){
            p->getItem().setChave(chaveNova);
            break;
        }
        p = p->getProx();
    }
}

template <class Tipo>
bool FilaDePrioridade<Tipo>::verificar(int chaveDoVertice){
    No<Tipo> *p = prim->getProx();
	while(p!= NULL){
        if(p->getItem()==chaveDoVertice){
            return true;
        }
        p = p->getProx();
    }
    return false;
}

template <class Tipo>
int FilaDePrioridade<Tipo>::getTam(){
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

typedef int Peso;
template <class Tipo>
class Grafo{
private:
    Lista<Tipo> *adj;
    int n; //ordem
    int m; //tam
    int **mat;
    void destruir();
public:
	Grafo();
    Grafo(int n);
	void inicializar(int n);
    void inserirVertice(Vertice u, Vertice v, Peso w);
    void ordenarADJ();
    Lista<Tipo> *getAdj();
    void mostra();
	void setN(int n);
	void setM(int m);
	int getM();
	int getN();
    Peso **&getMat();
    int w(int u, int v);

};

template <class Tipo>
Grafo<Tipo>::Grafo(){
}

template <class Tipo>
Grafo<Tipo>::Grafo(int n){
    this->n = 0;
    this->m = 0;
    mat = new Peso *[n];
    for(int i=0; i<=n; i++){
      mat[i] = new Peso[n];
    }
	inicializar(n);
}

template <class Tipo>
void Grafo<Tipo>::inicializar(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          mat[i][j]=0;
        }
    }
	if(this->n != 0){
		destruir();
	}
	this->n = n;
	adj = new Lista<Vertice>[n+1];
}

template <class Tipo>
void Grafo<Tipo>::inserirVertice(Vertice u, Vertice v, Peso w){
	Tipo x = v;
	adj[u.getChave()].insere(x);
	x = u;
	adj[v.getChave()].insere(x);
    mat[u.getChave()-1][v.getChave()-1] = w;
    mat[v.getChave()-1][u.getChave()-1] = w; //deve ser desativada caso o grafo seja direcionado
	m++;
}

template <class Tipo>
void Grafo<Tipo>::mostra(){
    cout<<" Listas de Adjacências \t"<<endl;
	for(int i=1; i<=n; i++){
		cout<<"v["<<i<<"] = {";
		adj[i].mostra();
		cout<<"}"<<endl;
	}
    cout<<"------------------------------------------------------"<<endl;
    cout<<" Matriz de Adjacências \t"<<endl;
    int k = 3;
    cout<<" ";
    for(int j=0; j< n; j++){
        cout<< setw(k)<<j+1;
    }
    cout<<endl;
    for(int j=0; j< n*k+3; j++){
        cout<<"-";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<setw(1)<<i+1;
        cout<<"|";
        for(int j=0; j<n; j++){
            cout<<setw(k)<<mat[i][j];
        }
        cout<<endl;
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
template <class Tipo>
int Grafo<Tipo>::w(int u, int v){
    return mat[u][v];
}
template <class Tipo>
Peso **&Grafo<Tipo>::getMat(){
	return mat;
}

class MST{
private:
    int *chaves;
    int *predecessores;
public:
    void mstPrim(Grafo<Vertice> &g, int r);
    // void mostraChaves();
    // void mostraPredecessores();
};

void MST::mstPrim(Grafo<Vertice> &g, int r){
    chaves = new int[g.getN()+1];
    predecessores = new int[g.getN()+1];
    for(int u=1; u<=g.getN(); u++){
        chaves[u]=INT_MAX;
        predecessores[u]=0;
    }
    chaves[r]=0;
    FilaDePrioridade<Vertice> Q;
    for(int i=1; i<=g.getN(); i++){
        Q.insere(i);
    }
    while(Q.getTam()!=0){
        int u = Q.extrairMin(u);
        Lista<Vertice> vetor = g.getAdj()[u];
        No<Vertice> *v = vetor.getPrim()->getProx();
        if(g.w(u, v->getItem().getChave())<chaves[v->getItem().getChave()] && Q.verificar(v->getItem().getChave())){
            predecessores[v->getItem().getChave()]=u;
            chaves[v->getItem().getChave()]=g.w(u, v->getItem().getChave());
        }
    }
    for(int i=1; i<=g.getN(); i++){
        cout<<"predecessor de "<<i<<": "<<predecessores[i]<<endl;
    }
    for(int i=1; i<=g.getN(); i++){
        cout<<"chaves: "<<chaves[i]<<endl;
    }
}

template <class Tipo>
void testaGrafo(Grafo<Tipo> &g){
    Item a, b, c, d, e, f, h;
    MST mst;
    a.setNome("Will");
    b.setNome("Artur");
    c.setNome("Gian");
    d.setNome("Lucas");
    e.setNome("Arthur");
    f.setNome("Leticia");
    h.setNome("Mari");
    Vertice a1, b1, c1, d1, e1, f1;
    a1.setChave(1);
    a1.setItem(a);
    b1.setChave(2);
    b1.setItem(b);
    c1.setChave(3);
    c1.setItem(c);
    d1.setChave(4);
    d1.setItem(d);
    e1.setChave(5);
    e1.setItem(e);
    f1.setChave(6);
    f1.setItem(f);
	g.inserirVertice(1, 2, 1);
	g.inserirVertice(1, 4, 1);
	g.inserirVertice(4, 2, 1);
	g.inserirVertice(2, 5, 1);
	g.inserirVertice(5, 4, 1);
	g.inserirVertice(3, 5, 1);
	g.inserirVertice(3, 6, 1);
    g.inserirVertice(6, 6, 1);
	g.mostra();
    mst.mstPrim(g, 1);
}
int main(){
    int n, m;
	n=6;
	Grafo<Vertice> g(n);
	testaGrafo(g);
    return 0;
}
