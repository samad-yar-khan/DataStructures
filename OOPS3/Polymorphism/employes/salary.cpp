#include<iostream>
#include<string>
using namespace std;
    
#include"employee.h"
#include"HR.h"
#include"engineer.h"
#include"managers.h"

int main(){

    HR hr1("Samad");
    hr1.age = 10;
    hr1.employees_under = 10;

    engineer E1("ABU");
    E1.stars_codechef = 10;
    E1.num_languages = 20;

    managers m1("Areeb");
    m1.marks_mba = 20;

    employee** list = new employee*[4];
    list[0] = &hr1;
    list[1] = &m1;
    list[2] = &E1;

    for(int i = 0 ; i < 3 ; i++){
        cout<<"Salary : "<<list[i]->calc_salary()<<endl;
    }
}

