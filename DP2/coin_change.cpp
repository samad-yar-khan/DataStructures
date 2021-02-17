/*
Ways To Make Coin Change
Send Feedback
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/

#include <iostream>
using namespace std;

//brute force approaahc 
//complexity = O(2^N)  
int count(int* arr , int n , int val){
    //base case
    if(val < 0 || n==0){
        return 0;
    }

    int case1 = 0 , case2 = 0 ;

    //if i dont consider first elmeent at all
    case1 = count (arr+1 , n - 1 , val);
    
    //if i considr first element
    // if my element is val , then subtracing it with wval will result in 0
    //and woont ake sense to check further so my ans for case 2 will be  just one conbnation
    //  if my elmeent is less than value te i subtract it from val and check further
    if(arr[0] == val){
        case2 = 1;//i consider my element atleast once
    }else if(arr[0] < val){
        case2 = count(arr , n , val - arr[0]);
    }

    return case1 + case2;
}

//MEMOIZATION
/*
We see a lot of sub problems are repeating , there is a repetition of sub problems
so a single problem is solved multple tiimes which increased the time complexity of our
problem to O(2^N) 
So what we see is that there are pairs of vals and size of array with respect to which
we need our max count of combinations 
output[i][j] will store our ans for array of size i from th end and value j
*/

int count_memo(int* arr , int n , int val , int** output){
    //base case
    if(val == 0 || n==0){
        return 0;
    }

    //check my ans
    if(output[n][val] != -1){
        return output[n][val];
    }

    int case1 = 0 , case2 = 0 ;

    //if i dont consider first elmeent at all
    case1 = count_memo (arr+1 , n - 1 , val , output);
    
    //if i considr first element
    // if my element is val , then subtracing it with wval will result in 0
    //and woont ake sense to check further so my ans for case 2 will be  just one conbnation
    //  if my elmeent is less than value te i subtract it from val and check further
    if(arr[0] == val){
        case2 = 1;//i consider my element atleast once
    }else if(arr[0] < val){
        case2 = count_memo(arr , n , val - arr[0] , output);
    }

    //save my answer
    output[n][val]= case1 + case2;
    return output[n][val];
}

int count_memo(int* arr , int n , int val ){
    int **output = new int*[n+1];//row represet array size

    //columns will represent value
    for(int i = 0 ; i <= n ; i++){
        output[i] = new int[val+1];
    }
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= val ;j++){
            output[i][j] = -1;
        }
    }
    int ans = count_memo(arr , n , val , output);
    for(int i = 0 ; i <= n  ; i++){
        delete [] output[i];
    }

    delete [] output;
    return ans;
}

//dp

int count_dp(int *arr , int n , int val){

    int **output = new int*[n+1];//row represet array size

    //columns will represent value
    for(int i = 0 ; i <= n ; i++){
        output[i] = new int[val+1];
    }
 
    //first row and col = 0

    for(int i = 0 ; i <= n ; i++){
        output[i][0] = 0; //col 0
    }

    for( int j = 0 ; j <= val ; j++){
        output[0][j] = 0;
    }

    //j represents diff values of val
    //i repesents size of aray from back
    for(int i = 1 ; i <= n ; i++){

        int index = n - i;
        for(int j = 1 ; j <= val ; j++)
        {
            int case1 = 0 , case2 = 0; //case on deals with smaller array and case w deals with when we add our elemnet

            case1 = output[i-1][j];

            if( arr[index] == j){  //if iits equal subtracting it will result to 0  , so our combination is 1
                case2 = 1;
            }else if( arr[index] < j ) { //we cant subtract from val if its larger as it will becooe a newgatve  monetary  amount
                case2 = output[i][j-arr[index]];
            } 
            output[i][j] = case1 + case2;
        }
    }


    int ans = output[n][val];
    for(int i = 0 ; i <= n  ; i++){
        delete [] output[i];
    }

    delete [] output;
    return ans;

}



int main(){
    int n{0};
   
    cout <<"Enter number of denominations : ";
    cin>> n;
    int*arr = new int[n];

    cout<<"Enter all denominations  : ";
    for(int i {0} ; i < n ; i++){
        cin>>arr[i];
    }

    cout<<"enter the final value : ";
    int val{0};
    cin>> val;
    cout <<"Combinations "<< count_dp(arr, n ,val);
    delete[] arr;
}

