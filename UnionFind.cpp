#include "UnionFind.h"

int UnionFind::procurar(int p) {
    while (p != this->conjuntos[p]) {
        p = this->conjuntos[p];
    }
    return p;
}

bool UnionFind::conectados(int p, int q) {
    return (this->procurar(p) == this->procurar(q));
}

void UnionFind::uniao(int p, int q) {
    int raizP = this->procurar(p);
    int raizQ = this->procurar(q);

    if (raizP == raizQ) { return; }

    this->conjuntos[raizP] = raizQ;
    this->tamanho--;
}
