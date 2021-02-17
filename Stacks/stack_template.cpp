#include <iostream>
using namespace std;

template <typename T>

class stack{
    private :
    T* data;
    int capacity;
    int next_index;

    public:

    stack (){
    data = new T[5]{0};
    capacity =5;
    next_index = 0;
    }

    int size() {
        return next_index;
    }

    bool is_empty(){
        return next_index == 0;
    }

    void push (T n){
        if(next_index == capacity){
            T*new_data = new T;
            for(int i = 0 ; i<capacity ; i++){
                new_data[i]=data[i];
            }
            capacity = capacity*2;
            delete data;
            data = new_data;
        }
        data[next_index]=n;
        next_index++;
    }

    T top (){
        if (is_empty()){
            cout<<"STACK EMPTY!\n";
            return 0;
        }
        return data[next_index-1];
    }

    T pop (){
           if (is_empty()){
            cout<<"STACK EMPTY!\n";
            return 0;
        }
        next_index--;
        return data[next_index]; 
    }

    ~stack(){
        delete [] data;
    }

};