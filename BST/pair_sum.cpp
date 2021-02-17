/*
Pair sum BInary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S
Output Format :
Each pair in different line (pair elements separated by space)
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

/*
LOGIC 
we will store thr whole tree in a vector using pre order traersal.O(n)
next thing we do is that qwe save this in an array;O(n)
we sort the arry so we can optimize the pairing. sorting is donme using merge sort.O(NlogN)

now we have  a sorted array and a sum 
so we keep an index at the beggining(i) of the arry and one at the end index(j)
if sum of pairs is greater than given sum we decrease j , because we need a lower sum
if sum of pairs is less we inremenet i , we need a lkarger sum
if sum == k , we print pair , we invremener i and dcrenment j
*/
#include<iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
#include<vector>

int* merge_sorted(int* arr1 ,int size1, int *arr2,int size2){

    int *arr = new int[size1 + size2];

    int i=0;
    int j=0;
    int k=0;

    while(i<size1 && j<size2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
            k++;
        }else{
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }

    while(i<size1){
        arr[k]=arr1[i];
        i++;
        k++;
    }

    while(j<size2){
        arr[k]=arr2[j];
        j++;
        k++;
    }

    return arr; 
}

void merge_sort(int* arr,  int size ){
    if(size==1 || size ==0){
        return;
    }

    int mid = size/2;
    merge_sort(arr , mid);
    merge_sort(arr+mid , size-mid);

    int *ans = merge_sorted(arr , mid , arr+mid,size-mid);

    for(int i{0} ; i<size ;i++){
        arr[i]=ans[i];
    }

    delete [] ans;
}

void save_in_vector (BinaryTreeNode<int>*root ,  vector<int> &vec){
    if(root==NULL){
        return;
    }
    
    vec.push_back(root->data);
    save_in_vector(root->left , vec);
    save_in_vector(root->right , vec);
    
    return;
}

void nodesSumToS(BinaryTreeNode<int> *root, int  sum) {
    // Write your code here
    if(root==NULL){
     return;   
    }
    vector <int> vec;
    
    save_in_vector(root,vec);
    int *arr = new int [vec.size()];
    
    for(int i{0} ; i < vec.size() ; i++){
        arr[i]=vec[i];
    }
    
    merge_sort(arr,  vec.size() );
    
    int i =0;
    int j = vec.size()-1;
    
    while (i<j){
        if(arr[i]+arr[j]==sum){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }else if(arr[i]+arr[j]<sum){
            i++;
        }else{
            j--;
        }
    }

    delete [] arr;
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


int count_nodes (BinaryTreeNode<int> *root ){
    if(root==NULL){
        return 0;
    }
    
    int x = count_nodes (root->left);
    int y = count_nodes (root->right);
    
    return x+y+1;
}

int main(){
    cout<<"Enter the BT "<<endl;
    BinaryTreeNode<int>* root = take_input_levelwise();
    cout<<count_nodes (root)<<endl;

    cout<<"Enter value of sum of the pairs rrquired : ";
    int k ;
    cin>>k;

    cout<<"Nodes with sum equal to "<<k<<" is : "<<endl;
    nodesSumToS(root , k);

    delete root;
}