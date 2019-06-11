#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

#include "Grafo.h"
#include "Heap.h"
#include "Aresta.h"
#include "UnionFind.h"

using namespace std;

const bool DOENTE = true;
const bool SAUDAVEL = false;
const int NULO = -1;
const int INFINITO = numeric_limits<int>::max();
//----------------------------------------------------------------------------------------------------------------------
int particao(vector<Aresta> &v, int p, int r){
    Aresta x = v[p];
    Aresta tmp = v[r+1];
    v[r+1] = x;
    int i = p;
    int j = r+1;

    while(true){
        do{
            i = i+1;
        }while((v[i].getPeso() < x.getPeso()) && (i <= r+1));
        do{
            j = j-1;
        }while ((v[j].getPeso() > x.getPeso()) && (j >= p));

        if (i < j){
            Aresta aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        } else {
            Aresta aux = v[p];
            v[p] = v[j];
            v[j] = aux;
            v[r+1] = tmp;
            return j;
        }
    }
}

void quickSort(vector<Aresta> &v, int p, int r) {
    if (p < r){
        int q = particao(v, p, r);
        quickSort(v, p, q-1);
        quickSort(v, q+1, r);
    }
}

void quickSort(vector<Aresta> &v) {
    quickSort(v, 0, v.size()-1);
}

vector<string> leitura() {
    string entrada = "";
    char * entradaChar;
    vector<string> entradaSplit;

    getline(cin, entrada);
    entradaChar = strtok(&entrada[0], " ");
    while (entradaChar != nullptr) {
        string split(entradaChar);
        entradaSplit.push_back(split);
        entradaChar = strtok(nullptr, " ");
    }
    return entradaSplit;
}

Grafo<Grafo<bool>> lerCerebro() {
    vector<string> entrada;
    int ordemCerebro, tamanhoCerebro = NULO;

    entrada = leitura();
    ordemCerebro = stoi(entrada[0]);
    tamanhoCerebro = stoi(entrada[1]);

    Grafo<Grafo<bool>> cerebro(ordemCerebro);

    for (int i = 1; i <= tamanhoCerebro; i++){
        entrada = leitura();
        int u = stoi(entrada[0]);
        int v = stoi(entrada[1]);
        float w = stof(entrada[2]);

        cerebro.inserirAresta(u, v, w);
    }
    return cerebro;
}

void lerBlocos(Grafo<Grafo<bool>> &cerebro) {
    vector<string> entrada;
    int ordemCerebro = cerebro.getOrdem();

    for (int i = 1; i <= ordemCerebro; i++) {
        int ordemBloco, tamanhoBloco = NULO;
        vector<int> doentes;

        entrada = leitura();
        ordemBloco = stoi(entrada[0]);
        tamanhoBloco = stoi(entrada[1]);

        Grafo<bool> bloco(ordemBloco);

        entrada = leitura();
        if(entrada[0] == "0"){
            for (int j = 1; j <= tamanhoBloco; j++) {
                entrada = leitura();
                int u = stoi(entrada[0]);
                int v = stoi(entrada[1]);
                float w = stof(entrada[2]);

                bloco.inserirAresta(u, v, w);
            }
        }
        else{
            entrada = leitura();
            for (string x : entrada) {
                doentes.push_back(stoi(x));
            }
            for (int j = 1; j <= tamanhoBloco; j++) {
                entrada = leitura();
                int u = stoi(entrada[0]);
                int v = stoi(entrada[1]);
                float w = stof(entrada[2]);

                bloco.inserirAresta(u, v, w);
            }
        }

        if (doentes.size()== 0){
            for (int j = 1; j <= ordemBloco; j++){
                bloco.inserirItem(SAUDAVEL, j);
            }
        }
        else{
            int k = 0;
            for (int j = 1; j <= ordemBloco; j++) {
                if (j == doentes[k] && k < doentes.size()) {
                    bloco.inserirItem(DOENTE, j);
                } else {
                    bloco.inserirItem(SAUDAVEL, j);
                }
                k++;
            }
        }


        cerebro.inserirItem(bloco, i);

    }
}

vector<int> adjDeU(vector<float> aux) {
    vector<int> adjU;
    for (int i = 1; i < aux.size(); i++) {
        if (aux[i] != 0.0) {
            adjU.push_back(i);
        }
    }
    return adjU;
}

template <typename T>
vector<Vertice> Dijkstra(Grafo<T> grafo, int inicio) {
    Vertice Q[grafo.getOrdem()+1];
    vector<Vertice> S;
    vector<int> adjU;
    vector<float> *matriz = grafo.getMatriz();
    Heap prioridade;

    for (int i = 1; i <=grafo.getOrdem(); i++) {
        Q[i] = Vertice(INFINITO, NULO, i);
    }

    Q[inicio].setDistancia(0.0);
    prioridade.constroiHeap(Q, grafo.getOrdem());

    while (prioridade.getTamanhoHeap() > 0) {
        Vertice u = prioridade.extrairMenor(Q);
        S.push_back(u);

        adjU = adjDeU(matriz[u.getNumVertice()]);

        for (int x : adjU) {
            int pos = prioridade.posNoHeap(x);
            if (Q[pos].getDistancia() > u.getDistancia() + (matriz[u.getNumVertice()][Q[pos].getNumVertice()])) {

                float distancia = u.getDistancia() + (matriz[u.getNumVertice()][Q[pos].getNumVertice()]);
                Q[pos].setPredecessor(u.getNumVertice());

                prioridade.alterarChave(Q, pos, distancia);
            }
        }
    }
    return S;
}

template <typename T>
vector<Aresta> Kruskal(Grafo<T> grafo) {
    vector<Aresta> A;
    vector<Aresta> saida;
    UnionFind conjuntos(grafo.getOrdem());

    vector<float> *matriz = grafo.getMatriz();

    for (int i = 1; i <= grafo.getOrdem(); i++) {
        for (int j = 1; j <= grafo.getOrdem(); j++) {
            if (j > i && matriz[i][j] != 0.0) {
                A.push_back(Aresta(i, j, matriz[i][j]));
            }
        }
    }

    quickSort(A);

    while (A.size() > 0) {
        Aresta aux = A[0];
        A.erase(A.begin()+0);

        if (!conjuntos.conectados(aux.getU(), aux.getV())) {
            saida.push_back(aux);
            conjuntos.uniao(aux.getU(), aux.getV());
        }
    }

    return saida;

}
//----------------------------------------------------------------------------------------------------------------------
int main() {

    vector<string> entrada;
    Grafo<Grafo<bool>> cerebro;
    int inicio, fim = NULO;

    cerebro = lerCerebro();

    entrada = leitura();
    inicio = stoi(entrada[0]);
    fim = stoi(entrada[1]);

    lerBlocos(cerebro);

    vector<Vertice> resultD = Dijkstra(cerebro, inicio);

    //------------------------------------------------------------------------------------------------------------------

    vector<int> blocosV;
    int aux = fim;
    while (aux != NULO) {
        for (Vertice x : resultD) {
            if (aux == x.getNumVertice()) {
                blocosV.push_back(x.getNumVertice());
                aux = x.getPredecessor();
                break;
            }
        }
    }


    vector<Grafo<bool>> blocos;
    for (int x : blocosV) {
        Grafo<bool> bloco = cerebro.getItem(x);
        for (int i = 1; i <= bloco.getOrdem(); i++) {
            bool aux = bloco.getItem(i);
            if (aux) {
                blocos.push_back(bloco);
                break;
            }
        }
    }

    float saida = 0.0;

    for (Grafo<bool> x : blocos) {
        vector<Aresta> resultKruskal = Kruskal(x);

        for (Aresta y : resultKruskal) {
            saida += y.getPeso();
        }
    }

    cout << saida << endl;

    cout << "\n---------------------------------------------------------";

    return 0;
}
