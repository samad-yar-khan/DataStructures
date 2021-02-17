#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input , string output){
		
	//base case 
    if(input.length() == 0 ){
        cout<<output<<endl;
        return ;
    }
    
    //induction hypothesis
    for(int i = 0 ; i < input.length() ; i++){
        
        string small_input = input.substr(0,i) + input.substr(i+1);;
        printPermutations(small_input , output+input.at(i));
                          
    }
    
    
}

void printPermutations(string input){
	
    string output = "";
    printPermutations(input,output);
    
}

int main(){
    
    cout<<"Enter input string : ";
    string input ;
    cin>>input;

    cout <<"PERMUTATIONS : \n\n";
    printPermutations(input);


}