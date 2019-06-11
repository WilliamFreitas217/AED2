#include <iostream>
#include<cstdlib>
#include <iomanip>
using namespace std;

typedef int Vertice;
typedef int Peso;
template <class Tipo>
class Grafo{
private:
  Peso **mat;
  int n=0; //ordem
  int m=0; //tam
public:
	Grafo();
  Grafo(int n);
	void inicializar(int n);
  void inserirVertice(Vertice u, Vertice v, Peso w);
  // void removerVertice(Vertice u, Vertice v);
  Peso **&getMat();
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
    this->n = n;
    mat = new Peso *[n+1];
    for(int i=0; i<=n; i++){
      mat[i] = new Peso[n+1];
    }
    inicializar(n);
}

template <class Tipo>
void Grafo<Tipo>::inicializar(int n){
	for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      mat[i][j]=0;
    }
  }
}

template <class Tipo>
void Grafo<Tipo>::inserirVertice(Vertice u, Vertice v, Peso w){
	mat[u][v] = w;
  // mat[v-1][u-1] = w; //deve ser desativada caso o grafo seja direcionado
  m++;
}

template <class Tipo>
void Grafo<Tipo>::mostra(){
	int k = 3;
  cout<<" ";
  for(int j=1; j<= n; j++){
    cout<< setw(k)<<j;
  }
  cout<<endl;
  for(int j=0; j< n*k+3; j++){
    cout<<"-";
  }
  cout<<endl;
  for(int i=1; i<=n; i++){
    cout<<setw(1)<<i;
    cout<<"|";
    for(int j=1; j<=n; j++){
      cout<<setw(k)<<mat[i][j];
    }
    cout<<endl;
  }
}

template <class Tipo>
Peso **&Grafo<Tipo>::getMat(){
	return mat;
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
void testaGrafo(Grafo<Tipo> &g){
	g.inserirVertice(1, 2, 1);
	g.inserirVertice(1, 4, 1);
	g.inserirVertice(4, 2, 1);
	g.inserirVertice(2, 5, 1);
	g.inserirVertice(5, 4, 1);
	g.inserirVertice(3, 5, 1);
	g.inserirVertice(3, 6, 1);
  g.inserirVertice(6, 6, 1);
	g.mostra();
}
int main(int argc, char const *argv[]) {
	int n, m;
	n=6;
	Grafo<int> g(n);
	testaGrafo(g);
	return 0;
}
