#include <iostream>

using namespace std;

#include "BinarySearchTreeOfInteger.h"

int main(){
    BinarySearchTreeOfInteger abb;
    abb.add(2);
    abb.add(9);
    abb.add(11);
    abb.add(3);
    abb.add(20);
    abb.add(13);
    abb.add(38);
    abb.print();
    
    int rem = 20;
    cout << "removendo nodo" << rem << ": " << abb.remove(rem) << endl;

    abb.print();
}
