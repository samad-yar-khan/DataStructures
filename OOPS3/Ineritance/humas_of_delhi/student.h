#include "humans.h"
#include <iostream>
//public access specifier for inheritance 
class student:public human{

    private :
        int percentage ;
        char grade ;
    public :
        
        string stream;
        
        //i can acces the human eheirited pproperties
    student(){
        cout<<"Student constructor "<<endl;
    }
    void print(){
 //       cout<<IQ<<endl; //gives error because wasnt inherted
        cout<<name<<endl;//inherted 
        cout<<age<<endl;//inherted
        cout<<grade<<endl;
        cout<<percentage<<endl;
        cout<<weight<<endl;
        cout<<stream<<endl;
        
    }
    ~student (){
        cout<<"Student Distructor "<<endl;
    }

};