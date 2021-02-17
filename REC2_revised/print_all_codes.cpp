#include<iostream>
#include<string>
using namespace std;

void help (string input , string output){
    if(input.length()==0){
        cout<<output<<endl;
        return ;
    }   
    
    int a='a';
    
    string my_alpha_1 , my_alpha_2 ;
    
    int my_num = (int)input[0]-(int)'0';
    my_alpha_1= my_num + a -1;
    
    int my_num_2=0;
    
    if(input.length()>1){
    for(int i=0;i<2;i++){
     my_num_2=10*my_num_2 +  (int)input[i]-(int)'0';
     }
    my_alpha_2=my_num_2 + a -1;
    }
    
    help(input.substr(1) , output + my_alpha_1 );
    
    if(0<my_num_2 && my_num_2<27){
        help (input.substr(2) , output + my_alpha_2 );
    }
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output;
    help ( input , output );
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}


