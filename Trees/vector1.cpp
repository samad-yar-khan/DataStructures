#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector <int> vec1{1,2,3,4,5,6,7};
    
    for(auto const &a:vec1){
        cout<<a<<" ";
    }

    cout<<"\ninitial size"<<vec1.size()<<endl;
    vec1.pop_back();
    cout<<"\nfinal size"<<vec1.size()<<endl;

    vector<char> vec2;

    for(int i =0 ; i<26;i++){
        
        cout<<"size "<<vec2.size()<<endl;
        cout<<"capacity "<<vec2.capacity()<<endl;
        vec2.push_back('a'+i);
        cout<<"elemnt added - "<<vec2.at(i)<<endl;
    }
       cout<<"size "<<vec2.size()<<endl;
        cout<<"capacity "<<vec2.capacity()<<endl;
}
