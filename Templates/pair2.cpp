//now we want the option make our templates of different types
#include<iostream>
using namespace std;
template <typename T , typename V>
                      
class Pair {
    private:
    T x;
    V y;
    
    public :

    //setters
    // Pair <T,V> (T x , V y){
    //     this->x=x;
    //     this->y=y;
    // }
    void set_x (T x){
        this->x = x;  //copy assignment operatpr works here
    }

    void set_y (V y){
        this->y= y;  //copy assignment operatpr works here
    }

    //getters
    T get_x (){
        return this->x;
    }

    V get_y (){
        return this->y;
    }

    void display(){
        cout<<x<<" "<<y<<"\n";
    }
};

