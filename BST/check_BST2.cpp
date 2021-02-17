/*

we try with a better aaproach with a lower complexity.
we will make a class and retunr multiple values at once
so that we dont hav eto go back to that node morre than once
O(n complexity

*/

#include<iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include <climits>

class triplet {
    public:

    bool is_bst;
    int min;
    int max;

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

triplet is_BST (BinaryTreeNode<int>* root){

    //base case
    if(root == NULL){
        triplet ans;

        ans.is_bst = true; //no node so our ans should be trur
        ans.min = INT_MAX; // no node so +infinity indiciated this as min
        ans.max = INT_MIN; //no nodes so -infinity indicates this as max

        return ans;
    }

    //ih
    //we assume left and right gives us the correct data for subtrees
    triplet left = is_BST(root->left);
    triplet right = is_BST(root->right);

    //is

    triplet my_ans;
    my_ans.max = max(root->data , max (left.max , right.max));
    my_ans.min = min(root->data , min (left.min , right.min));
    my_ans.is_bst = (root->data > left.max && root->data < right.min && left.is_bst && right.is_bst);
    return my_ans;
}

int main(){

    BinaryTreeNode<int>* root = take_input_levelwise();
    print_level_wise(root);

    triplet my_triplet = is_BST(root);

    cout<<"TREE FEATURES"<<endl;
    cout<<"MAX NODE : "<<my_triplet.max<<endl;
    cout<<"MIN NODE : "<<my_triplet.min<<endl;
    cout<<boolalpha;
    cout<<"IS TREE A BST  : "<<my_triplet.is_bst<<endl;
    cout<<noboolalpha;
    delete  root;
}