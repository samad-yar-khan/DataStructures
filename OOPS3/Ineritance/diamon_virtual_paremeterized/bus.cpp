class bus : public car , public truck {

    public :
        string school ;

        //either we entroduce a aprint here to avoid the ambiguity due to multiiple cpoies of vehicle
        //due to diamond inheritnace or we use scope resulouton operatr to specify the exat propert and parent class 
        //we are refreing to

        //but here we have used virtual keywords to make vehicle our virtual base class of car and truck
        //to avoid mltiple copies of same class , but the actual contructor of vehicle is called by bus 
        //and car and truck are provided pointers to the object vehicle 
        //and asli objects - car , truck , vehice -> hamare bus ke pas rakhe hai

        //yaha parameterized contructor hai vehicle ka 
        //so sare chhild classes se explicityly parametretzied conctructor call hoga , including the bbus class

        bus():vehicle(5){
            cout<<"BUS constructor \n";
        }

};