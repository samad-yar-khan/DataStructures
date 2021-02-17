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
void print_at_level_k (TreeNode<T>* root , int k){
   
   //edge cases
    if(k<0 || root==NULL){
        cout<<"invalid value of k !\n";
        return;
    }

    if(k==0){
        cout<<root->data<<endl;
        return;
    }

    //if we see closely base cases arre hiddern inside the loop
    //if we have just one 1 node/if we are on a leaf and k is still > 0, 
    //the loop wont run and we ll simply return void , no erros
    for(int i{0} ; i<root->children.size() ; i++){
        print_at_level_k (root->children.at(i) ,k-1);
    }
    return;

}

template <typename T> 
int number_of_leaves(TreeNode<T>*root){
    if(root==NULL){
        return 0;
    }
    
    if(root->children.empty()){
        return 1;
    }
       
    int sum_of_leaves =0;
    for(int i{0} ; i<root->children.size() ; i++){
        sum_of_leaves+=number_of_leaves(root->children.at(i));
    }
       
    return sum_of_leaves;
       
}

int main(){
    TreeNode<int>*root=take_input_levelwise() ;
    cout<<"Whole tree structure - \n" ;
    print_Tree_Levelwise(root);

    cout<<"Which level depth / level do you wanty to print ? ";
    int k{0};
    cin>>k;

    cout<<"\nData at "<<k<<" level -"<<endl;
    print_at_level_k(root,k);

    delete root; //we dont have to use the delete function we created , we did it kin our destructor
    // delete_Tree(root);
}

