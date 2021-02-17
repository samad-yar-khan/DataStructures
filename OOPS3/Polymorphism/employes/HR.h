class HR : public employee {

    public :

        int employees_under ;
        HR (string name ):employee(name){
            employees_under = 0;
        }

        int calc_salary(){
            return 10000*employees_under;
        }

};