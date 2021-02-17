/*
Next larger
Send Feedback
Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.
Return NULL if no node is present with the value greater than n.
Input Format :
Line 1 : Integer n
Line 2 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Node with value just greater than n.
Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
20
Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
30
*/
#include <iostream>
#include <queue>
using namespace std;
#include"TreeNode.h" 


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
TreeNode<int> * nextLargerElement(TreeNode<int> *root, int n) {

    queue <TreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    
    TreeNode<int> * max_next=NULL;

    while(!pending_nodes.empty()){
        
        TreeNode<int> * front_node = pending_nodes.front();
        pending_nodes.pop();
        if(max_next==NULL){
            if(front_node->data > n){
                max_next = front_node;
            }
        }
        
        if(front_node->data > n && front_node->data < max_next ->data){
            max_next = front_node;
            }
        
        for(int i{0} ; i<front_node->children.size() ;i++){
            pending_nodes.push(front_node->children[i]);
        }
    }
    
    return max_next;
	
}

int main(){
    return 0;
}