class vehicle {

    private :
        int max_speed;

    protected :
        int rating ;

    public :
        string color ;
        
        vehicle(){
            cout<<"vehicle constructor \n";
        }
        void print (){
            cout<<"VEHICLE\n";
        }
};