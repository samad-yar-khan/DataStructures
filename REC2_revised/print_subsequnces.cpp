#include<iostream>
#include<string>
using namespace std;

void print_subs(string input , string output){

    //base case
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }

    //we either add the first char to the output or we dont
    print_subs(input.substr(1) , output); //didnt add first char to op
    print_subs(input.substr(1) , output+input[0]);
    
}

int main(){

    cout<<"Enter string : ";
    string input ;
    cin>>input;
    //we pass an empty string as op
    string output = "";

    print_subs(input , output);

    }
