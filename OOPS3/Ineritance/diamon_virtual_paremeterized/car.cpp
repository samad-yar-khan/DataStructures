class car:virtual public vehicle {

    public :
        int num_gears ;

        car():vehicle(4){
            cout<<"CAR contstructor \n";
        }
        void print (){
            cout<<"CAR\n";
        }

};