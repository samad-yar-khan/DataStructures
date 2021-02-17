#include<string>
#include<iostream>

using namespace  std;

//parent class
class human {
    
    private :
        int IQ; //not inherted in any case

    protected :
        int age ;
        int phone_number ;
        int weight ;

    public :
        string name ;

        human(){
            cout<<"human constructor"<<endl;
        }
        ~human(){
            cout<<"human distrcutor "<<endl;
        }

};