#include<iostream>

#include "vehicle.h"

//SYNTAX
// class child_class_name  : acess_sprcifer parent_class {
//------------------------------------------------------
//}

/*
Now this acess specifier can be 
->public - In case of public specifier ->private propertier are not inherted 
                                        ->protected properties of parent become pprotected properties of chil
                                        ->public properties of parent become public properties of chils 

->protected - In case of protected specifier -> private propperties are not inherited 
                                             -> protected properties of parent become pprotected properties of child
                                             -> even the public properties of parent become the proteted propertied of child
                                             -> IN SHORT pvt to inherit hoti nhi , jo inherit hingi wo protected banjaynegi hamari class ki

->private - In case of protected specifier  --> private propperties are not inherited 
                                             -> protected properties of parent become private properties of child
                                             -> even the public properties of parent become the private propertied of child
                                             -> IN SHORT pvt to inherit hoti nhi , jo inherit hingi wo private banjaynegi hamari class ki
*/

class car : public vehicle{
    public:
    
    int num_gear; //this is its own property and the rest are inherted

    //num tyres is set as our protected property sand must be initilised using stetters

    void set_num_tyre(int num){ //inherted
        this->num_tyres = num;
    }



    //paramertized contsrutor to use paremetrirseed contrutor of parent and to avoid error
    car (int m_s , int  num_tyres , string color , int num_gear ):vehicle(m_s , num_tyres , color) {
        this->num_gear = num_gear;
        cout<<"car constructor\n";
    }
    //what we did above is that we explicityly told our coplier to use the parameteriseed contrucor of our parent class i.e. VEHICLE
    //this is because by default or implecittly our defult contructor for vehicle class would have been called but that doente exist
    //and would have lead to errors 
    //the below fucntion wouldd throw off an error because it emplicitly calls my non existant default constructor of vehicle class befpre the creation of car\
    // 
    // car(int num_tyres){
    //     this->num_tyres=num_tyres;
    // }

    void print(){
        cout<<"NUM  TYRES : "<<num_tyres<<endl;
        cout<<"COLOUR : "<<color<<endl;
        cout<<"NUM GEARS : "<<num_gear<<endl;
    }
    ~car(){
        cout<<"car destructor\n";
    }
    
    
};