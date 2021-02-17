#include<string>
#include<iostream>
using namespace std;


class vehicle {

    private: //cant be acceses outise the class
        int max_speed;
    
    protected: //can be accessees outise the class only by children class 
        int num_tyres ;

    public: //can be accses outside class

        string color;

        //paramtertized constrcutor 
        vehicle (int m_s , int num_tyres , string color ){
            max_speed = m_s;
            this ->color = color ;
            this-> num_tyres = num_tyres;
            cout<<"Paramterised con4tructor of vehicle \n";
        }
        ~vehicle(){
            cout<<"vehicle destructor\n";
        }
};

