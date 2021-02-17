#include <iostream>
using namespace std;
#include "pair.cpp"
 //nopw the Pair is class tenplate and its vlements can just be of aany type
 //koi bhu type ka  pair banaa
int main(){

    //tyemplates is a very stromng feature
    Pair <int> p1;
    p1.set_x(10);
    p1.set_y(20);
    p1.display();

    Pair <char> c1;
    c1.set_x('a');
    c1.set_y ('b');
    c1.display();

    Pair <double > d1;
    d1.set_x(2.3);
    d1.set_y(45.39);
    d1.display();
}