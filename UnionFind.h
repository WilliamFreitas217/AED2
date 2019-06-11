#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
private:
    vector<int> conjuntos;
    unsigned int tamanho;

public:
    UnionFind(unsigned int pTamanho) {
        this->tamanho = pTamanho;
        this->conjuntos.resize(tamanho+1);
        for (unsigned int i = 0; i < this->conjuntos.size(); i++){
            this->conjuntos[i] = i;
        }
    }

    int procurar(int);
    bool conectados(int, int);
    void uniao(int, int);

};
