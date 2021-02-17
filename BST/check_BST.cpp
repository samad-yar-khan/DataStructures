#include<iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include <climits>

int  min_node(BinaryTreeNode<int>* root){
    if(root==NULL){
        return  INT_MAX;
    }

    //IH

    int min_l = min_node(root->left);
    int min_r = min_node(root->right);

    //IS 
    return min(root->data , min(min_l,min_r));  //we return the absolute minimun
}


int max_node (BinaryTreeNode<int>* root){
    //base case
    if(root==NULL){
        return INT_MIN;
    }
    //iH
    int max_l = max_node(root->left);
    int max_r = max_node(root->right);

    //is
    int my_output = max(root->data , max(max_l,max_r));
    return my_output;
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



bool check_bst(BinaryTreeNode<int>* root){

    //base case
    if(root==NULL ){
        return true;
    }

    bool left_condition = (root->data > (max_node(root->left)));
    bool right_condition = (root->data < min_node(root->right));
    
    return  (left_condition && right_condition && check_bst(root->left) && check_bst(root->right));


}


int main(){
    BinaryTreeNode<int>* root = take_input_levelwise ();

    print_level_wise(root);

    cout<<boolalpha;
    cout<<"MINIMUM NODE - "<<min_node(root)<<endl;
    cout<<"MAXIMUM NODE - "<<max_node(root)<<endl;
    cout<<"BST - "<<check_bst(root);

    delete root;
}