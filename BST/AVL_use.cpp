#include<iostream>
using namespace std;
#include "AVLTREE.h"

int main(){
    BST b1;
    b1.insert(21);
    b1.insert(26);
    b1.insert(30);
    b1.insert(9);
    b1.insert(4);
    b1.insert(14);
    b1.insert(28);
    b1.insert(18);
    
    b1.printTree();
    
    cout<<"_____________"<<endl;
    b1.printTree();
    
}