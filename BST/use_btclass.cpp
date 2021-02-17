#include<iostream>
using namespace std;
#include "BST.h"

int main(){
    BST b1;
    b1.insert(10);
    b1.insert(20);
    b1.insert(30);
    b1.insert(40);
    //b1.insert(50);
    cout<<"_____________"<<endl;
    b1.printTree();
    b1.deleteData(10);
    cout<<"_____________"<<endl;
    b1.printTree();
    
}

