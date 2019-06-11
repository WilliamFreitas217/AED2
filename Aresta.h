#ifndef NANOROBOSCEREBRAIS_ARESTA_H
#define NANOROBOSCEREBRAIS_ARESTA_H


class Aresta {
private:
    int u, v;
    float peso;

public:
    Aresta() {}
    Aresta(int pU, int pV, float pPeso) {
        this->u = pU;
        this->v = pV;
        this->peso = pPeso;
    }

    int getU() { return this->u; }
    int getV() { return this->v; }
    float getPeso() { return this->peso; }

};


#endif //NANOROBOSCEREBRAIS_ARESTA_H
