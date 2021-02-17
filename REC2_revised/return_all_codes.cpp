#include<iostream>
#include<string>
#include <string.h>

using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
      /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    //base case
    if(input.empty()){
        output[0]="";
        return 1;
    }
    int a='a';
    int my_num = (int)input[0]- (int)'0'; //covcrt string to int
    string temp_1;  //temps store my character after i converrt intigers to alphabets etc
    temp_1 = my_num+a-1;
    string temp_2;
    int my_num_2=0;
    //proceding if length is more than 1
    if(input.length()>1){
    for(int i=0;i<2;i++){
     my_num_2=10*my_num_2 +  (int)input[i]-(int)'0';
     }
    temp_2= my_num_2+(int)'a'-1;
    }
 
    temp_1 = my_num+a-1;
    
    
    string output_1 [5000];
    string output_2 [5000];
    
    int r1=0,r2=0;
    r1=getCodes(input.substr(1),output_1);
    
    
    int row=0;
    
    for(int i=0;i<r1;i++){
        output[row]=temp_1 + output_1[i];
        row++;
    }
    
    if( my_num_2<27 && my_num_2>0){
        r2 = getCodes(input.substr(2),output_2);
        for(int i=0 ; i<r2 ; i++ ){
             output[row]=temp_2 + output_2[i];
            row++;
        }
    }
    
    return row;
}