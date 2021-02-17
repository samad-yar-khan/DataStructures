
#include<iostream>
#include<string>
#include<climits>
using namespace std;

int keypad(int num , string output[] ,const string keys[]){

    //base case
    if(num==0){
        output[0] =""; //0 pe empty string
        return 1;
    }

    //induction hypothesis
    int small_num = num/10;
    int our_digit =  num%10;

    int small_op_size = keypad(small_num , output , keys );
    //we asume ki hamarae output me sare cominations gaye honge 

    //now we need to see ki hamare pas kitn characters har
    int our_length = keys[our_digit].length();

    //ab length-1 times copy kardo and place each char in front later
    for(int i{0} ; i < (our_length-1)*small_op_size ; i++){
        output[small_op_size+i] = output[i];
    }

    for(int i{0} ; i < keys[our_digit].length() ; i++){

        for(int j{0} ; j<small_op_size ; j++){

            output[i*small_op_size + j] = output[i*small_op_size + j] + keys[our_digit].at(i);

        }
    }

    if(keys[our_digit].length()>0){
        small_op_size=small_op_size*keys[our_digit].length();
    }
    return small_op_size;


}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string key [] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
    return keypad(num , output , key);

}

int main(){
    
    cout<<"Enter digits : ";
    int n{0};
    cin>>n;

    string output [1000];

    int op_size = keypad(n, output);

    for(int i{0} ; i < op_size ; i++){

        cout<<output[i]<<endl;

    }


}
