#include<iostream>
#include<string>
using namespace std;
#include "student.cpp"
#include "teacher.cpp"

//as student class is wriitten befre tracher , so its contrutore will be called before tecaher class and the teacher and then TA

class TA:public student, public teacher {

    public :
    string name;

    // void print(){
    //     cout<<"print ta";
    // }

    TA(){
        cout<<"TA constrcutor \n";
    }
    


};

int main(){

    TA ta_1 ;
    //ta_1.print(); //will give error because print func exits in both our parents classes so compiler wont knwi which one to use 
    //and this raises ambiguity so we need to telel compiler which parent clases prooperty is to be used
    ta_1.student::print();
    ta_1.teacher::print();
    //this signifies that we need to use pprint func of base class student

    //if a ffunction // property is present is all - children/derived and all the base/parent classesthen we can diretly call that property and 
    //and the one from our children class will be called 
    //so first compiler looks for property in the child class, then looks for it in the parent classes
    ta_1.name ="SAMAD";
    cout<<ta_1.name;

    return 0 ;

}
