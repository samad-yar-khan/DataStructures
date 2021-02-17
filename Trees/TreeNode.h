using namespace std;
#include <vector>
#include <queue>

template <typename T>

class TreeNode{
    public :
    T data;
    vector<TreeNode<T>*> children;
    
    //constructor
    TreeNode (T data){
        this->data = data;
       
    }

    ~TreeNode ( ){
        for(int i=0;i<this->children.size() ;i++){
            delete this->children[i];
        }
        cout<<"Deallocated ! \n";
    }
    

};