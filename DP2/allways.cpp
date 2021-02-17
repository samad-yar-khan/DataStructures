/*
All possible ways
Send Feedback
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)
Output Format :
Count
Constraints :
1 <= a <= 10^5
1 <= b <= 50
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
*/

#include<iostream>
#include<cmath>
using namespace std;


int allways(int a , int b ,int i = 1){

//BC
if(a==0 && i!=1){
    return 1; //we have reached a point
}

//
if(a<=0 ||( a==0 && i ==1 ) || pow(i , b) > a){
    return 0;
}

//IH 
//ours not choosen 
int case1 = allways(a , b , i+1);
int case2 = allways(a - pow(i,b) , b , i+1);

return case1+case2;




}



int main(){

    cout<<"-> This program takes two intigers A  & B as input ";
    cout<<"\n-> It will return the number of ways we can represent a as uniquieq intigers i power of b "<<endl;;
    cout<<"Enter a number A and B : ";
    int a= 0, b =0;
    cin>> a>>b; 

    cout<<"ALLWAYS TO REPRSENT A IN POWERS OF B "<<allways(a ,b )<<endl;
}
