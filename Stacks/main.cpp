#include <iostream>
using namespace std;

#include "stack_LL.h"



int main() {

    // stack <int >s1;
    // cout<<s1.pop();
    // s1.push(1);
    // s1.push(2);
    // s1.push(3);
    // s1.push(4);
    // s1.push(5);
    // s1.push(6);
    // s1.push(7);
    // s1.push(8);

    //cout<<s1.pop()<<"\n";
   

   stack <char> char_stack ;

   int i = 'A';
   
   for( ; i<=(int)'Z' ; i++){
       char_stack.push(i);
   }

   while (char_stack.getsize() !=0){
       cout<<char_stack.pop()<<endl;
   }

   
}