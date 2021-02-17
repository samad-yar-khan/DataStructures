/*
Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/
/*
LOGIC 
our basse case says that if an emepty string is passed , we will retur an empty string aswell

-> we can either add our firt elements codein output string or oour first two elelments code so we take two cases
1) incnlude first elments code
2)include the code of first two elments

using our string values "1","2","3--"26" we try to convert this yo intiger values of 1,2,3,4,,,26
also we check ki code 26 se bada to nhi hai

then uske bad uske according character codes likh sakte hai


*/

#include <iostream>
#include <string>
using namespace std;



int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
   // base case
   if(input.length() == 0 ){
       return 1; 
   }

    char a = 'a';
   //we can have two small_output strings 
    string case1[10000];
    string case2[10000];

    int so_2 =0 ;
    
    int code_1_int = 0 ;
    code_1_int += (input[0] - '0' ); //converrt char too int
    int code_2_int =  0 ;
    code_2_int = 10*code_1_int + (input[1] - '0' ); //("12" = 1*10 + 2  ) "1" lo int mai covert jara then mutiply by 10 and add 2

    int so_1 = getCodes(input.substr(1) , case1); //pehle digit dalenge
    
    if(input.length() > 1 && code_2_int < 27){
        so_2 = getCodes(input.substr(2) , case2);
    }

    //now we assume ki hamaro case1 and case2 arrays  bhar gyi , we just need to append our int ke codes in fronta and add to total output

    char code_case_1 = a+code_1_int-1;
    char code_case_2 = a+code_2_int-1;

    for(int i = 0 ; i < so_1 ; i++){
        output[i] = code_case_1+case1[i]; 
    }
    for(int i = 0 ; i < so_2 ; i++){
        output[i+so_1] = code_case_2+case2[i];
    }

    return so_1+so_2;
    

}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
