#include<iostream>
using namespace std;
#include <vector>
#include<string>


int main(){

    string s1;
    getline(cin,s1);

    vector<string> vec;

    int i = 0;
    int j=0;
    int len =0;

    while (s1.at(j)!='\0'){
        if(s1.at(j)==' '){
            vec.push_back(s1.substr(i,len));
            len=0;
            i=j+1;
            j++;
        }else{
            j++;
            len++;
        }
    }      

    for(int k=0 ; k<vec.size();k++){
        cout<<vec[k]<<endl;
    }
}