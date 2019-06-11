#include "Heap.h"

int Heap::getTamanhoHeap() { return this->tamanhoHeap; }

void Heap::troca(Vertice *v, int i, int j) {
    Vertice vAux = v[i];
    v[i] = v[j];
    v[j] = vAux;

    int aux = this->posParaVert[i];
    this->posParaVert[i] = this->posParaVert[j];
    this->posParaVert[j] = aux;

    aux = this->vertParaPos[this->posParaVert[i]];
    this->vertParaPos[this->posParaVert[i]] = this->vertParaPos[this->posParaVert[j]];
    this->vertParaPos[this->posParaVert[j]] = aux;
}

void Heap::heapfica(Vertice *v, int i) {
    int esq = esquerda(i);
    int dir = direita(i);
    int menor;

    if (esq <= this->tamanhoHeap && (v[esq].getDistancia() < v[i].getDistancia())) {
        menor = esq;
    } else {
        menor = i;
    }

    if (dir <= this->tamanhoHeap && (v[dir].getDistancia() < v[menor].getDistancia())) {
        menor = dir;
    }

    if (menor != i) {
        this->troca(v, i, menor);
        this->heapfica(v, menor);
    }

}

void Heap::constroiHeap(Vertice *v, int pTamArray) {
    this->tamArray = pTamArray;
    this->tamanhoHeap = this->tamArray;

    this->vertParaPos = new int[this->tamArray+1];
    this->posParaVert = new int[this->tamArray+1];

    for (int i = 0; i <= this->tamArray; i++) {
        this->vertParaPos[i] = i;
        this->posParaVert[i] = i;
    }

    for (int i = floor(this->tamArray/2); i > 0; i--) {
        this->heapfica(v, i);
    }
}

Vertice Heap::extrairMenor(Vertice *v) {

    Vertice menor = v[1];
    v[1] = v[this->tamanhoHeap];

    int vert = this->posParaVert[this->tamanhoHeap];
    this->vertParaPos[vert] = 1;
    this->posParaVert[1] = vert;

    this->tamanhoHeap--;

    this->heapfica(v, 1);

    return menor;
}

void Heap::alterarChave(Vertice *v, int vert, float peso) {
    v[vert].setDistancia(peso);

    while(vert > 1 && v[pai(vert)].getDistancia() > v[vert].getDistancia()) {
        this->troca(v, vert, pai(vert));
        vert = pai(vert);
    }
}

int Heap::posNoHeap(int vertice) { return this->vertParaPos[vertice]; }
