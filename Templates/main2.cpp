#include <iostream>
#include <string>
using namespace std;
#include "pair2.cpp"

int main(){

    //real powwer of templates, we can set the type of our properties whatever we want . ham kisi bhi do cheez ka pair
    //bana sakte hai
    Pair <int , double> p1 ; 
    p1.set_x(1);
    p1.set_y(3.14);
    p1.display();

    Pair<char , int> p2;
    p2.set_x('a');
    p2.set_y('1');

    p2.display();
    //in your template you can basically use another class as your own class ke data memnber ka type
    //yaha mera T striung type ka kardo
    //v int type ka
    //har jagah object mai T string se replace hoga 
    // v int se replace joga 
    //so this works like a function
    //where intead of passing values as paramatertes , you pass data type/class as your parameter v
    Pair <string , int > p3;
    string name {"Samad Yar Khan"};
    p3.set_x(name);
    p3.set_y(95);
    p3.display();

    cout<<"TRIPLET !\n";
    //making a triplet ising my pair
    //T becomes pair type
    //V bcomes int
    //further we spscify that T consists of T' and V' which are of type int
    //so we baically have a triplet
    Pair <Pair<int , int >, int> p4; //my pair p4 consists of a pair of intigers (x) and a intiger y

    p4.set_y(3); //ye mai simply int pass karna hai beecaise V was replaced by int and y is out type int

    //but our x is of ttpe pair , so in its getter we must pass another pair
    
    Pair <int , int > p_x; //because x  bhi pair of ints hai
    p_x.set_x(1);
    p_x.set_y(2);
    
    //p_x is kind of a blue print of x so we set p4 ka x this 
     
    p4.set_x(p_x); //this p_x gets copied to p4 ka x using inbult 
                   //copy assignment operator (=).

    cout<<p4.get_y()<<" ";// simple get use mardenge for y wo int ki value uthalkar dedega y se
    
    //when we simply use get on x , hamara pura x nam pair uthke ajayega 
    //to what we need to do it ki ye jo pair uthke aye iske x and y ko lekar aye
           //pair x
    cout<<(p4.get_x()).get_x()<<" "; // fetch the value of x data memeber which kept in the pair named x
    //p4 mai se x uthakar lao. ye x bhi pair hai. to is x ka bhi x hoga . wo uthakar le ao

    cout<<(p4.get_x()).get_y()<<" "<<endl;
}