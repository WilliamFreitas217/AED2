#include <iostream>
using namespace std;
enum Cor {branco, cinza, preto};

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
    Vertice *verticePredesc; //vertice Predecessor
    Item item;
    int chave;
    Cor cor;
    int tempoD;
    int tempoF;
public:
    Vertice();
    Vertice(Cor cor, int chave);
    Cor getCor();
    int getTempoD();
    int getTempoF();
    Item getItem();
    int getChave();
    Vertice *&getVerticePredesc();
    void setVerticePredesc(Vertice &vertice);
    void setChave(int chave);
    void setItem(Item &item);
    void setCor(Cor cor);
    void setTempoD(int tempo);
    void setTempoF(int tempo);
};

Vertice::Vertice(){
    this->verticePredesc =NULL;
}

Vertice::Vertice(Cor cor, int chave){
    this->cor = cor;
    this->chave = chave;
    this->tempoD = 0;
    this->verticePredesc =NULL;
}

Cor Vertice::getCor(){
    return cor;
}

int Vertice::getTempoD(){
    return tempoD;
}

int Vertice::getTempoF(){
    return tempoF;
}

Item Vertice::getItem(){
    return item;
}

int Vertice::getChave(){
    return chave;
}

Vertice *&Vertice::getVerticePredesc(){
    return verticePredesc;
}

void Vertice::setVerticePredesc(Vertice &vertice){
    this->verticePredesc = &vertice;
}

void Vertice::setChave(int chave){
    this->chave = chave;
}

void Vertice::setItem(Item &item){
    this->item = item;
}

void Vertice::setCor(Cor cor){
    this->cor = cor;
}

void Vertice::setTempoD(int tempo){
    this->tempoD = tempo;
}

void Vertice::setTempoF(int tempo){
    this->tempoF = tempo;
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
    	cout<<p->getItem().getItem().getNome();
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

class BuscaProfundidade{
private:
  int tempo;
public:
    void dfs(Grafo<Vertice> &g);
    void dfsVisita(Grafo<Vertice> &g, No<Vertice>*u);
};

void BuscaProfundidade::dfs(Grafo<Vertice> &g){
  Lista<Vertice> *adj = g.getAdj();
  for(int i=1; i<=g.getN(); i++){
      adj[i].getPrim()->getProx()->getItem().setCor(branco);
      // cout<<adj[i].getPrim()->getProx()->getItem().getChave()<<endl;
    // adj[i].getPrim()->getProx()->getItem().setVerticePredesc(NULL);
  }
  tempo = 0;
  for(int i=1; i<=g.getN(); i++){
    if(adj[i].getPrim()->getProx()->getItem().getCor() == branco){
      dfsVisita(g, adj[i].getPrim());
    }
  }
}

void BuscaProfundidade::dfsVisita(Grafo<Vertice> &g, No<Vertice> *u){
  tempo++;
  u->getProx()->getItem().setTempoD(tempo);
  u->getProx()->getItem().setCor(cinza);
  No<Vertice> *v = u->getProx();
  while(v!=NULL){
    if(v->getItem().getCor()==branco){
        v->getItem().setVerticePredesc(u->getItem());
        dfsVisita(g, v);
    }
    v = v->getProx();
  }
  // cout<<"aqui"<<endl;
  u->getItem().setCor(preto);
  tempo++;
  u->getItem().setTempoF(tempo);
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
    Vertice a1, b1, c1, d1, e1;
    a1.setChave(1);
    a1.setItem(a);
    b1.setChave(2);
    b1.setItem(f);
    c1.setChave(3);
    c1.setItem(c);
    d1.setChave(4);
    d1.setItem(d);
    e1.setChave(5);
    e1.setItem(e);
  	g.inserirVertice(a1, b1);
  	g.inserirVertice(b1, c1);
  	g.inserirVertice(c1, d1);
  	g.inserirVertice(d1, e1);
  	g.inserirVertice(e1, a1);
  	g.inserirVertice(e1, b1);
  	g.inserirVertice(b1, d1);
    BuscaProfundidade busca;
    g.mostra();
    busca.dfs(g);
}
int main(){
    int n;
	n=5;
	Grafo<Vertice> g(n);
	testaGrafo(g);
    return 0;
}
