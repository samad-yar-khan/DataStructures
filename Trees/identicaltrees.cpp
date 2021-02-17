#include <iostream>
#include <queue>
using namespace std;
#include"TreeNode.h" 


template <typename T>
void print_Tree_Levelwise (TreeNode <T>* root);
TreeNode<int>* take_input_levelwise();
bool  identical_trees(TreeNode<int>*root1,TreeNode<int>*root2);

int main(){

    TreeNode<int>*root1=take_input_levelwise();
    cout<<"YOUR TREE 1\n";
    print_Tree_Levelwise (root1);

    TreeNode<int>*root2=take_input_levelwise();
    cout<<"YOUR TREE 2\n";
    print_Tree_Levelwise (root2);
    cout<<boolalpha;
    
    cout<<"Tree 1 and Tree 2 are identical : "<<identical_trees(root1,root2)<<"\n";
    

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

bool  identical_trees(TreeNode<int>*root1,TreeNode<int>*root2){

    queue <TreeNode<int>*> Q1;
    queue <TreeNode<int>*> Q2;
    
    Q1.push(root1);
    Q2.push(root2);
    
    while( !Q1.empty() && !Q2.empty()){
        TreeNode<int>* front1 = Q1.front();
        Q1.pop();
        
        TreeNode<int>* front2 = Q2.front();
        Q2.pop();
        
        if (front1->data != front2->data){
            return false;
        }
        
        for(int i =0 ; i < front1->children.size() ; i++){
        	Q1.push(front1->children[i]);
        }
        
        for(int i =0 ; i < front2->children.size() ; i++){
        	Q2.push(front2->children[i]);
        }
        
        if(Q1.size() != Q1.size()){
            return false;
        }
        
    }
    
    return true;
}


//1 2 2 3 1 5 1 7 0 0