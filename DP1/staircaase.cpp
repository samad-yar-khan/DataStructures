/*
Code : Staircase using Dp
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/



#include <iostream >
using namespace std;

//recursice approach

long staircase_REC(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    //base 
    if (n == 0){
        return 1;
    }
    
    if(n < 0){
        return 0;
    }
    
	return  staircase_REC(n-1) +  staircase_REC(n-2) +  staircase_REC(n-3);
    
}



//memotization approach

long helper (long* arr , int n){
    
    //base case 
    if(n == 0 ){
        return 1;
    }

    //IS
    if(arr[n] != -1){
        return arr[n];
    }
    
    
    //IH
    long x=0 , y = 0 , z = 0 ;
    
    if(n>=1){ //we can only go up a staiir if there is a stair
    	x = helper (arr , n-1);
    }
    
    if(n>=2){//we cant only go up 2 stairs when there are 2 or more stairs
        y = helper (arr , n-2 );
    }
    
    if(n >= 3){ //we can only go up 3 sttairs when there are 3 or more stairs
        z = helper ( arr , n-3);
        
    }
    
    arr[n] = x+y+z;
    return arr[n];
    
}


long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
   
    //in this array each arr[n]  will contain the no of ways to climb n steps
	long *arr = new long [n+1];
    
    //in memotoztion u just initialize thw hole arr to -1
    for(int i {0} ; i <  n+1 ; i++){
        arr[i] = -1;
    }
    
    long ans =  helper(arr, n);
    delete [] arr;
    
    return ans;
    
    
}


//dynamic proramming approach
long staircase_dp(int n){

    //in this array each arr[n]  will contain the no of ways to climb n steps
	long *arr = new long [n+1];
    //there is 1 way to go up zero stairs 
    arr[0] = 1;
    
    for(int i = 1 ; i < n+1 ; i++){
        
        long x = 0, y=0 , z=0;
        
        if (i >=1){ 
            x = arr[i-1];
        }
        if (i >= 2){
            y = arr[i-2];
        }
         if (i >= 3){
            z = arr[i-3];
        }
        arr[i] = x+y+z;
    }
    
    long ans = arr[n];
    return ans;
 
    
    
}