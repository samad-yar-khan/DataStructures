#include <iostream>
#include <string>
using namespace std;


void printKeypad_2(int num, string output,string *ref){
    if(num==0){
        cout<<output<<endl;
        return;
        }
    int small_output = num/10;
    int my_num =num%10;
    int my_len = (ref[my_num]).length();
    for(int i=0;i<my_len;i++){
        printKeypad_2(small_output,(ref[my_num].at(i))+output,ref);
        }
    
    }
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    string ref[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
              //0  1    2     3    4      5    6      7      8     9
    printKeypad_2(num,output,ref);
    return;
    
}

