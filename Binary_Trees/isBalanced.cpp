/*
is Balanced
Send Feedback
Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

#include<iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>

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


class Pair {
    public :
    int depth ;
    bool isbal;
};

Pair help (BinaryTreeNode<int> *root){
    if( root == NULL){
        Pair ans;
        ans.depth = 0;
        ans.isbal = true;
        return ans;
    }
    
    Pair left = help (root->left);
    Pair right = help(root->right);
    
    Pair myp ;
    bool op1 = true;
    myp.depth = 1+ max(left.depth, right.depth);
    if(left.depth!=right.depth){
        int dl = left.depth > right.depth ? left.depth:right.depth;
        int ds = left.depth < right.depth ? left.depth:right.depth;
        if(dl-ds>1){
            op1=false;
        }
	 }
    bool op2 = left.isbal;
    bool op3 = right.isbal;
    
    myp.isbal = (op1&&(op2&&op3));
    
    return myp;
    
    
}
bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
	return (help(root)).isbal;
}