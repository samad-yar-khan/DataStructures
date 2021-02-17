class managers:public employee{

    public:

    int marks_mba ;

    managers(string name ):employee(name){

        marks_mba = 0;
    }

    int calc_salary(){
        return 10000*marks_mba;
    }


};