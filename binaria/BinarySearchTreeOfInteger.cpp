#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "BinarySearchTreeOfInteger.h"

BinarySearchTreeOfInteger::BinarySearchTreeOfInteger() {
    root = NULL;
    count = 0;
}

/* Verifica se a arvore esta vazia ou nao */
bool BinarySearchTreeOfInteger::isEmpty() {
    return (root == NULL);
}

/* Retorna o total de elementos da arvore. */
int BinarySearchTreeOfInteger::size() {
    return count;
}

/* Retorna o elemento armazenado na raiz da arvore. */
int BinarySearchTreeOfInteger::getRoot() {
    if (isEmpty()) {
        throw 0;
    }
    return root->element;
}


/* Insere o elemento na arvore. */
void BinarySearchTreeOfInteger::add(int element) {
    root = add(root, element, NULL);
    count++;
}
NodoAB* BinarySearchTreeOfInteger::add(NodoAB* nodo, int element, NodoAB* father)
{
    if (nodo == NULL) // Encontrou o lugar onde deve ser inserido
    {
        NodoAB* aux = new NodoAB(element);
        aux->father = father;
        return aux;
    }
    
    // Se elemento eh maior que o nodo atual, entao insere na sub-árvore da direita
    if (element > nodo->element) {
        nodo->right = add(nodo->right, element, nodo);
    }
    else {
        nodo->left = add(nodo->left, element, nodo);
    }
    
    return nodo;
}

// Metodo privado que procura por element a partir de n
// e retorna a referencia para o nodo no qual elem esta
// armazenado.
NodoAB* BinarySearchTreeOfInteger::searchNodeRef(int element, NodoAB *nodo) {
    
    if (nodo == NULL) // não achou!
        return NULL;
    
    if (nodo->element == element) // achou!
        return nodo;
    
    if (element < nodo->element) // Se o elemento buscado é menor que o nodo atual
        return searchNodeRef (element, nodo->left); // então, busca à esquerda
    else
        return searchNodeRef (element, nodo->right); // senão, busca à direita
    
    return NULL;
}

/* Verifica se element esta ou nao armazenado na arvore. */
bool BinarySearchTreeOfInteger::contains(int elem) {
   NodoAB *nAux = searchNodeRef(elem, root);
   return (nAux != NULL);
}

void BinarySearchTreeOfInteger::print(){
    print(0, root);
    return;
}

void BinarySearchTreeOfInteger::print(int height, NodoAB *aux){
    string tracinhos;
    for(int i = 0; i < height; i++){
        tracinhos.append("-");
    }
    if(aux != NULL)
        cout << tracinhos << " " << aux->element << endl;
    else {
        cout << tracinhos << " null" << endl;
        return;
    }
    print(height+1, aux->left);
    print(height+1, aux->right);
    return;
}

NodoAB* BinarySearchTreeOfInteger::remove(int element, NodoAB *raiz) {
    if(raiz == NULL)
        return raiz;
    else if(raiz->element > element)
        raiz->left = remove(element, raiz->left);
    else if(raiz->element < element)
        raiz->right = remove(element, raiz->right);
    else {
        //caso 1 = sem filhos
        if(raiz->left == NULL && raiz->right == NULL) {
            delete raiz;
            count--;
            return NULL;
        }
        //caso 2 = nodos com 1 filho
        else if(raiz->left == NULL) {
            NodoAB* temp = raiz;
            raiz = raiz->right;
            count--;
            delete temp;
        }
        else if(raiz->right == NULL) {
            NodoAB* temp = raiz;
            raiz = raiz->left;
            count--;
            delete temp;
        }
        //caso 3 = nodos com 2 filhos
        else{
            NodoAB* maiorDaEsquerda = raiz->left;
            while(maiorDaEsquerda->right != NULL) {
                maiorDaEsquerda = maiorDaEsquerda->right;
            }
            raiz->element = maiorDaEsquerda->element;
            raiz->left = remove(raiz->element,raiz->left);
        }
    }
    return raiz;
}

/* Remove element da arvore. */
bool BinarySearchTreeOfInteger::remove(int element) {
    int countInicial = count;
    remove(element,root);
    return countInicial != count;
    
}
