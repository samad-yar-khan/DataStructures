#include <iostream>
#include<string>
using namespace std;


//node clas to support our linked list
template <typename V>
class Node {

    public:

    string key;
    V value ;
    Node<V>* next;

    Node(string key ,V data){

        this->key = key;
        this->value = data;
        this->next = NULL;

    }

    //destructor 
    ~Node(){
        delete next; //when we call dlete on head it recurivley deletes the whole ll
    }

    //friend class ourmap;

};

template <typename V>
class ourmap{

    private:

    Node<V>** buckets;
    int bucket_size;;
    int count;

    public:
    
    //conttructor
    ourmap(){
        buckets = new Node<V>*[5]; //pts to an array which har ptr head of sepearet lls
        for(int i=0 ; i<5 ; i++){
            buckets[i]=NULL;
        }
        bucket_size = 5;
        count = 0;
    }

    int size (){
        return count;
    }

    //destructor 
    ~ourmap (){
        for(int i=0 ; i<bucket_size ; i++)
        {
            delete buckets[i];
        }
    }
    
    private:
    //converts my key to hashcode and then our compreseeive func gives us our bcket_index
    int get_bucket_index(string key){

        int hash_code = 0;
        int current_coeff = 1;
        
        /*
        (A*B*C)%r =( A%r * B%r * C%r )%r
        */

        for(int i=key.length() -1  ; i >= 0 ; i-- ){
            
            hash_code += key.at(i)*current_coeff;
            hash_code = hash_code % bucket_size; //just to keep it within bounds we use modulus op at each step
            current_coeff*=37;
            current_coeff = current_coeff % bucket_size;

        }

        return hash_code % bucket_size;

    }
    //so bacially as soon as oout loadfactor becomes more than 0.7 we rehash the map tpo trickel down 
    //complexity back to O(1)
    void rehash (){

        Node<V>** temp = buckets;

        buckets = new Node<V>*[2*bucket_size];

        int old_bucket_size = bucket_size;
        bucket_size= bucket_size*2;

        for(int i{0} ; i<bucket_size ; i++){
            buckets[i]=NULL;
        }
        
        count=0;
        for(int i{0} ; i<old_bucket_size ; i++){
            Node<V>* head = temp[i];

            while(head!=NULL){

                string key = head->key ;
                V value = head->value;

                insert(key,value);
                head=head->next;
            }
        }

        for(int i{0} ; i<old_bucket_size ; i++){
            Node<V>* head = temp[i];
            delete head; //recursivve deletion of our ll
        }
    }

    public:

    double loadfactor(){

        double load_factor =  (1.0*count / bucket_size);
        return load_factor;

    }

    void insert (string key , V value){

        int bucket_index  = get_bucket_index(key); //we need to get the bucket index of ur key
        Node<V>* head = buckets[bucket_index];
        Node<V>* head_2 = head;;
        //now we need look fr our key on the ll at index bucket_index

        //if we find  the key we update the vall8ue
        //if we cant find the key we add our new node with key and vall at the
        //begg of our ll

        while (head != NULL){
            if(head->key==key){
                head->value=value;
                return;
            }

            head = head -> next;
        }

        //we exit the loop only if our key isnt present in the array
        //add a new node at the begghiniing of our ll at that index
        Node<V> * new_head = new Node<V>(key , value);
        new_head -> next = head_2;
        buckets[bucket_index] = new_head; //we update our head
        count++;

      double load_factor = (1.0*count/bucket_size);

        if(load_factor > 0.7){
            rehash();
        }
   
    }

    V  get_value (string key){
        int bucket_index  = get_bucket_index(key);
        Node<V>* head = buckets[bucket_index];
        //our key can be presnt anywhere in the ll so we traverse through the whole ll till we find key
        while (head!=NULL){
            if(key == head->key){
                return head->value;
            }
            head = head->next;
        }
        //you only come outta the loop if you acant find the key
        return 0;        
    }


    V delete_key (string key){

        int bucket_index = get_bucket_index(key);
        Node<V> * head = buckets[bucket_index];

        Node<V> *previous = NULL; //keeps strack of my prev node so i can delete my curewnt node adn connect the ll
        while (head != NULL){

            if(head->key == key ){
                if(previous==NULL){
                    buckets[bucket_index]=head->next;
                    head->next = NULL;
                    int temp=head->value;
                    delete head;
                    count--;
                    return temp;
                }else{
                    previous ->next = head-> next; //bridged the ll
                    head->next = NULL;
                    int temp=head->value;
                    delete head;
                    count--;
                    return temp;
                    
                }
            }

            previous = head;
            head = head->next;
        }

        return 0; //key not present
    }
};