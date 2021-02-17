//a different approach to reverse ll 
//here we make a different class so we can return our tail and head from the same function
//so that we dont have to do it iteratively

//we see two more methods 
#include <iostream>
using namespace std;
#include "linked_list.cpp"

// class Node{
//     public:

//     int data;
//     Node* next;

//     //default constructor pareameterized
//     Node(int data) {
//         this->data = data;
//         next =NULL;
//     }

//     ~Node(){
//         cout<<"deconstructor called!"<<endl;
//     }
// };1
class pr{
    public : 

    Node*head;
    Node*tail;

};

void print (Node * head);
Node *take_input ();
void del (Node *head );
Node * reverse_itr(Node*head); //iterative method for reversing LL
Node * reverse_1 (Node *head); 
pr reverse_p (Node *head);
Node *reverse_best (Node *head); //best recursive method for reversing ll o(n)

int main( ) {
    Node *head = take_input() ;
    print(head);

    //head = reverse_itr (head);  //iterative
    //head = reverse_best(head); //recursive 
    head=reverse_1(head);
    print(head);

    del(head);
}



pr reverse_p (Node *head){

    //base case
    if(head == NULL || head->next == NULL){
        pr my_output ;
        my_output.head = head;
        my_output.tail = head;

        return my_output;
    }

    //IH we assum e this will give us our reversed ll whose head is stored in head of small_oytput and itss tail in tail of small_output
    pr small_output = reverse_p(head->next);
    small_output.tail->next = head;
    head->next = NULL;

    pr my_output ;
    my_output.head = small_output.head;
    my_output.tail = head;

    return my_output;     


}
Node * reverse_1 (Node *head){
    return reverse_p (head).head ;
}


 
Node * reverse_itr(Node*head){ 

    Node * prev = NULL;
    Node *curr = head;
    Node *next_n =head->next;

    while (curr!=NULL){
        curr->next = prev;
        prev = curr;
        curr = next_n;
        if(curr == NULL ){
            break;
        }
        next_n = next_n->next;
    }

    return prev ;
}


Node *reverse_best (Node *head){
    //base case 
    if( head->next == NULL || head == NULL){
        return head;
    }
    //IH 
    //Assume that this we will bring us the smaller reversed linked list
    
    //induction step
    
    Node *small_output = reverse_best (head->next);
    //now the tail of this reversed linked list is in the next of my head 
    //ye connextion break nhi hua
    //ab mujhe is tail ke next mai apne head dalna hai
    //mera node end mai chala gya
    Node* tail = head->next;
    tail ->next = head;
    head->next =NULL;

    return small_output;
}

void print (Node * head) {
    while (head != NULL ){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}


Node *take_input (){
    cout<<"Enter elements (to terminate the input function enter -1)\n";
    Node *head = NULL;
    Node *tail = NULL;

    int input = 0;
    cin>>input;

    while (input != -1)
    {
        Node *new_node = new Node (input);
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail=new_node;
        }

        cin>>input;
    }

    return head;
}

void del (Node *head ){
    Node* temp=head;
    Node * next =NULL;

    while (temp != NULL){
        next = temp->next;
        delete temp;
        temp = next;
    }

  
}