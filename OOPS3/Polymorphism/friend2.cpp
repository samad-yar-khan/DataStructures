#include<iostream>
#include<string>

using namespace std;


class teacher {

    private :

        int age ;
        int salary ;
    
    public :
        
        void print();
        void print_age();
        void print_income();
        void print_IQ();
};

class human {

    private :
        int age ;
        int IQ;
        int income ;

    public:
        string name ;
        string father_name ;

    friend class teacher ;
};

void teacher :: print(){
        human H;
        H.name = "SAMPLE NAME";
        H.age = 30;
        H.IQ = 100;
        H.income = 100000;
        cout<<"NAME : "<<H.name<<endl;
        cout<<"AGE : "<<H.age<<endl;
        cout<<"IQ : "<<H.IQ<<endl;
        cout<<"INCOME : "<<H.income<<endl;
}
void teacher :: print_age(){
    human H;
    H.age = 30;
    cout<<"AGE : "<<H.age<<endl;
}
void teacher :: print_IQ(){
    human H;
    H.IQ = 0 ;
    cout<<"IQ : "<<H.IQ<<endl;
}

void teacher:: print_income(){
    human H;
    H.income = 10000;
    cout<<"INCOME : "<<H.income<<endl;

}

int main(){

    teacher T1;
    T1.print();
    cout<<"*****\n";
    T1.print_age();
    cout<<"*****\n";
    T1.print_income();
    cout<<"*****\n";
    T1.print_IQ();
}
