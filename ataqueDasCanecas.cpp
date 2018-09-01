#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Dado{
private:
    int numNaFace;
public:
    Dado();
    int sorteia();
};
Dado::Dado(){
}
int Dado::sorteia(){
    srand(time(0));
    numNaFace = rand()%6+1;
    return numNaFace;
}
class Caneca{
private:
    Dado dados[3];
    int valor;
public:
    Caneca();
    int lanca();
    int getValor();
    void setValor(int valor);
};
Caneca::Caneca(){
}
int Caneca::lanca(){
    valor = 0;
    valor += dados[0].sorteia();
    valor += dados[1].sorteia();
    valor += dados[2].sorteia();
    return valor;
}
int Caneca::getValor(){
    return valor;
}
void Caneca::setValor(int valor){
    this->valor = valor;
}

class Jogador{
private:
    string nome;
    int pontos;
    Caneca caneca;
public:
    Jogador();
    Jogador(string nome);
    string getNome();
    int getPontos();
    void setNome(string nome);
    void setPontos(int num);
    int joga();
    void guardarDados();
};
Jogador::Jogador(){
    this->pontos = 0;
}
Jogador::Jogador(string nome){
    this->nome = nome;
    this->pontos = 0;
}
string Jogador::getNome(){
    return nome;
}
int Jogador::getPontos(){
    return pontos;
}
void Jogador::setNome(string nome){
    this->nome = nome;
}
void Jogador::setPontos(int num){
    this->pontos = num;
}
int Jogador::joga(){
    int pontos = caneca.lanca();
    return pontos;
}
void Jogador::guardarDados(){
    caneca.setValor(0);
}
bool haVencedor(Jogador *jogadores, int nJogadores){
    for(int i=0; i<nJogadores; i++){
        if(jogadores[i].getPontos()>=53){
            cout<<"Vencedor: "<<jogadores[i].getNome()<<" || Pontos: "<<jogadores[i].getPontos();
            return true;
        }

    }
    return false;
}
int main(int argc, char const *argv[]) {
    int nJogadores;
    cout<<"Quantos jogadores?"<<endl;
    cin>>nJogadores;
    Jogador jogadores[nJogadores];
    for(int i=0; i<nJogadores; i++){
        cout<<"Nome do jogador numero "<<i+1<<": "<<endl;
        string nome;
        cin>>nome;
        jogadores[i].setNome(nome);
    }
    while(haVencedor(jogadores, nJogadores)!=true){
        cout<<"Qual valor?"<<endl;
        int valor;
        //cin>>valor;
        srand(time(NULL));
        valor = rand()%18+1;
        if(valor==jogadores[1].joga()){
            jogadores[0].setPontos(jogadores[0].getPontos()+valor);
            cout<<"Jogador 1 acertou"<<endl;
            cout<<"Pontos do jogador 1: "<<jogadores[0].getPontos()<<endl;
        }
        else{
            cout<<"Pontos do jogador 1: "<<jogadores[0].getPontos()<<endl;
            cout<<"Jogador 1 errou!"<<endl;
        }
        jogadores[1].guardarDados();
        if(haVencedor(jogadores, nJogadores)){
            break;
        }
        int valorMq;
        srand(time(NULL));
        valorMq = rand()%18+1;
        if(valorMq==jogadores[0].joga()){
            jogadores[1].setPontos(jogadores[1].getPontos()+valor);
            cout<<"Jogador 2 acertou"<<endl;
            cout<<"Pontos do jogador 2: "<<jogadores[1].getPontos()<<endl;
        }
        else{
            cout<<"Pontos do jogador 2: "<<jogadores[1].getPontos()<<endl;
            cout<<"Jogador 2 errou!"<<endl;
        }
        jogadores[0].guardarDados();
        if(haVencedor(jogadores, nJogadores)){
            break;
        }
        cout<<"-----------------------------------------------------------------------------------------------"<<endl;
        cout<<"Fim de rodada"<<endl;
        cout<<"Valor apostado do jogador 1: "<<valor<<" ||| Valor apostado do jogador 2: "<<valorMq<<endl;
        cout<<"Total de Pontos do jogador 1 "<<jogadores[0].getPontos()<<endl;
        cout<<"Total de Pontos do jogador 2 "<<jogadores[1].getPontos()<<endl;
        cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    }
    return 0;
}
