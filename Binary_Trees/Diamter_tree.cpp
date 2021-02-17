#include <iostream>
#include<queue>

using namespace std;
#include"BinaryTree.h"

class Pair{
  public:
    int height;
    int diameter;

    Pair(){
        height =0;
        diameter =0;
    }

};

BinaryTreeNode<int>* take_input_levelwise();
void print_level_wise(BinaryTreeNode<int> *root);
Pair * ht_d(BinaryTreeNode <int>* root ){
    if(root==NULL){
        Pair * p= new Pair;
        return p;
    }


    Pair *left = ht_d(root->left);
    Pair *right = ht_d(root->right);

    Pair *my_pair;

    int my_height = max(left->height,right->height) +1;
    int diameter = max(left->height + right->height , max(left->diameter, right->diameter));

     
    Pair *my_pr = new Pair;
    my_pr ->height= my_height;
    my_pr ->diameter =diameter;

    delete left;
    delete right;

    return my_pr;
}

int tree_diameter (BinaryTreeNode<int>*  root ){
    if(root==NULL){
        return 0;
    }

    Pair * left_p = ht_d(root->left);
    Pair* right_p = ht_d(root->right);

    int op1 = left_p->height+right_p->height;
    int op2 = left_p ->diameter;
    int op3 = right_p->diameter;

    delete left_p;
    delete right_p;

    return max(op1 , max(op2,op3));
}

int main(){
 BinaryTreeNode<int>* root = take_input_levelwise();
 print_level_wise(root);
 cout<<"\ndiamater : "<<tree_diameter(root)<<endl;
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
