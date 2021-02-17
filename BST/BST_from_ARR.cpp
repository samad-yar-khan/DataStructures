/*
Code: Construct BST from a Sorted Array
Send Feedback
Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note : If array size is even, take first mid as root.
Input format :
Line 1 : Integer n (Size of array)
Line 2 : Array elements (separated by space)
Output Format :
BST elements (in pre order traversal, separated by space)
Sample Input :
7
1 2 3 4 5 6 7
Sample Output :
4 2 1 3 6 5 7 

*/


#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include <climits>




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
BinaryTreeNode<int>* help (int* input , int SI , int EI){
    
    if(SI>EI){
        return NULL;
    }
    int mid = (SI+EI)/2;
    
    BinaryTreeNode<int> *left = help(input , SI,mid-1);
    BinaryTreeNode<int> *right= help(input,mid+1,EI);
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    root->left = left;
    root->right = right;
    
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	//base

    //is
   
    return help (input , 0 , n-1);
    
    
}


int main(){


    cout<<"Turn Sorted array to  LINKED BINARY SEARCH TREE !"<<endl;

    cout<<"Enter number of elements of arr ";
    int n {};
    cin>>n;

    int*arr = new int[n];

    cout<<"Enter elements (sorted)- ";
    for(int i{0} ; i < n ;i++){
        cin>>arr[i];
    }

    BinaryTreeNode<int>* root = constructTree(arr,n);

    cout<<"\nREQUIRED TREE - "<<endl;

    print_level_wise(root);

    
    delete root;delete []arr;
}