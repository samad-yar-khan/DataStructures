/*
Minimum Count
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
#include<cmath>
#include<climits>
using namespace std;

//brute
int min_count (int N){

    //base case 
    if(N==0){
        return 0;
    }

    //IH
    int min_ans = INT_MAX;
    int x = N;
    while(x>0) {

         if(pow(x,2)<=N){
            int n = pow(x,2);
            int ans_t = min_count(N-n);
            min_ans  = min(ans_t , min_ans);

        }
        x--;
    }

    //is
    int final_ans = min_ans+1;
    return final_ans;
}

//memoization 
int min_count_2(int N , int* arr){
    
    if(N==0){
        return 0;
    }

    //check
    if(arr[N]!=-1){
        return arr[N];
    }

    //IH
    int min_ans = INT_MAX;
    int x = N;
    while(x>0) {

         if(pow(x,2)<=N){
            int n = pow(x,2);
            int ans_t = min_count_2(N-n , arr);
            min_ans  = min(ans_t , min_ans);

        }
        x--;
    }

    //is
    int final_ans = min_ans+1;
    arr[N] = final_ans;
    return arr[N];

} 



int min_count_2(int N){
    
    int *arr = new int[N+1];
    for(int i = 0 ; i <= N ; i++){
        arr[i] = -1;
    }

    int ans = min_count_2(N,arr);
    delete [] arr;
    return ans;
}

int min_count_dp(int N){

    int *arr = new int[N+1];

    for(int i = 0 ; i <= N ; i++){
        arr[i] = -1;
    }

    //base values bhardi
    arr[0] = 0 ;
    arr[1] = 1;

    //i will start bilding my ans from smallest unknown value and work my way to N

    for(int i = 2 ; i <= N ; i++){

        int ans = INT_MAX;

        int j = i-1; 

        while (j>0){

            if(pow(j,2)<=i){

                int n = pow(j,2);

                ans = min(ans,arr[i-n]);

             }

            j--;
        }

        arr[i] = ans+1;

    }

    int final_ans = arr[N];
    delete [] arr;
    return final_ans;
    

}

int main(){
    int n= 0 ;
    cin>> n;

    cout<<min_count_dp(n);
}


