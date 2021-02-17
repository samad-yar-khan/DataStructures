#include <iostream>
using namespace std;
#include "linked_list.cpp"

void print (Node *head); //prints the entire linked list

int main(){

    Node n1(1);
    Node *head = &n1; //This is the head of the linked list and points to the first data member of linked list
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);

    // n1.next=&n2;
    // n2.next=&n3;
    // n3.next=&n4;
    // n4.next=&n5;
    print(head);

 return 0;
}

void print (Node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}