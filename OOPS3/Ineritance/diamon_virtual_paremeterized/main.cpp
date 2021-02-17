#include<iostream>
#include<string>
using namespace std;

#include"vehicle.cpp"
#include"truck.cpp"
#include"car.cpp"
#include"bus.cpp"

int main(){
    bus bus_1 ;

    //ab abigityu remove hogyi hai due to vertual base class concept and now we dont have any copied or same propertied of vehicle clas atleast
    bus_1.print(); //cars ka print call hoga kyuki wo hamse zada pas hai and hamari hi arent class  mai dircyy hai
    bus_1.truck :: print(); // we can explicityly call vehicle wala this way
    //5 oprint hoga showing ki vehicle ka contructor bus call kar rha hai 
    //naki truck aur car ka a 
    
}