#include <iostream>
#include <string>
using namespace std;

class vehicle {

    private :
        int max_speed ;
    public :
        string color ;

        void print(){
            cout<<"vehicle\n";
        }
        void display_color(){
            cout<<color <<endl;
        }
};

class car : public vehicle {

    private :
        string owner ;
    
    public :
        void print (){
            cout<<"car\n";
        }

};

class honda_city : public car {

    public :

        string model_number ;
        void print (){
            cout<<"honda\n";
        }

};

int main(){
   
    vehicle V1 ;
    V1.print();

    car C1 ;
    C1.print();

    honda_city H1 ;
    H1.print();

    honda_city* h2 = new honda_city;

    h2->print();
    car *c2 = nullptr;
    //anthough base class ptr can pt to the elments of children clsses but the can acces only those elmenets which 
    //belong to that base class
    
    c2 = &H1; //c2 can only acces the print of car or vehcle class but just because print() exists in the car class itself it wont check vehicle

    c2->print();

    vehicle *vp  = &H1;
    //vechicle class can pt to its children classes objects like cars and honda_city bt it can only acess vehicle objects
    //these things are decided at complile time i.e. which prin is to be used is decided at compile time hence this is an example oof compile time polimorphism
    vp->print();

    delete [] h2;



}