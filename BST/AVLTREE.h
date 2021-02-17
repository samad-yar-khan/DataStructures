#include "BinaryTree.h"
#include <queue>
#include<queue>
class Pair{
    public : 
    int depth ;
    BinaryTreeNode<int>* child;
};

class BST {
	// Complete this cl    
    private : 

    BinaryTreeNode<int>* root; //our bst willl internally work on a BT strcuture 

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

    bool has_data (int k , BinaryTreeNode<int>* node){
     if(node == NULL){
        return false;
     }   

     if(node->data == k){
        return true;
     }else if(node->data > k){
         return  has_data(k , node->left);
     }else {
         return has_data (k , node->right);
     }
    }

    BinaryTreeNode<int>* insert_node (BinaryTreeNode<int>* node,int k){

        if(node==NULL){
            BinaryTreeNode<int> * newnode = new BinaryTreeNode<int> (k);
            return newnode;
        }

        if(k<node->data){
            BinaryTreeNode<int>* left = insert_node(node->left , k);
            node ->left=left;
            return node;
        }else{
            BinaryTreeNode<int>* right = insert_node(node->right,k);
            node->right = right ;
            return node;
        }
        
    }


    BinaryTreeNode<int>* deleteData (BinaryTreeNode<int>* node , int k){

        if(node==NULL){
            return node;
        }

        if(node->data == k){
            if(node->left ==NULL && node->right ==NULL){
                delete node;
                return NULL;
            }

           if(node->left == NULL && node->right !=NULL){
               BinaryTreeNode<int>* newhead = node->right;
               node->right = NULL;
               delete node;
               return newhead;
           } 

           if(node->left != NULL && node->right ==NULL){
               BinaryTreeNode<int>* newhead = node->left;
               node->left = NULL;
               delete node;
               return newhead;
           } 
		
            BinaryTreeNode<int>* temp = node->right;
            
            while(temp->left!=NULL){
                temp=temp->left;
            }
            
            node->data = temp->data;
            node->right = deleteData(node->right,temp->data);
            
            return node;
            
         }else if(node->data >k){
             node->left = deleteData(node->left,k);
             return node;
         }else {
             node->right = deleteData(node->right,k);
             return node;
         }
    }

    void printTree(BinaryTreeNode<int> * node){
        if(node==NULL){
        return;
    }
    
    queue <BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(node);
    
    while(pending_nodes.size()!=0){
        BinaryTreeNode<int> * front = pending_nodes.front();
        pending_nodes.pop();
        
        cout<<front->data<<":";
        
        if(front->left!=NULL){
            cout<<"L:"<<front->left->data<<",";
            pending_nodes.push(front->left);
        }else{
            cout<<"L: ,";
        }
        
        if(front->right!=NULL){
            cout<<"R:"<<front->right->data;
            pending_nodes.push(front->right);
        }else{
            cout<<"R: ";
        }
        cout<<endl;
    
        // printTree(node->left);
        // printTree(node->right);
        
    }
    }

    public:


    //constructor
    BST() {
        root=NULL;
    }

    //destructor
    ~BST (){
        delete root; //BT already deleetd roor recursively we jsut use delete
    }

    //
    bool hasData (int k){
        return has_data (k,root);
    }

    void insert (int k){
        BinaryTreeNode<int>* newroot= insert_node(root,k);
        newroot=balance_BST(newroot).child;
        root = newroot;
        return;
    }

    void deleteData (int k){

        root = deleteData(root,k);
        root=balance_BST(root).child;

        return;
    }

    void printTree(){
        printTree(root);
    }

    
};


