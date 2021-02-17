#include <iostream>
using namespace std;

template <typename T>
class Node {
    public :

    T data ;
    Node<T> *next;

    Node (T data ){
        this->data  = data;
        this->next - NULL;
    }

};

template <typename T>
class Queue{
    private :

    Node <T>* head;
    Node <T>* tail;
    int size;

    public :

    Queue (){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(T element){
        
        //make a new node first
        Node<T>* new_node = new Node<T>(element);

        if (head == NULL){ //empty queue
            head = new_node;
            tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    int get_size (){
        return size;
    }

    bool is_empty (){
        return size == 0;
    }

    T front (){
        if (head == NULL){
            cout<<"Empty Queue !"<<endl;
            return 0;
        }
        else {
            return head->data;
        }
    }

    T dequeue (){
        if (head == NULL){
            cout<<"Empty Queue !"<<endl;
            return 0;
        }
        else {
            T del_data  = head ->data;
            Node<T>* del_node = head;
            head = head->next;
            delete del_node;
            size--;
            return del_data;
         }
    
    }
};