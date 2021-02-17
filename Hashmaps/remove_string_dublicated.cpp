#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


string remove_dublicates(string s){
    string ans;

    unordered_map <char , bool > check ;

    for (auto x:s){

        if(check.count(x) > 0){
            continue;
        }
        else
        {
            check[x]=true;
            ans+=x;
        }
        
    }

    return ans;
}

int main(){

    string input;

    cout<<"enter string with dublicates : ";
    cin>>input;

    input = remove_dublicates(input);

    cout<<input<<endl;

}