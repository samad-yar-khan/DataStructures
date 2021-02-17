#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node *next;

    Node (int data){
        this->data = data;
        next = NULL;
    }

    ~Node (){
        // delete  next;
        cout<<"DECONSTRUCTOR\n";
    }
};
