class vehicle {

    private :
        int max_speed;

    protected :
        int rating ;

    public :
        string color ;
        
        vehicle(int a){
            max_speed = a;
            cout<<a<<endl;
            cout<<"vehicle constructor \n";
        }
        void print (){
            cout<<"VEHICLE\n";
        }
};