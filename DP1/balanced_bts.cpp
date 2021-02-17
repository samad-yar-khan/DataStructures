/*
Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315

*/

#include <iostream>
using namespace std;
#include<cmath>

/* CRUX
see we use the recursive logic by imagining left ans right sub trees
base case null tree and tree ht 1

let tree height be h
then in balanced condition
a)left & right sbtrees have ht h-1
b)keft has ht h-1 & right has hieght h-2
c)left has ht h-2 & right has ht h-1

we smm all casea ans return
to keep answers within bound we use a mood opertar 
along with that we use typecasting to long so  that the temporary contaioners 
where calculation happens are a little larger insize
and after mod they retrn bact to int


*/

//recursive method

int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.

 */
    
	//base case
    if(h <=1){
        return 1;
    }
    
    int mod = pow(10,9) + 7;
    
    //Induction hypothesis
    long  case1 = balancedBTs(h-1)%mod;
    long  case2 = balancedBTs(h-2)%mod;

    
    //inducron step
    long  x=case1*case1%mod;
    long  y=case2*case1%mod;
    long  z=case1*case2%mod;

    
    int ans = (x+y+z)%mod;
    
    return ans;


}



//memotization
int help (int*arr , int h ){
    //base
    if(h<=1){
        return 1;
    }
    
    //is
    if(arr[h] != -1){
        return arr[h];
    }
    
    //ih
	int mod = (int)pow(10,9) +7;
    int x = help(arr , h-1);
    int y = help(arr , h-2 );
    
    int temp1 = (((long)(x)*x)%mod);
    int temp2 = (((long)(x)*y)%mod);

     arr[h] = ((long)temp1 + 2*temp2)%mod;
	
	return arr[h];
	
}

int binaryTreesOfHeightH_memo(int h) {
    // Write your code here
	int mod = (int)pow(10,9) +7;
    
    int *arr = new int[h+1];
    for(int i{0} ; i <  h+1  ; i++){
        arr[i] = -1;
    }
    
    int ans = help(arr , h);
    return ans;
    
}


//dynamic proramming O(n)
int binaryTreesOfHeightH_dp(int h) {
    // Write your code here
	int mod = (int)pow(10,9) +7;
    
    int *arr = new int[h+1];
    for(int i{0} ; i <  h+1  ; i++){
        arr[i] = -1;
    }
    arr[0] = 1; //null tree
    arr[1] = 1; //ht 1
    
    for(int i{2} ; i < h+1 ; i++){
        
    	int temp1 = ((long)(arr[i-1])*arr[i-1]) % mod;
        int temp2 = ((long)(arr[i-1])*arr[i-2]) % mod;
        
        arr[i] = ((long)(temp1) + 2*temp2 )%mod;
    }
    
    int ans = arr[h];
    
    delete [] arr;
    return ans;
    
}

