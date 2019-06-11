class Vertice {
private:
    float distancia;
    int predecessor;
    int numVertice;

public:
    Vertice(){}
    Vertice(float pDistacia, int pPredecessor, int pNumVertice) {
        this->distancia = pDistacia;
        this->predecessor = pPredecessor;
        this->numVertice = pNumVertice;
    }

    float getDistancia() { return this->distancia; }
    void setDistancia(float pDistancia) { this->distancia = pDistancia; }
    int getPredecessor() { return this->predecessor; };
    void setPredecessor(int pPredecessor) { this->predecessor = pPredecessor; }
    int getNumVertice() { return this->numVertice; }
    void setNumVertice(int pNumVertice) { this->numVertice = pNumVertice; }
};
