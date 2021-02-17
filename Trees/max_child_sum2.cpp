/*
Node with maximum child sum
Send Feedback
Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output format :
Node with maximum sum.
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
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

class Pair{
    public :
    TreeNode<int>* Tree_node ;
    int sum;
    
    Pair(TreeNode<int>* node){
        Tree_node=node;
        sum=node->data;
        for(int i=0 ; i<node->children.size() ; i++){
            sum+=node->children[i]->data;
        }
    }
};

Pair max_children_sum (TreeNode<int> *root){
    Pair max(root);
    
    for(int i=0 ; i<root->children.size();i++){
        Pair temp_max= max_children_sum(root->children[i]);
        
        if(temp_max.sum > max.sum){
            max=temp_max;
        }
    }
    return max;
}
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    //edge case
     if(root==NULL){
        return root;
    }
    return  max_children_sum(root).Tree_node;
   
    
}

int main(){
    return 0;
}