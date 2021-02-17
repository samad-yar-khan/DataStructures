 #include <iostream>
 #include <climits>
 using namespace std;      


 class stack {
    int *data; //points to our stack array
    int next_index; //tell us ki naya aya hua eleemnt kha rakhna hua
    int capacity; //this total capacity is proivided by the user at the time of creatuin of a stack

    public :

    //dufault parametreised contsructor 
    // stack (int total_size){
    //     data = new int [total_size];
    //     next_index = 0; //initially 0 inec pe hi dalna hai
    //     capacity = total_size;
    // }

    stack (){
        data = new int [5]{0};
        next_index=0;
        capacity = 5;

    }


    int size (){ 
        return next_index;
    }

    // void push(int n){
    //     if( next_index == capacity ){
    //         cout<<"STACK FULL!"<<endl;
    //         return ;
    //     }

    //     data[next_index]=n;
    //     next_index++;
    //     return;
    // }

    void push(int n){
        if( next_index == capacity ){
            //if our array gets full we make an arr of double the size and copy our elements to this
            //now this will be pour new data
           int * newdata = new int [capacity*2];
           for(int i = 0 ; i < capacity ; i++){
               newdata[i]=data[i];
           }

           delete data;
           data = newdata;
           capacity=capacity*2;
        }

        data[next_index]=n;
        next_index++;
        return;
    }



    bool is_empty(){
        return (next_index == 0);
    }

    int top(){
        if(this->is_empty()){
            cout<<"STACK EMPTY !"<<endl;
            return INT_MIN;       
             }
        return data[next_index -1];
    }

    //delete the top element
    int pop(){
        if(this->is_empty()){
            cout<<"STACK EMPTY !"<<endl;
            return INT_MIN;
        }
        next_index--; //next idex kam hogya, no this can never be used to print  out this value by the user, we can only accesss
                      //iske pehle wali values so acc to users prespective top is deleted
        return data[next_index];
    }

    ~stack (){
        delete data;
    }


};