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

pair <int,int> height_diameter (BinaryTreeNode<int>* root){
    //base case
    //if we have zero nodes, we return a pair with h=0 , d=0
    //thats eat makes sense
    if(root==NULL){
        pair <int , int> my_pair ;
        int height = 0;
        int diameter = 0;
        my_pair.first = height;
        my_pair.second=diameter;
        return my_pair;   
    }
   
    //induction hypothesis
    //these will retun to me respective hts and diamter of my childred subtress
    pair <int,int> left = height_diameter(root->left);
    pair <int,int> right = height_diameter(root->right);
    
    int height_left = left.first;
    int height_right = right.first;
    int diameter_left = left.second;
    int diameter_right = right.second;

    int option_1 = height_left+height_right;
    int option_2 = diameter_left;
    int option_3 = diameter_right;

    int my_ht = max(height_left , height_right)+1; //max ht + my root
    int my_diameter = max(option_1,max(option_2,option_3));

    pair<int,int> output_p ;
    output_p.first = my_ht;
    output_p.second= my_diameter;

    return output_p;

}

int main(){
    cout<<"------------INPUT-------\n";
    BinaryTreeNode<int>* root = take_input_levelwise();
    cout<<"------------TREE-------------\n";
    print_level_wise(root);

    pair <int , int> ans = height_diameter(root);
    cout<<"\nheightt of tree "<<ans.first<<endl;
    cout<<"diameter of tree "<<ans.second<<endl;


    delete root;

}