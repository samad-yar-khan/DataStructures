#include "car.h"

class honda_city : public car{

    public:

        int license_plate ;
        bool rim ;

        honda_city(int m_s , int num_tyre , string color , int num_gear ) : car(m_s , num_tyre , color , num_gear){
            license_plate = 0;
            rim = false;
            cout<<"honda city contructor called!\n";

        }
        ~honda_city(){
            cout<<"\nhonda city distructor !\n";
        }

};

int main(){

    vehicle v1(10,4,"Vehicle");
    v1.color = "RED";
    //v1.num_tyres = 8; //this will give me an error becase its a proteted property


    car car_1(20,4,"red",20);
    car_1.color = "BLUE";
    car_1.num_gear = 25;
    //car_1.num_tyres = 61 ; //this will give an error becase num tyres is protected 
    car_1.set_num_tyre(30);
    car_1.print();
    cout<<"\n\n";
    honda_city (20 , 4 , "RED" , 7);
}