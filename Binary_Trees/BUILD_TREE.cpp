#include <iostream>
#include<queue>

using namespace std;
#include"BinaryTree.h"


BinaryTreeNode<int>* take_input_levelwise();
void print_level_wise(BinaryTreeNode<int> *root);
BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength);

int main(){
    cout<<"Enter number of nodes of tree - ";
    int nodes {};
    cin>>nodes;
    int* preorder =new int [nodes];
    int* inorder =new int [nodes];

    cout<<"\nEnter pre order  - ";
    for(int i =0 ; i<nodes ; i++){
        cin>>preorder[i];
    }

    cout<<"\nEnter in order - ";
    for(int i =0 ; i<nodes ; i++){
        cin>>inorder[i];
    }
    BinaryTreeNode<int>* root = buildTree(preorder,nodes, inorder , nodes);
    cout<<"\nTREE "<<endl;
    print_level_wise (root);

    delete root;
    delete []inorder;
    delete []preorder;

    
}

// my approach
BinaryTreeNode<int>* build_tree(int *preorder, int preLenght, int *inorder, int inLength) {
    // Write your code here
	
    if(inLength <=0 ||  preLenght<=0){
        return  NULL;
    }
    
    BinaryTreeNode <int>* root = new BinaryTreeNode<int> (preorder[0]);
    
    int i =0; 
    while (inorder[i]!=root->data){
        i++;
    }
    // i has length of left tree
    BinaryTreeNode<int>* left= build_tree(preorder+1,i,inorder,i);
    BinaryTreeNode<int>* right= build_tree(preorder+i+1,preLenght-i-1,inorder+i+1,preLenght-i-1);
    
    root->left = left;
    root->right = right;
    return root;
    
}

BinaryTreeNode<int>* build_tree_indexes(int* preorder , int preS , int preE,  int *inorder, int inS , int inE ){

	if(inS>inE){
        return NULL;
    }
    
    int root_data = preorder[preS];
    int root_index=inS;
    while(inorder[root_index]!=root_data){
        root_index++;
    }
    
    int inSL = inS;
    int inEL = root_index-1;
    int preSL = preS+1;
    int preEL = preSL + inEL- inSL;
    
    int inSR = root_index+1;
    int inER = inE;
    int preSR = preEL +1;
    int preER = preE;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (root_data);
    root->left = build_tree_indexes(preorder , preSL , preEL , inorder , inSL , inEL);
    root->right = build_tree_indexes(preorder , preSR , preER , inorder , inSR , inER);
    return root;
    
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    // Write your code here
    
    return build_tree_indexes(preorder,0, preLenght-1,inorder,0,inLength-1);

    
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
