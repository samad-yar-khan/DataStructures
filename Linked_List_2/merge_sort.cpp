#include <iostream>
using namespace std;
#include "linked_list.cpp"

void del (Node* del);  //deletes all dynamic data
Node* take_input();    //takes your input O(n)
void print(Node *head);  //prints your linked list
int length(Node *head);   //returns length of linked list
Node * mergeSort(Node *head);  //Sorts LL
Node * mergeTwoLLs(Node *head1, Node *head2);  //merges 2 sorted ll such that merges ll is sorted
Node * midpoint_linkedlist(Node *head); //gives middle element of linked list



int main(){
    cout<<"Enter linked list - ";
    Node *head = take_input ();

    print(head);


    head = mergeSort(head);
    cout<<"\nSorted Linked List \n";
    print(head);

    
    del(head);//frees up my memory
return 0;

}


Node * midpoint_linkedlist(Node *head)
{
    // Write your code here
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast!=NULL && fast->next != NULL){
        slow=slow->next;
        fast=(fast->next)->next;
    }
    
    return slow;

}

Node * mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    
    Node *h1=head1;
    Node * h2=head2;;
    Node *FH=NULL;
    Node *FT=NULL;
    
	while(h1!=NULL&&h2!=NULL){
        if(FH==NULL){
            if(h1->data <=  h2->data){
                FH=h1;
                FT=h1;
                h1=h1->next;
            }
            else{
                FH=h2;
                FT=h2;
                h2=h2->next;
            }
        }
        else{
           if( h1->data <= h2-> data ){
               FT->next = h1 ;
               FT=h1;
               h1=h1->next;
           }
            else{
               FT->next = h2 ;
               FT=h2;
               h2=h2->next;
            }
        }
    }
    
	if(h1!=NULL){
        FT->next=h1;
    }
    
    if(h2!=NULL){
        FT->next=h2;
    }
    
    return FH;
    
    
}



Node * mergeSort(Node *head) {
    
    //basse 
    if(head->next ==NULL || head==NULL){
        return head;
    }
    
    Node * mid = midpoint_linkedlist(head); //mid pt mil gya
    
    Node * head2 = mid->next; // i ll store the next
    
     mid->next = NULL; //now i ll cut off the linjked klist from the mid and now we heave two linked list
    
    //induction hypothesis
    head = mergeSort (head); //assuming it ll sort our ll fo us
    
    head2 = mergeSort (head2);
    
    //induction step
    Node *head_sorted = mergeTwoLLs(head, head2) ;  //merging the two sorted ll
    
    return head_sorted ;
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

void del (Node* head){
     while (head!=nullptr){
        Node* temp=head->next;
        delete head;
        head=temp;
     }
}