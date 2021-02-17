#include<iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include <cmath>

class Pair{
    public : 
    int depth ;
    BinaryTreeNode<int>* child;

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

Pair balance_BST (BinaryTreeNode<int>* node){
    if(node == NULL){
       Pair ans;
       ans.depth=0;
       ans.child =NULL;
        return ans;
    }

    //ih this will rerturn me 2 balanced bsts and their depth
    //we do this at each addition of node so , diif ion dpeh cant be more than once
    Pair left = balance_BST(node->left);
    Pair right = balance_BST(node->right);

    //is
    if(left.depth - right.depth > 1 ){
        BinaryTreeNode<int>* newroot;
        newroot = left.child;
        BinaryTreeNode<int>* temp=left.child->right;
        node->left = temp;
        node->right = right.child;
        newroot->right = node;

        Pair ans;
        ans.depth = left.depth ;
        ans.child = newroot;
        return ans;
    }else if(right.depth - left.depth > 1 ){
        BinaryTreeNode <int>*newroot = right.child;
        BinaryTreeNode<int>*temp = right.child->left;
        node->right= temp;
        newroot->left = node;
        
        Pair ans;
        ans.depth = right.depth;
        ans.child = newroot;
        return ans;
    }else{
        node->left = left.child;
        node->right = right.child;
        Pair ans ;
        ans.depth = max(left.depth,right.depth)+1;
        ans.child = node;
        return ans;
    }
}

pair<int,bool>is_balanced (BinaryTreeNode<int>* node){
    if(node == NULL){
        pair<int,bool> ans;
        ans.first = 0;
        ans.second = true;
        return ans;
    }

    //ih this will return me a pair telling me depth of my childrena nd if they are balaanced or not
    pair<int,bool> left_output = is_balanced(node->left);
    pair<int,bool> right_output = is_balanced (node->right);

    pair<int , bool > ans ;
    ans.first = max (left_output.first , right_output.first) + 1;
    ans.second = abs(left_output.first- right_output.first)<=1 && left_output.second && left_output.second;

    return ans;

}
 
  
int main(){
    BinaryTreeNode<int> * root = take_input_levelwise();
    
    cout<<is_balanced(root).second<<endl;
    print_level_wise(root);
    Pair ans= balance_BST(root);
    root= ans.child;
    print_level_wise(root);
    cout<<is_balanced(root).second;
    


    delete root;
}