class employee{

    protected :

        int employee_ID;

    public:

        const string name ;
        int age ;   
        int experience ;

        employee (string name) : name(name){
            this -> age = 0 ;
            this->experience = 0 ;
        }
        void set_details (int age , int exp){
            this->age = age ;
            this->experience = exp;
        }
        void print_details (){
            cout<<"NAME : "<<this->name<<'\n';
            cout<<"AGE : "<<age<<endl;
            cout<<"EXPERRNCE : "<<experience<<endl;
        }


        //pure virtual function
        virtual int calc_salary() = 0;
        

};
