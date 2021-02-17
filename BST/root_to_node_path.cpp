#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include "BinaryTree.h"


void print_level_wise(BinaryTreeNode<int> *root);
BinaryTreeNode<int>* take_input_levelwise ();
vector<int>* return_path(BinaryTreeNode<int>*,int k);

int main(){
    
    BinaryTreeNode<int>* root = take_input_levelwise();

    cout<<"Enter node to till which path is reqd - ";
    int n;
    cin>>n;
    vector<int>* path = return_path(root ,n );

    for(auto const &x:*path){
        cout<<x<<endl;
    }

    delete path;
    delete root;
}




vector<int>* return_path(BinaryTreeNode<int>* root,int k){

    //base case

    if(root==NULL){
        return NULL;
    }

    //induction step

    if(root->data == k){
        vector<int> *path = new vector<int>;
        (*path).push_back(root->data);
        return path;
    }

    vector<int>* left_path = return_path (root->left , k);
    if(left_path!=NULL){
        left_path->push_back(root->data);
        return left_path;
    }

    vector<int>* right_path = return_path(root->right , k);
    if(right_path!=NULL){
        right_path->push_back(root->data);
        return right_path;
    }

    return NULL;
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