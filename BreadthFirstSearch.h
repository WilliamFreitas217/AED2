#ifndef BreadthFirstSearch_h
#define BreadthFirstSearch_h
#include "AdjacentList.h"
#include <iostream>
using namespace std;
template<typename Type>
class BFS{
private:
  Graph<Type> * g;
  int * prevVertexArray;
  string * colorArray;
  int  distanceToSource;

public:
  BFS(int);
  void bfs(Graph<Type> *,int);
  void bfsMap(Graph<Type> *);
  Graph<Type> * getG();
  void setG(Graph<Type> * g);
  int * getPrevVertexArray();
  void setPrevVertexArray(int * prevVertexArray);
  string * getColorArray();
  void setColorArray(string * colorArray);
  int getDistanceToSource();
  void setDistanceToSource(int distanceToSource);
};
template<typename Type>
Graph<Type> * BFS<Type>::getG(){
  return g;
}
template<typename Type>
void BFS<Type>::setG(Graph<Type> * g){
  this->g = g;
}
template<typename Type>
int * BFS<Type>::getPrevVertexArray(){
  return prevVertexArray;
}
template<typename Type>
void BFS<Type>::setPrevVertexArray(int * prevVertexArray){
  this->prevVertexArray = prevVertexArray;
}
template<typename Type>
string * BFS<Type>::getColorArray(){
  return colorArray;
}
template<typename Type>
void BFS<Type>::setColorArray(string * colorArray){
  this->colorArray = colorArray;
}
template<typename Type>
int BFS<Type>::getDistanceToSource(){
  return distanceToSource;
}
template<typename Type>
void BFS<Type>::setDistanceToSource(int distanceToSource){
  this->distanceToSource = distanceToSource;
}

template<typename Type>
BFS<Type>::BFS(int order){
  g = new Graph<Type>(order);
  prevVertexArray = new int[g->getOrder()+1];
  colorArray = new string[g->getOrder()+1];
  distanceToSource = 0;
}

template<typename Type>
void BFS<Type>::bfs(Graph<Type> * g, int s){
  DynamicQueue<int> * q = new DynamicQueue<int>();
  for(int i = 1; i <= g->getOrder(); i++) colorArray[i] = "White";
  colorArray[s] = "Grey";
  distanceToSource = 0;
  q->enqueue(s);
  int u ;
  while(!q->emptyQueue()){
    u = q->getFront()->getNext()->getItem();
    Node<Vertex<Type>> * i= g->getAdjVertex()[u].getFirst()->getNext();
    q->dequeue();
    while(i != NULL){
      int aux = i->getItem().getIndex();
      if(colorArray[aux] == "White"){
        colorArray[aux] = "Grey";
        distanceToSource++;
        prevVertexArray[aux] = u;
        q->enqueue(aux);
      }
      i = i->getNext();
    }
    colorArray[u] = "Black";
  }
}

template<typename Type>
void BFS<Type>::bfsMap(Graph<Type> * g){
  cout << "<<Breadth First Search(BFS) >>" << endl;
  cout << "Previous = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << prevVertexArray[i] << " ";
  cout << "]"<<endl;
  cout << "Colors = [ ";
  for(int i = 1; i <= g->getOrder(); i++) cout << colorArray[i] << " ";
  cout << "]"<<endl;
  cout << "Distance to Source = [ "<< distanceToSource << " ]" << endl;

}
#endif
