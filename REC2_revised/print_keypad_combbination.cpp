#include<iostream>
#include<string>
using namespace std;


void print_combination(int n , string output , string key[]){

    //base case if input is 0 we prrint output
    if(n==0){
        cout<<output<<endl;
        return;
    }

    int my_digit = n%10;
    string my_chars = key[my_digit];
    
    if(my_chars.length()==0){
        print_combination(n/10,output,key);
    }else{
    
        for(int i = 0 ; i < my_chars.length() ; i++){

            print_combination(n/10 , my_chars.at(i)+output , key);

        }
    }


}

void printKeypad(int n){

   
    string key [] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
    string output = "";
    print_combination(n,output,key);

}

int main(){
     int n{0};
    cin>>n;
    printKeypad(n);
}