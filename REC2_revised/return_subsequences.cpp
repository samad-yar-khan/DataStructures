#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int sub_sequences(string input , string output []);

int main(){

    string input;
    cin>>input;
    string* subsequnces = new string[(int)pow(2,input.length())];
    int output_size = sub_sequences(input,subsequnces);
    for(int i{0} ; i < output_size ; i++){
        cout<<subsequnces[i]<<endl;
    }
    delete [] subsequnces;
}

int sub_sequences(string input , string output []){

//base case if my strig is empty , i ll ad an emptt string to the output and return
    if(input.empty()){
        output[0] ="";
        return 1;
    }

    //IH we call rec on the sbustr and expect it to get the ans and then just see how we can make oour output 
    //from this output
    string small_string = input.substr(1);
    int small_output_size = sub_sequences(small_string,output);

    //now we assume ki ye output mai sahi subseqeunces le ara and we also have the now of subsseqneces in output
    //now all we need to do is copy al subsequnced and just append our first elment to the front and add these to output

    for(int i{0} ; i < small_output_size ; i++){

        output[i+small_output_size]=input[0] + output[i];

    }

    //now we have added our first elment tp the front of eachh subseq to the no of elmentss in output has doubles 
    //or
    // no of rows of strngs has doubled

    return 2*small_output_size;

}