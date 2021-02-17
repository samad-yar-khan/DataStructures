#include<iostream>
#include<string>
using namespace std;

class vehicle {

    public:

        string color ;
        //this is a virtual function soo its decdded at runtime whtehr this would be used or the one in child class

        virtual void print(){
            cout<<"vehicle\n";
        }

};

class car : public vehicle {

    public :

        int max_speed ;
        void print(){
            cout<<"car\n";
        }

};

class car_2 : public vehicle {

    public :

        int max_speed ;


};

int main(){

    car * c1 = new car ;
    car c2 ;

    c1->print();
    vehicle* v1 = &c2 ; //vehicle ptr  pointiing to c2

    //in prev ex of compile time polimorphism we say that it is decide at compile time that print of 
    //vehicle will be called if our vehicle(base class) ptr pts to and object of car class(child class)
    // this is becuaasse acc too our compiler vehicle ptr should have acces t only vehicle functions and properties 

    //but by using virtual funcs it is decided at run time , which pint is  to be used , it sees that alhough uts a vehicle ptr
    //but its is pooited towards a car bject and the func is virtual so it looks for thee function in car first , and exucuted it

    
    v1->print();
    
    //if print is removed from car class , directly vehiclle ka print call hoga

    car_2 c3 ;
    vehicle* v2 = &c3 ;
    v2->print();//ye vehicle ka print call karega because although due to rpint being virtual func its decide at runtime 
    //ki konsa print call hoga , but car_2 mai print hai hi nhi to vehicle ka ccall hojayega
    


    delete c1;
}

