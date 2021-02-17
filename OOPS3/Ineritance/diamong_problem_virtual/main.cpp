#include<iostream>
#include<string>
using namespace std;

#include"vehicle.cpp"
#include"truck.cpp"
#include"car.cpp"
#include"bus.cpp"

int main(){
    bus bus_1 ;

    //we either introduce a print in our bus class t remive the ambiguity of print 
    //actually a vehicle is crated by car and truck both and then we ednup with  multiple copies
    //of same data members of vehcle in the final bus cllass
    //to remove this ambiguity we can also specify which copy of the property we wanna use

    // bus_1.color = "RED"; ambigity error

    bus_1.car  :: color = "RED ";
    bus_1.truck :: print(); //this will print the print func of vehicle because truck doesnt have a loclal print
    bus_1.car :: print (); //this will print the print fucn of car because our car has local func print whihc is called before vehicle parent is even checcked
    
}