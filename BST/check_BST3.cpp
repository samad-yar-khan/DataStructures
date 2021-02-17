/*
APPROACH 3

we knwo all elemntys to the left fo a node should be less than the root while all alements on the right of it
should be more than root->data  based on this we can specify a range for each node /children subtree
if a node is founf to be outisde our range it is a non bst

*/



#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include <climits>


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

BinaryTreeNode<int>* take_input_levelwise (){

    int root_data{};
    cout<<"Enter root data(-1 for no input) ";
    cin>>root_data;
    if(root_data==-1){
        return NULL;
    }
    queue <BinaryTreeNode<int>*> pending_nodes;
    
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>( root_data);
    pending_nodes.push(root);

    while(pending_nodes.size()!=0){
        BinaryTreeNode<int>* front = pending_nodes.front();
        pending_nodes.pop();

        cout<<"Enter left child of "<<front->data<<endl;
        int left_d;
        cin>>left_d;
        if(left_d!=-1){
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(left_d);
            front->left = left;
            pending_nodes.push(left);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int right_d;
        cin>>right_d;
        if(right_d!=-1){
            BinaryTreeNode<int>* right = new BinaryTreeNode<int>(right_d);
            front->right = right;
            pending_nodes.push(right);
        }

    }

    return root;
    


}

bool is_bst ( BinaryTreeNode<int>* root , int min = INT_MIN , int max = INT_MAX){

    //BC
    if(root==NULL){
        return true;
    }

    //IS
    if(root->data < min || root->data >max){
        return false;
    }

    //IH
    bool check_left = is_bst (root->left ,min , root->data );
    bool check_right = is_bst (root->right  , root->data , max);

    return check_left && check_right;

    
}
 
 int main(){
    BinaryTreeNode<int>* root = take_input_levelwise();
    print_level_wise(root);

   

    cout<<"TREE FEATURES"<<endl;
 
    cout<<boolalpha;
    cout<<"IS TREE A BST  : "<<is_bst(root)<<endl;
    cout<<noboolalpha;
    delete  root;

 }