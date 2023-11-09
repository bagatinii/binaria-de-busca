#ifndef _ABP
#define _ABP
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

#include "NodoAB.h"

class BinarySearchTreeOfInteger
{
private:
  NodoAB *root;
  int count;

  void print(int height, NodoAB *aux);
  NodoAB* searchNodeRef(int elem, NodoAB *n);
  NodoAB* add(NodoAB* nodo, int element, NodoAB* father);
  NodoAB* remove(int element, NodoAB *raiz);
  
public:
    BinarySearchTreeOfInteger();
    void print();
    bool isEmpty();
    int size();
    int getRoot();
    void add(int element);
    bool contains(int elem);
    bool remove(int element);
};
#endif
