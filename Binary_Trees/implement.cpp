#include<iostream>
using namespace std;
#include <queue>
#include "BinaryTree.h"

// BinaryTreeNode<int>* take_input (){
//     int root_data{};
//     cout<<"Enter data "<<endl;
//     cin>>root_data;
//     if(root_data==-1){
//         return NULL;
//     }

//     BinaryTreeNode <int>* root = new BinaryTreeNode<int> (root_data);
//     BinaryTreeNode <int>* left_child = take_input();
//     BinaryTreeNode <int>* right_child = take_input();

//     root->left = left_child;
//     root->right = right_child;

//     return root;
// }

// int depth_of_tree (BinaryTreeNode<int>* root,int height=0){
//     if(root==NULL){
//         return height;
//     }

//     height ++;

//     int l_h = depth_of_tree(root->left,height);
//     int r_h = depth_of_tree(root->right,height);


// }
// void print_masTREE(BinaryTreeNode<int> root){

// }
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

int num_nodes(BinaryTreeNode<int>* root){
    //base case base
    if(root == NULL){
        return 0;
    }

    int my_answer =1 ;
    int smalloutput_L = num_nodes(root->left);
    int smalloutput_R = num_nodes(root->right);

    return my_answer + smalloutput_L +smalloutput_R;
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
template <typename T>
void print_Tree (BinaryTreeNode <T>* root){

    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<"\n";

    print_Tree(root->left);
    print_Tree(root->right);
}

int main(){
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode <int>(20);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(30);
    // (*root).left =node1;
    // (*root).right=node2;

    BinaryTreeNode <int>* root = take_input_levelwise();
    print_level_wise(root);
    cout<<"\nno of nodes -"<<num_nodes(root)<<endl;

    delete root; // should delete the whoel tree
}