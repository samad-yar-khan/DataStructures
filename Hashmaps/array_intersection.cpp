/*
Code : Maximum Frequency Number
Send Feedback
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Most frequent element
Constraints :
0 <= N <= 10^8
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/

#include<iostream>
using namespace  std;
#include<unordered_map>

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */

    unordered_map <int , int> map;

    for(int i{0} ; i< size1 ; i++){

        if(map.count(input1[i]) < 1){
            map[input1[i]]=1;
        }else{
            map[input1[i]]++;
        }
    }

    for(int i{0} ; i<size2 ; i++){
        if(map.count(input2[i])>1){
            cout<<input2<<endl;
            map[input1[i]]--;
           if(map[input1[i]] == 0){
                map.erase(input1[i]);
            }
            
        }
    }
}

int main() {
    cout<<"Enter size of array 1 "<<endl;
    int n;
    cin>>n;
    
    cout<<"enter elmenets - ";
    for(int i{0} ; i<n ; i++){

    }
}
