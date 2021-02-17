/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include<iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    //base case 
    if(num==0){
        output[0]="";
        return 1;
    }
    string KP [10] {"" ,"", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
   
    int small_arr =  keypad(num/10 ,output);
    int last_num = num%10;
    int my_size=(KP[last_num]).length();
    
    for(int i=1;i<my_size;i++){
        for(int j=0;j<small_arr;j++){
            output[j+i*small_arr]=output[j]+KP[last_num][i];
        }
    }
    for(int i=0;i<small_arr;i++){
       output[i]=output[i]+KP[last_num][0];  
    }
    
    return my_size*small_arr;
}