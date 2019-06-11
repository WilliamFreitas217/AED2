#include <iostream>
using namespace std;
enum Direcao {direita, esquerda};
enum Estado {ativo, desativado};

template <class Tipo>
void troca(Tipo &itemA, Tipo &itemB){
    Tipo tmp = itemA;
    itemA =itemB;
    itemB=tmp;
}

int fatorial(int n){
    int fat=1;
    for(int i=1; i<=n; i++){
        fat*=i;
    }
    return fat;
}

int maiorElemento(int *vetor, int tam){
    int maior = vetor[1];
    for(int i=2; i<=tam; i++){
        if(maior<vetor[i]){
            maior = vetor[i];
        }
    }
    return maior;
}

template <class Tipo>
void print(Tipo *vetor, int tam){
    for(int i=1; i<=tam; i++){
        cout<<vetor[i]<<" ";
    }
    cout<<endl;
}

template <class Tipo>
void printar(Tipo *vetor, int tam){
    for(int i=1; i<=tam; i++){
        cout<<vetor[i]<<" ";
    }
    cout<<endl;
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
        cout<<"{";
        p->getItem();
        cout<<"}"<<endl;
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

class JhonsonTrotter{
private:
    Lista<int> *P;
    Estado *estados;
    Direcao *direcoes;
    int *vetorPermAtual;
    int tamDoVetorPerm;
    bool haMovel(int *vetor, int tam);
    int maior(int *vetor, int tam);
    void inverterSetas(int i, int *vetor, int tam);
public:
    JhonsonTrotter();
    JhonsonTrotter(int *N, int tam);
    Lista<int> *getP();
};

JhonsonTrotter::JhonsonTrotter(){
}

JhonsonTrotter::JhonsonTrotter(int *N, int tam){
    tamDoVetorPerm = tam;
    P = new Lista<int>[fatorial(tam)];
    estados = new Estado[maiorElemento(N, tam)+1];
    vetorPermAtual = new int[tam+1];
    direcoes = new Direcao[tam+1];
    for(int i=1; i<=tam;i++){
        estados[N[i]]=ativo;
        vetorPermAtual[i] = (N[i]);
        direcoes[i]=esquerda;
    }
    int k=0;
    // int permutacao(vetorPermAtual, tam);
    // // P[k].insere(permutacao);
    // print(vetorPermAtual, tam);
    print(vetorPermAtual, tam);
    while (haMovel(N, tam) && k<fatorial(tam)) {
        int i = maior(vetorPermAtual, tam);
        cout<<"["<<i<<"] = "<<vetorPermAtual[i]<<endl;
        if(i!=1){
            if(direcoes[vetorPermAtual[i]]==esquerda && estados[i]!=desativado){
                cout<<"sim1 ";
                troca(vetorPermAtual[i], vetorPermAtual[i-1]);
                if(i-1==1){
                    estados[vetorPermAtual[i-1]] = desativado;
                }
                print(vetorPermAtual, tam);
            }
            if(direcoes[vetorPermAtual[i]]==direita && estados[i]!=desativado){
                cout<<"sim2 ";
                troca(vetorPermAtual[i], vetorPermAtual[i+1]);
                if(i+1==tam){
                    estados[vetorPermAtual[i+1]] = desativado;
                }
                print(vetorPermAtual, tam);
            }
        }
        else{
            estados[i] = desativado;
        }
        inverterSetas(vetorPermAtual[i], vetorPermAtual, tam);
        k++;
    }
}

int JhonsonTrotter::maior(int *vetor, int tam){
    int k = vetor[1];
    int maior = 1;
    for(int i=2; i<=tam; i++){
        if(estados[maior]==desativado){
            k = vetor[i];
            maior = i;
        }
        else{
            break;
        }
    }

    for(int i=1; i<=tam; i++){
        if(k<vetor[i] && estados[i]!=desativado){
            k = vetor[i];
            maior = i;
        }
    }
    return maior;
}
void JhonsonTrotter::inverterSetas(int i, int *vetor, int tam){
    for(int k=1; k<=tam; k++){
        if(i<vetor[k]){
            if(direcoes[vetor[k]]==esquerda){
                direcoes[vetorPermAtual[k]]=(direita);
                estados[vetorPermAtual[k]]=ativo;
            }
            if(direcoes[vetor[k]]==direita){
                direcoes[vetorPermAtual[k]]=(esquerda);
                estados[vetorPermAtual[k]]=ativo;
            }
        }
    }
}

bool JhonsonTrotter::haMovel(int *vetor, int tam){
    for(int i=1; i<=tam; i++){
        if(estados[vetor[i]]==ativo){
            return true;
        }
    }
    return false;
}

Lista<int> *JhonsonTrotter::getP(){
    // cout<<fatorial(tamDoVetorPerm)<<endl;
    // cout<<tamDoVetorPerm<<endl;
    for(int i=1; i<=fatorial(tamDoVetorPerm); i++){
        P[i].mostra();
    }
    return P;
}


int main(int argc, char const *argv[]) {
    int *vetor;
    int tam=3;
    vetor = new int[tam+1];
    vetor[1]=1;
    vetor[2]=2;
    vetor[3]=3;
    // printar(vetor, 3);
    // troca(vetor[3], vetor[2]);
    // printar(vetor, 3);
    JhonsonTrotter *JT = new JhonsonTrotter(vetor, tam);
    // JT.getP();
    return 0;
}
