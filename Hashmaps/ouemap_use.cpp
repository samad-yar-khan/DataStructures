#include <iostream>
using namespace std;
#include "hashmaps.h"
#include <string>



int main(){

    ourmap <int> map;
    // map1.insert("samad" , 100);
    // map1.insert("samar" , 5);
    // map1.insert("abu",10);

    // cout<<"abu "<<map1.get_value("abu")<<endl;
    // cout<<"samad "<<map1.get_value("samad")<<endl;
    // cout<<"samar "<<map1.get_value("samar")<<endl;

    string s{"SAMAD"};
    map.insert(s,10);
    // cout<<map.loadfactor()<<endl;
    char t = '0';
    for(int i=0  ; i< 20 ; i++){
        char t2= t+i;
        map.insert(s+t2,i);
        cout<<map.loadfactor()<<endl;
    }
    

}

