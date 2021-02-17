class truck : virtual public vehicle{

    public :

        int capacity_rating ;
        truck() : vehicle(3){ 
            cout<<"Truck contructor !\n";
        }

};