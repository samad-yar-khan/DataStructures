#include <iostream>
using namespace std;

template <typename T>

class Queue{
    private :

    T* data ; //pts to an array which hold t type of data
    int first_index;
    int next_index;
    int size;
    int capacity;

    public:

    //constructow which takes my size of quee needed
    //must intialise everthuing
    Queue (int capacity){
        this->capacity = capacity;
        size = 0;
        data = new T[capacity];
        first_index = -1; //initial size is zero so first index is -1
        next_index = 0;
    }

    int get_size (){
        return size;
    }

    bool is_empty (){
        return size == 0;
    }

    void enqueue(T element){
       
        if(size == capacity){
            cout<<"Queue Full !\n";
            return;
        }

        data[next_index]=element; //added the element at the next free index/ slot
        next_index = (next_index+1)%capacity ;
        //basically as soon as nextindex+1 is less then capacity , it is stores as usual in the next_index
         //now this ensures normal increment of next index till we reach the end of array
        // as soon as we reach the end of array nextindex+1 becomes equal to our capacity
        //now capacity % capacity = 0
        //so wehen qwe reah the end of out array , this send us back to first index and we travel
        //the array in a circular manner
        //this is done to utilise the space which was vacated by the first elments which were deleted
        //as entry point and exit point bare different here(unlike stack), we ll have to go back these 
        //indexes ion this way 
        if(first_index == -1){ //if this is the first element bieneg added here , we miust change first index to 0
            first_index = 0;
        }
        size++;
        return;
    }

    T front(){ //return type T, that the data i am storing

        if(size ==0 ){ //empty queue
            cout<<"Empty Queue !\n";
            return 0;
        }

        return data[first_index];

    }  

    T deque(){
        if(size ==0 ){ //empty queue kise hatau
            cout<<"Empty Queue !\n";
            return 0;
        }

        T deleted_data   = data [first_index];
        first_index=(first_index+1)%capacity; //we want this to move circularly through our arr aswell 
                                              //if this goes  beyond first endex becomes equal to capacity
                                              //it will be send to the 0th index 
        size--;

        if (size==0) //if size becomes zero we reset the queeue
        {
            first_index = -1;
            next_index=0;
        }

        return deleted_data;
    }

    ~Queue(){
        delete [] data;
    }
}; 