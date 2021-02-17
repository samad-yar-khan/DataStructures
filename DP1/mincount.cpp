/*
Code : Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1

*/


#include<iostream>
#include <climits>
using namespace std;


//brute force
int minCount(int n){

    //bc
    if(n==0){
        return 0;
    }
    
    //ih

    int x=1;
    int min = INT_MAX;
    
    while (x*x <= n){
        int ans = minCount(n-x*x);
        if(min > ans){
            min = ans;
        }
    	x++;    
    }
    
    return min+1;
}

//memotizatoion approach

int minCount2(int * arr , int n){
    
    if(n==0){
        return 0; 
    }

    if( arr[n] != -1 ){
        return arr[n];
    }	
    
    int i = 1;
    int ans=INT_MAX;
    while( i*i <= n ){
        int ans_temp =  minCount2(arr , n- (i*i) );
        
        if(ans_temp < ans ){
            ans = ans_temp;
        }
        i++;
    }
    
    arr[n] = ans+1;
    return arr[n];
}


int minCount_memo(int n){

    //bc
   int *arr = new int [n+1];
    
    for(int i{0} ; i < n+1 ; i++){
        arr[i] = -1;
    }
    
    int ans = minCount2(arr , n);
    delete [] arr;
    
    return ans;
    
    
}



//dynamic programming approach 


int minCount_dp(int n){

    //bc
   int *arr = new int [n+1];
    
	arr[0] = 0;//0 no ans;
    
    for(int i{1} ; i < n+1 ; i++){
        
        int j = 1;
        int min = INT_MAX;
        while (j*j <= i){
            int temp = arr[i-(j*j)]; //we get ans , we choose min and add 1 to  it
        
            if(temp < min){
                min = temp;
            }
            j++;
        }
        arr[i] = min+1;
    }
    
    int ans = arr[n];
    delete [] arr;
    
    return ans;
}

int main(){

cout<<"Enter your number - ";
int n{0};
cin>>n;

cout<<minCount_dp(n)<<" Squares will be needed to make "<<n<<endl;


}


