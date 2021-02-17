#include <iostream>
using namespace std;

class Node {
    public :
    
    int data; //This data member stores data of current node
    Node *next ; //This data member stores the adress of next node , we can acess next node using this data member
    static Node *tail;
    //Parameterized constructor
    Node (int value){
        this->data =value;
        next=nullptr;
        if(tail!=nullptr){
            tail->next=this; //basically apne tail wale nod eke next mai iska adress daldiya . onlyy if its not head node
        }
        tail=this;
    }
};

Node* Node::tail = nullptr;
//Tried to make a linked list class such that5 every oder node i add gets 
//linked to the previous class using a static member tail 
//now this method is good when you have to use a single linkjed list 
//but we cant use two diffwerent linked list this way
//evene if we make two different linked list the will be connected somehow by this 
//statric variable tail as it cnnects evry simgle linked liost we add, be it dynamic or static
//this is because it is a property of the class now and the tail operated as one for all nodes
//so every node we create will be connected without extra effort
// but to make node not automatiaclly link to our new node , we can change the class variable tail to null
//before we want to declare a new list , so each time we wish that two nodes are not joined we will ahve 
// to manually change our static class member tail to null
//warna no matter how many node you create , they wil get automatically connecting leaving us with onl one
// list for a program unless we manually change the tail to null before declaringa a new class
// may lead to errors if we dont manually set tail to nullptrs before declearion of a new list 
//but may also be usefull 
//will be continued