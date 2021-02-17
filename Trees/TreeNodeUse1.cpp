#include<iostream>
using namespace std;
#include "TreeNode.h"
#include <queue>

template <typename T> 
void printTree (TreeNode<T> * root);

TreeNode<int>* take_input_levelwise();
TreeNode<int>* take_input();

template <typename T> 
void delete_Tree (TreeNode<T> *root);

template <typename T>
void print_Tree_Levelwise (TreeNode<T> * root);




int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);

    // (*root).children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int>* root=take_input_levelwise();
    
    print_Tree_Levelwise(root);


    //delete_Tree (root); //this was fine but we dont need this anymore,we can justb delete all nodes using
                          //recursion inside our destructor

    // delete root;
    // delete node1;
    // delete node2;

}


template <typename T>
void printTree (TreeNode<T> * root){    
    
    cout<<root->data<<" : ";
    for (int i = 0; i < root->children.size(); i++)
    {
      cout<<root->children[i]->data<<",";
    }
    cout<<"\n";
    for(int i=0 ; i< root->children.size() ; i++){
        printTree
        (root->children[i]);
    }
}

TreeNode<int>* take_input(){

    cout<<"Enter data of the node - ";
    int data;
    cin>>data;
    TreeNode<int>* root = new  TreeNode<int>(data);
    cout<<"Enter number of children of "<<data<<" - ";
    int num_children ;
    cin>> num_children ;

    for(int i=0 ; i<num_children ;i++){
        
        TreeNode<int>*child = take_input();
        root->children.push_back(child);

    }
    
    return root;
}

template <typename T> 
void delete_Tree (TreeNode<T> *root){

    //base case
    if(root->children.empty()){
        delete root;
        return;
    }

    //IH
    for(int i=0 ; i<root->children.size() ; i++){
        delete_Tree(root->children[i]);
    }

    //IS
    delete root;
}

TreeNode<int>* take_input_levelwise(){
    
    int root_data;
    cout<<"Enter root data ";
    cin>>root_data;

    TreeNode<int>*root = new TreeNode<int>(root_data);
    queue <TreeNode<int>*> pending_nodes ;
    pending_nodes.push(root);

    while(pending_nodes.size()!=0){

        TreeNode<int>* front = pending_nodes.front();
        pending_nodes.pop();
        int num_children{0};
        cout<<"Enter number of children of "<<front->data<<" : ";
        cin>>num_children;

        for(int i {0} ; i<num_children ; i++){
            cout<<"Enter data of "<<i<<"th child of "<<front->data <<" : ";
            int child_data{};
            cin>>child_data;

            TreeNode<int>* child = new TreeNode<int> (child_data);
            front->children.push_back(child);
            pending_nodes.push(child);
        }
    }

    return root;

}

template <typename T>
void print_Tree_Levelwise (TreeNode <T>* root){

    queue<TreeNode <T>*> pending_nodes;
    pending_nodes.push(root);

    while (pending_nodes.size()!=0)
    {
        TreeNode<T>* front_node=pending_nodes.front();
        pending_nodes.pop();

        cout<<front_node->data<<":";
        for(int i =0 ;i<front_node->children.size(); i++){
            TreeNode<T>* child = front_node->children[i];
            pending_nodes.push(front_node->children[i]);
            cout<<child->data;
            if(i<front_node->children.size()-1){
                cout<<",";
            }
        }
        cout<<"\n";
    }
    


}