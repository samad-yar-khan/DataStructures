#include <iostream>
using namespace std;

template <typename T>

class Node{
    public:
    T data; //T type ka data legi ll
    Node <T> *next; //node , jisme t type ka data store hota ho uska ptr banaya

    //constructoe
    Node (T data) {
        this->data = data;
        next - NULL;
    }
};

template <typename T>  //we have to do this for evey class we create

class stack {
    Node <T> *head; // i have to specify kik my head ptr pts to a node which stores vaklues of typr T
    int size;

    public :

    //default constructor
    stack (){
        head = NULL;
        size =0;
    }

    int getsize (){
        return size;
    }

    bool is_empty (){
        return size == 0;
    }

    void push (T data){
        Node<T> *new_node = new Node <T> (data);
        new_node->next = head;
        head = new_node;
        size++;
    }

    T pop (){
        if(head == NULL){
            return 0;
        }

        T temp = head->data;
        Node<T>*del = head;
        head= head->next;
        delete del;
        size--;
        return temp;
    }

    T top(){
        if(head == NULL){
            return 0;
        }        

        return head->data;
    }
};