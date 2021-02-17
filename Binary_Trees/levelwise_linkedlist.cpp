/*
Level wise linkedlist
Send Feedback
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output format : Each level linked list is printed in new line (elements separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9
*/
#include <iostream>
using namespace std;
#include<queue>
#include<vector>
#include "BinaryTree.h"

template<typename T>
class node{
   public:
    T data;
    node<T>* next;

    node(T data){
        this->data= data;
        this->next=NULL;
    }

    ~node(){
        if(this->next != NULL){
            delete this->next;
        }
    }
};

void print_level_wise(BinaryTreeNode<int> *root) {
   
	//base case
    
    if(root==NULL){
        return;
    }
    
    queue <BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    
    while(pending_nodes.size()!=0){
        BinaryTreeNode<int> * front = pending_nodes.front();
        pending_nodes.pop();
        
        cout<<front->data<<":";
        
        if(front->left!=NULL){
            cout<<"L:"<<front->left->data;
            pending_nodes.push(front->left);
        }else{
            cout<<"L:  ";
        }
        
        if(front->right!=NULL){
            cout<<",R:"<<front->right->data;
            pending_nodes.push(front->right);
        }else{
            cout<<",R:  ";
        }
        cout<<endl;
    }
}

BinaryTreeNode<int>* take_input_levelwise(){
    int root_data;
    cout<<"Enter root data(-1 for no data) - ";
    cin>>root_data;
    if(root_data == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode <int>(root_data);
    queue <BinaryTreeNode<int>*> pending_nodes ; //will contain nodes whos children hasnt been set

    pending_nodes.push(root);

    while (pending_nodes.size()!=0)
    {
      BinaryTreeNode <int>* front = pending_nodes.front();
      pending_nodes.pop();
      
      cout<<"Enter left child of "<<front->data<<endl;
      int left_child {};
      cin>>left_child;
      if(left_child!=-1){
        BinaryTreeNode<int>* left = new BinaryTreeNode<int>(left_child);
        front->left = left;
        pending_nodes.push(left);
      }

      cout<<"Enter right child of "<<front->data<<endl;
      int right_child {};
      cin>>right_child;
      if(right_child!=-1){
        BinaryTreeNode<int>* right = new BinaryTreeNode<int>(right_child);
        front->right = right;
        pending_nodes.push(right);
      }

    }
    return root;
}

template<typename T>
void printLL(node<T>* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }   
    cout<<"\n";
}
/*
we have a vector to store the head of each ll
we have out queue to maintain the 
we have our linked lists

*/
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
        // Write your code here
	 vector<node<int>*> nodes;
    if(root==NULL){
     return  nodes;   
    }

    queue<BinaryTreeNode<int>*> pending_nodes ; // will contain those nodes which are yet to be stires on the linked list
   // we push root followed by pending nodes in the queue
    pending_nodes.push(root); //we will fill out que with root
    pending_nodes.push(NULL); // null will indicate the end of a level
    


    while (!pending_nodes.empty()){
        BinaryTreeNode<int>* front = pending_nodes.front();
        
        //we make our root the head of our linked list by storin its data in anode
        pending_nodes.pop();

        //push its children on to the queue (enqueue)
        if(front->left!=NULL){
        pending_nodes.push(front->left);
        }
        if(front->right!=NULL){
            pending_nodes.push(front->right);
        }

        //store the head in our ll and make  a tail
        node<int>* head= new node<int>(front->data);
        node<int>* tail=head;
        nodes.push_back(head);


        // theres anull at the end of each level , we make nodes and join em to or tail till we reach
        //our null
        while(pending_nodes.front() != NULL){
            BinaryTreeNode<int>* temp = pending_nodes.front();
            pending_nodes.pop();
            tail->next = new node<int> (temp->data);
            tail = tail->next;
             if(temp->left!=NULL){
                pending_nodes.push(temp->left);
                }
            if(temp->right!=NULL){
                pending_nodes.push(temp->right);
            }
        }
        //pop out the null
        pending_nodes.pop();

        //now this is a new levele to push a null  at its end and marks the ending of the next levle
        //provided the queue is not empty
        if(pending_nodes.size()!=0){
            pending_nodes.push(NULL);
        }
	}

	return nodes;
}



int main(){
    BinaryTreeNode<int>* root =  take_input_levelwise();
    print_level_wise(root);

    vector <node<int>*> lls= createLLForEachLevel(root);

    for (auto l:lls){
        printLL(l);
    }

    for (auto l:lls){
        delete l;
    }

    delete root;
}
