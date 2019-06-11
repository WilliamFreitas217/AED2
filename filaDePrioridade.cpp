class FilaDePrioridade{
private:
    int tamHeap;
    Par *vetor;
    int pai(int i);
    int esq(int i);
    int dir(int i);
public:
    FilaDePrioridade();
    void FilaDePrioridade(int tam);
    void heapficaMin(int i);
    Par minimo();
    void decrescerMin(int i, Par);
    void insere(Par);
    Tipo extrairMin();
    int getTamHeap();
    bool verificar(int chaveDoVertice);
	void mostra();
};


FilaDePrioridade::FilaDePrioridade(){
}

FilaDePrioridade::FilaDePrioridade(int tam){
    this->tamHeap = 0;
    vetor = new Par[tam+1];
}

void FilaDePrioridade::heapficaMin(int i){
    int l = esq(i), r =dir(i);
    int menor = 1;
    if(l<=tamHeap && vetor[l]<vetor[i]){
        menor =l;
    }
    else{
        menor = i;
    }
    if(r<=tamHeap && vetor[r]<vetor[menor]){
        menor = r;
    }
    if(menor != i){
        troca(vetor[i], vetor[menor]);
        heapficaMin(menor);
    }
}

void FilaDePrioridade::insere(Par par){
	tamHeap++;
    v[tamHeap](par.getVertice(), par.getPesoAresta());
    decrescerMin(tamHeap, par);
}


Par FilaDePrioridade::minimo(){
    return vetor[1];
}

Par FilaDePrioridade::extrairMin(){
 	Par minimo = vetor[1];
    vetor[1] = v[tamHeap];
    tamHeap--;
    heapficaMin(1);
	return minimo;
}

void FilaDePrioridade::mostra(){
	for(int i=1; i<tamHeap; i++){
        cout<<"Vertice: "<<vetor[i].getVertice()<<" Aresta: "<<vetor[i].getPesoAresta()<<endl;
    }
}


void FilaDePrioridade::decrescerMin(int i, Par par){
    if(par.getVertice()>v[i].getVertice()){
        cout<<"valor inferior \n ACAO NAO PERMITIDA"<<endl;
    }
    v[i].setVertice(par.getVertice());
    v[i].setPesoAresta(par.getPesoAresta());
    while (i>1 && v[i/2].getVertice()>v[i].getVertice()) {
        troca(v[i/2], v[i]);
        i = i/2;
    }
}

bool FilaDePrioridade::verificar(int chaveDoVertice){
    for(int i=1; i<tamHeap; i++){
        if(vetor[i].getVertice()==chaveDoVertice){
            return true;
        }
    }
    return false;
}

int FilaDePrioridade::getTamHeap(){
    return tamHeap;
}
