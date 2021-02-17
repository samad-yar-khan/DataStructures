#include<iostream>
using namespace std;

//if we declare dome func of bus to be  friend func of vegicle it must be declareed before to avoid compiler errors
//coding ninjas example 

class bus{

    public :
        //yaha bas friend func ki definition ayegi , declaration globally hoga
        void print();

};

//must be declared aswell tp avoid error
void display();

class vehicle {

    private:
        int x;
    protected :
        int y ;
    private:
        int z ;

        //frined function kis acces specifie rke under ho fararkkk nhi padhta as its not a part of this class
        friend void bus :: print();
        friend void display();//a global func not beonging to any class can also be our friend 

};

//declarartion of the friend func must be global like this
void bus :: print(){
    //to acces private / protxted propertes us class ka obj bhi banan padega

    vehicle v;
    v.x = 100 ;
    v.y = 200;
    v.z = 300;
    cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;

}

//a gloal funnc whihc is  a friend of our vehiclle class
void display() {
    vehicle v2;
    v2.x= 1;
    v2.y=2 ;
    v2.z = 3;

    cout<<"\nA typical display of components of  vehicle looks like this \n";
    cout<<"x : "<<v2.x<<"\n";
    cout<<"y : "<<v2.y<<"\n";
    cout<<"z : "<<v2.z<<"\n";

 }

int main(){

    bus b1;
    b1.print();

    display();;


}