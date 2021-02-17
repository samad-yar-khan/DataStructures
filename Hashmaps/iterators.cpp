#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <map>



int main(){

    vector<int> vec1 {1,2,3,4,5,6,7,8,9,10}; 

    vector<int> :: iterator iterator_1 = vec1.begin();

    while (iterator_1 != vec1.end()){
        cout<<*(iterator_1)<<endl;
        iterator_1++;
    }

    unordered_map <string,int> ourmap;
    ourmap["ab"]=1;
    ourmap["bc"]=2;
    ourmap["cd"]=3;
    ourmap["de"]=4;
    ourmap["ef"]=5;
    ourmap["fg"]=6;
    ourmap["gh"]=7;
    ourmap["hi"]=8;
    ourmap["ij"]=9;
    ourmap["jk"]=10;

    unordered_map <string,int>::iterator it2 = ourmap.begin();

    while( it2 != ourmap.end() ){
        cout<<"Key = "<<it2->first<<"   Value = "<<it2->second<<endl;
        it2++;
    }

    map <string , int> map2;


    map2["deb"]=1;
    map2["bc"]=4;
    map2["cd"]=3;
    map2["de"]=2;
    map2["ef"]=5;
    map2["fg"]=6;
    map2["gh"]=7;
    map2["hi"]=8;
    map2["ij"]=9;
    map2["jk"]=10;

    map <string , int >::iterator it3 = map2.begin();

    while (it3  != map2.end()){
        cout<<"Key:"<<it3->first <<"  val:"<<it3->second<<endl;
        it3++;
    }

}
