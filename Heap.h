#include <iostream>
#include <vector>
#include <math.h>
#include "Vertice.h"
using namespace std;

class Heap {
private:
    int tamanhoHeap, tamArray;
    int * posParaVert, * vertParaPos;

    int esquerda(int i) { return i * 2; }

    int direita(int i) { return ((i * 2) + 1); }

    int pai(int i) { return floor(i / 2); }

    void troca(Vertice *, int, int);

public:
    int getTamanhoHeap();

    void heapfica(Vertice *, int);

    void constroiHeap(Vertice *, int);

    Vertice extrairMenor(Vertice *);

    void alterarChave(Vertice *, int, float);

    int posNoHeap(int);

};
