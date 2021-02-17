/*
Level order traversal
Send Feedback
Given a binary tree, print the level order traversal. Make sure each level start in new line.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9

*/

#include<iostream>
#include<queue>
using namespace std;
#include "BinaryTree.h"

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

void print_levels (BinaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<endl;

    queue <BinaryTreeNode<int>*> pendingnodes ;
    pendingnodes.push(root);
    int count =1;

    while (pendingnodes.size ()!=0){
        
        int c= count;
        count =0;
        for(int i = 0 ; i<c ; i++){
            BinaryTreeNode<int>* front = pendingnodes.front();
            pendingnodes.pop();
            if(front->left !=NULL){
                cout<<front->left->data<<" ";
                count++;
                pendingnodes.push(front->left);
            }
            if(front->right !=NULL){
                cout<<front->right->data<<" ";
                count++;
                pendingnodes.push(front->right);
            }
        }

        cout<<endl;
    }
}

int main(){
    BinaryTreeNode<int>* root = take_input_levelwise();
    print_levels(root);
    delete root;
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 










