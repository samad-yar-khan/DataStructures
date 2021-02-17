#include<iostream>
using namespace std;
#include<unordered_map>
#include<string>

int main(){

    unordered_map <string , int> map;

    pair <string , int>  p2 ("sameer" , 2)  ;;
    map.insert(p2);
    cout<<map.count("sameer");
    map["samad"] = 1;
    map["samad"] ++;

    cout<<map["samad"] ;

    cout<<"\n"<<map.size()<<endl;
}