template <typename T>
                      
class Pair {
    private:
    T x;
    T y;
    
    public :

    //setters
    void set_x (T x){
        this->x = x;  //copy assignment operatpr works here
    }

    void set_y (T y){
        this->y= y;  //copy assignment operatpr works here
    }

    //getters
    T get_x (){
        return this->x;
    }

    T get_y (){
        return this->y;
    }

    void display(){
        cout<<x<<" "<<y<<"\n";
    }
};

