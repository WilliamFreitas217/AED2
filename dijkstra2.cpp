#include <iostream>
using namespace std;
template <class Tipo>
class FilaDePrioridade{
private:
    int tamHeap;
    Tipo *vetor;
    int pai(int i);
    int esq(int i);
    int dir(int i);
public:
    Tipo extrairMin();
    void decrescerMin(int i, Tipo item);
    void insere(Tipo item);
    void deletar(int i);
    void mostra();
    int getTamHeap();
}
