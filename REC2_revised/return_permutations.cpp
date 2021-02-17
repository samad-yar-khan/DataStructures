#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
   //base case
    if(input.length()==1){
        output[0]=input[0];
        return 1;
    }
    string output_2 [1000];
    int row =0;
    int small_output = returnPermutations(input.substr(1),output_2);
    int len = output_2[0].length();
    for(int r=0;r<small_output;r++){
        output [row]=input[0]+output_2[r];
        row++;
        for(int j=1;j<len;j++){
            output[row++]=output_2[r].substr(0,j) + input[0] + output_2[r].substr(j) ;
        }
        output[row++]=output_2[r] + input[0];
        
    }
    
    return row;
}
