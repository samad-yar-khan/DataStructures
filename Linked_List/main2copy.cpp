#include <iostream>
using namespace std;
#include "linked_list.cpp"

void del (Node* del); 
Node* take_input();
void print(Node *head);
void printIthNode(Node *head, int i);
int length(Node *head);
Node* insert_node (Node *head , int i , int data);
Node* del_ith(Node*head , int elment);
int search_node(Node*head , int n);

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

int main(){

Node *head = take_input();
print(head);

   

 int a{0};
 
while(a!=-1){
    cout<<1<<" Insert Node at ith pos"<<endl;
    cout<<2<<" Print ith node "<<endl;
    cout<<3<<" Delete ith node "<<endl;
    cout<<5<<" Reverse List "<<endl;
    cout<<6<<" Print  "<<endl;
    cout<<7<<" Search a node "<<endl;
    cout<<-1<<" Quit "<<endl;

    cout<<"Enter input :";
    std::cin>>a;
    switch(a){
        case 1 : {
            cout<<"Index and element :";
            int in , el ;
            cin>>in>>el;
            head = insert_node(head , in , el);
            break;
            }
        case 2 : {
            cout<<"Enter i";
            int ith;
            cin>>ith;
            printIthNode(head , ith);
            break;
        }
        
        case 3 : {cout<<"Enter i";
            int ith;
            cin>>ith;
            head = del_ith(head , ith);
            break;
            }
        case 5 : {
            head = reverse_best(head);
            break;
        }
        case 6 : {
            print(head);
            break;
        }
        case 7:{
            cout<<"Enter the node to be serached :";
            int x{0};
            cin>>x;
            int npos = search_node(head  , x);
            if(npos == -1){
                cout<<"Node not found !\n";
            }else{
                cout<<"Node is at position - "<<npos<<endl;
            }
            break;
        }
        default:
                cout<<"Quit"<<endl;

        }

    cout<<"-1 to quit else enter any value to contnue \n";
    std::cin>>a;
}
// switch 
// int element ,index;
// cin>>element;
// cout<<"\nAt what element do you want to enter this ? - ";
// cin>>index;
// head = insert_node (head,index,element);
// print (head);
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

Node* del_ith(Node*head , int elment){
     
    int i = 1;

    if(elment == 1){
        Node* temp = head->next;
        delete head;
        head = temp;
        return head;
    }

    Node* temp = head;

    while(i < elment-1 && temp!=nullptr){
        
        temp = temp->next;
        i++;

    }

    Node* temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;
    delete temp2;

    return head;
 }

 int search_node(Node*head , int n){

     Node*temp = head;
    int i = 1;
    while(temp!=nullptr && temp !=NULL){
        
        if(temp->data == n){
            return i;
        }else{

            i++;
            temp=temp->next;
        }

    }

    // cout<<"\nNode not found !\n";
    return -1;


 }