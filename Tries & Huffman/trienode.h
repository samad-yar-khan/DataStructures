using namespace std;
#include <string>
class TrieNode{

    public :

    char data;
    TrieNode** children ; //hold adress of children array
    bool is_terminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode *[26] ; //26 alphabets
        for(int i{0} ; i < 26 ; i++){
            children[i]=NULL;
        }     
        is_terminal = false;
    }

    ~TrieNode(){
        for(int i=0 ; i < 26 ; i++){
            delete this->children[i];
        }
    } 

};



class  Trie {

    private :

    TrieNode* root; //this is the root of our trie

    public :

    Trie (){
        root = new TrieNode ('\0');  // our root will have a null value
    }    

    void insert (TrieNode * root , string word){

        if(word.size() == 0){
            root->is_terminal = true; //signify my last letter
            return;
        }

        int index = word[0]-'a';//tells my position of a letter

        TrieNode* child = NULL;

        if(root->children[index] != NULL){
            child  = root->children[index];
        }else{
            child = new TrieNode (word.at(0)); //made a  new node with that alphabet
            root->children[index]= child;
        }

        insert(child , word.substr(1));

    }

    void insert (string word){
        insert (this->root , word);
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> is_terminal = true;
            return;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }

        bool search(TrieNode *root , string word) {
        
        //base 
        if(word.length() == 0){
            if(root->is_terminal == true){
                return true;
            }else{
                return false;
            }
        }
        
        int index = word[0] - 'a';
        TrieNode* child =  root->children[index];
        
        //is
        if(child == NULL){
            return false;
        }
        
        //is
    	return search (child , word.substr(1));
    }

    bool search(string word) {
        // Write your code here
     	return search (root , word);
    }
    
    void remove (TrieNode* node,string word ){

        if(word.size() == 0){
            node -> is_terminal = false; //we dehighlight our node
            return ;
        }

        //IS

        int index = word[0]  -  'a';
        TrieNode*child = NULL;

        child = node->children[index];
        if(child == NULL){
            return ; ///nothing to delete
        }       

        remove(child , word.substr(1));
        //now i assume all loose ends from my children have been removed
        //if my children is a terminal , we wont delete it 
        // if my children has any other children , i.e. its a ppart of a word  ,
        //we wont delete it

        if(child ->is_terminal == false){ //not a terminal
        //now i check on children

        for(int i{0} ; i <26 ; i++){
            if(child->children[i]!=NULL){
                return; //we dont deleet our child even if it has one child
            }
        } 

        //we only come our of the loop if it has no children
        delete child;
        node->children[index] = NULL;
        return;

        }



    }

    void remove (string word){
        remove (root  ,  word);
    }



    ~Trie(){
        delete root;
    }

};