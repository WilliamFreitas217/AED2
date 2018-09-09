#include <iostream>
#include<cstdlib>
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
}
template <class Tipo>
void Lista<Tipo>::insere(Tipo &item){
	ult->setNo(new No<Tipo>());
	ult = ult->getProx();
	ult->setItem(item);
}
template <class Tipo>
void Lista<Tipo>::mostra(){
	No<Tipo> *p = prim->getProx();
	while(p!= NULL){
    	cout<<p->getItem();
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
typedef int Vertice;
template <class Tipo>
class Grafo{
private:
  Lista<Tipo> *adj;
  int n = 0; //ordem
  int m = 0; //tam
  void destruir();
public:
	Grafo();
  Grafo(int n);
	void inicializar(int n);
  void inserirVertice(Vertice u, Vertice v);
  // void removerVertice(Vertice u, Vertice v);
  Lista<Tipo> *&getAdj();
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
	Tipo x = {v};
	adj[u].insere(x);
	x = {u};
	adj[v].insere(x);
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
Lista<Tipo> *&Grafo<Tipo>::getAdj(){
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
// template <class Tipo>
// void removerVertice(Vertice u, Vertice v){
//
// }
template <class Tipo>
void testaGrafo(Grafo<Tipo> &g){
	g.inserirVertice(1, 2);
	g.inserirVertice(2, 3);
	g.inserirVertice(3, 4);
	g.inserirVertice(4, 5);
	g.inserirVertice(5, 1);
	g.inserirVertice(5, 2);
	g.inserirVertice(2, 4);
	g.mostra();
}
int main(int argc, char const *argv[]) {
	int n, m;
	n=5;
	Grafo<int> g(n);
	testaGrafo(g);
	return 0;
}
