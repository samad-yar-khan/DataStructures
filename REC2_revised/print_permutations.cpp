#include <iostream>
#include <string>
using namespace std;

void help (string input , string output){
    if(input.length()==0){
        cout<<output<<endl;
        return ;
    }
    
    int len = input.length();
    
    for(int i=0;i<len;i++){
        help(input.substr(0,i) + input.substr(i+1) , output+input[i]);
    }
      
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output;
    help(input,output);
    
}

int main(){
    
    cout<<"Enter input string : ";
    string input ;
    cin>>input;

    cout <<"PERMUTATIONS : \n\n";
    printPermutations(input);


}
