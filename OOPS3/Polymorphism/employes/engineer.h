class engineer : public employee {

    public :

        int num_languages;
        int stars_codechef;

        engineer(string name):employee(name){
            num_languages = 0 ; 
            stars_codechef = 0 ;
        }

        int calc_salary(){

            int total_salary = 1000*(5*stars_codechef + 10*num_languages) ;
            return total_salary;
        }

        

};