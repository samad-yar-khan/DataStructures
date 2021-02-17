/*
ZigZag tree
Send Feedback
Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/
#include<iostream>
using namespace std;
#include"BinaryTree.h"
#include<stack>
#include <queue>

//logic
// we store our root ina  stack 
 void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    //edge case
	if(root==NULL){
        return ;
    }
    
    //we make two stacls , while other is being emptied we fill the other one
    stack<BinaryTreeNode<int>*> outer_stack;
    stack<BinaryTreeNode<int>*> inner_stack;
    
    //we push root to our stack1
    outer_stack.push(root);
    //we maintain a count to know which tasks to do , because at altenrate iterations 
    //  we have to perfoerm differnet tasks and use push in dieffernet stack
    int count =1 ;
    //at each outer iteration one stack will be full with nodes of one level
    //while other would be empty
    while(outer_stack.size()!=0 || inner_stack.size() != 0){
        //for odd iteraion we know our  nodes
        //will come out in correct order so if we just opush their in another stack left 
        //to right , they will automatically come out in reversede fashion fashion in next its
        if(count%2 != 0){
            while (outer_stack.size()!=0){
                BinaryTreeNode<int>* top = outer_stack.top();
                outer_stack.pop();
                cout<<top->data<<" ";
                if(top->left!=NULL){
                inner_stack.push(top->left);
                }
                if(top->right != NULL){
                inner_stack.push(top->right);
                }
            }
            cout<<"\n";
            count++;
        }//for even iteration we know our eleemnts willl pop out in a reverse order(right to left) so we push children in reverse order 
        //right then left , so that so that our new stack when full will have elements in correct order when popped out
        else{
            while(inner_stack.size()!=0){
             BinaryTreeNode<int>* top = inner_stack.top();
            inner_stack.pop();
             cout<<top->data<<" ";
            if(top->right!=NULL){
             outer_stack.push(top->right);
            }
                if(top->left!=NULL){
             outer_stack.push(top->left);
                }
            }
            cout<<endl;
            count++;
        }
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

int main(){
    BinaryTreeNode<int>* root = take_input_levelwise();
    cout<<"ZIG ZAG TREE \n";
    zigZagOrder(root);
}