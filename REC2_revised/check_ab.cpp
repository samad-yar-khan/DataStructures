#include<iostream>
#include<string>
using namespace std;

bool check_ab(string input){

    //base
    if(input.size() == 0){
        return true;
    }

    //check
    if(input[0] == 'a'){
        if(input[1] == 'b' && input[2]=='b'){
            return check_ab(input.substr(3));
        }
        else{
            return check_ab(input.substr(1));
        }
    }else{
        return false;
    }
}
int main(){

    cout<<"Enter input :: ";
    string input ;
    cin>>input;
    cout<<check_ab(input)<<endl;

}

