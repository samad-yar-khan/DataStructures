#include <iostream>
using namespace std;
#include "linked_list.cpp"

void del (Node* del); 
Node* take_input();
void print(Node *head);
void printIthNode(Node *head, int i);
int length(Node *head);
Node* insert_node (Node *head , int i , int data);



int main(){

Node *head = take_input();
print(head);


del(head);
}



Node* take_input(){
    cout<<"Enter data (to terminate input process enter -1 )- "<<"\n";//flaw in out ll is we cant put -1 in our ll
    int input;
    cin>>input;
    Node *head = NULL;
    Node *tail = NULL;

    while (input!=-1){
        Node* new_node = new Node (input);

        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }

        cin>>input;
    }
    return head;                                                 
    
}

void print (Node* head){
    while (head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int length(Node *head) {

    int len =0;
    while (head!=NULL){
        len++;
        head = head->next;
    }
    
    return len;
}



void printIthNode(Node *head, int i) {
 
	int l=0;
    Node*temp = head;
    while (temp!=NULL){
        l++;
        temp = temp->next;
    }
    
    if (i>l){
        return;
    }
    
    for(int k=0 ; k<i ;k++){
       head = head-> next;
    }
 	cout<<head->data<<"\n";
 }

 Node* insert_node (Node *head , int i , int data){
     Node* new_node = new Node (data);
     Node* temp = head;
     int count{0};
     //this helps me transverse the array and reach at my i-1th element
     
     if(i==0){                           //we need to make a differnet case for  0th index because if we dont
         new_node->next=head;            // the according to our next conditions loop mai ham ja nhi paynege 
         head=new_node;                  //and hamara leement 0 nahi balki 1 index pe ajayega 
         return head;

     }

     while (count < i-1 && temp!=nullptr){ //bascially kya hoga . if someone enter an index out of bound
         temp= temp->next;                 //our temp will eventually change to null , because tail ke next mai 
         count++;                          // null hoga which will get strored in temp and if we dont put this condition
     }  

     if(temp!=nullptr) {                     //we will rewach a point jaha null ka next acces hira hoga leading to
    new_node->next = temp->next;           //segmentation error
    temp->next = new_node;                  //even the further changed of linking the new node at thta position wont take place
       }                                    //if we have null in temp , which means out of bounds 
                 

    return head;
 }

 void del (Node* head){
     while (head!=nullptr){
        Node* temp=head->next;
        delete head;
        head=temp;
     }
 }

  