#include<iostream>
#include<cmath>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {
    //base case
    if(n==0){
        if(k==0){
            output[0][0]  = 0;
            return 1;
        }else{
            return 0;
        }
    }
    int arr2[10000][50];
    //didnt include my elelmenr
    int small_op = subsetSumToK(input+1 , n-1 , output , k);
    ///inccludd my first elment so have to append ooutput in front of the subsets
    int small_op2 = subsetSumToK(input+1 , n-1 , arr2 , k-input[0]);
    
    //now append to our main output                 
    for(int i = 0 ; i < small_op2 ; i++){
        for(int j = 1 ; j <= arr2[i][0]  ; j++){
            output[i+small_op][j+1] = arr2[i][j];
        }
        output[i+small_op][0] = arr2[i][0]+1;
        output[i+small_op][1] = input[0];
    }

    return small_op + small_op2;

}
