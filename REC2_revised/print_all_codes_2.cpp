#include <iostream>
#include <string>
using namespace std;

//this get_code function will covert our strings  input in form of intigers from [1 to 26] to strings 
//consisting of alphabbets from a to z (a==1 , b==2 , c==3 ....z==26)
string get_code(string input){

    string output_code ="";
    char a = 'a';

    if(input.length() == 1){

        output_code += input[0]-'1'+ a;

    }else if(input.length() == 2){

        //below steps are used to converts strings to intiger form
        int tens  = input[0] - '0' ;
        int ones_place = input[1] - '0'; 


        int intiger_code = tens*10 + ones_place - 1 ;
        if(intiger_code <= 25){ //we can only form an alphabte if our intigeer_code+1 is more than 0 and less than 26    
            output_code += a+intiger_code;
        }else{
            output_code = "";
        }
    
    }
    
    return output_code;
}

void printAllPossibleCodes(string input,string output){

    if(input.length()==0){
        cout<<output<<endl;
        return;
    }

    //now we either add our first digits code to op c1
    //or we add the code of first two digits c2

    string c1 = get_code(input.substr(0,1));
    
    printAllPossibleCodes(input.substr(1) , output+c1);

    if(input.length() > 1){
        string c2 = get_code(input.substr(0,2)); //we ll onlu add this if this isnt empty pr if our firsttwo digits form an alphabet
        if(c2.length()>0){
            printAllPossibleCodes(input.substr(2) , output + c2);
        }
    }

}

void printAllPossibleCodes(string input) {

    string output = "";
    printAllPossibleCodes(input,output);

}

int main(){
    string input ;
    cout<<"Enter the string input : ";
    cin>>input;

    cout <<"All codes : \n";
    printAllPossibleCodes(input);

}