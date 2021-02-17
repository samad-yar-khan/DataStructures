#include<iostream>
#include <string>

using namespace std;

int returnPermutations(string input, string output[]){

    //base case
    if(input.length() == 1){
        output[0] = input;
        return 1;
    }

    //we crreate an auxilarry op
    string* small_output = new string [5000];
    int rows = returnPermutations(input.substr(1) , small_output);

    //now we need to place our fist char in all the outputs

    int k = 0 ;
    for(int i{0} ; i < rows ;  i++){
          //this will flill first char of i/p in all gaps or places of o/p
        for(int j = 0 ; j < small_output[i].length() + 1 ; j++){
            output[k] = small_output[i].substr(0,j) + input[0] + small_output[i].substr(j);
            k++;
        }
    }

    delete [] small_output;
    return k;

}

int main(){
    
    string input;
    cout<<"Enter input : ";
    cin>>input;

    cout<<"PERMUTATION :\n\n";

    string output[10000];
    int output_size = returnPermutations(input , output);
    for(int i{0} ; i < output_size ; i++){
        cout<<output[i]<<"\n";
    }

}














