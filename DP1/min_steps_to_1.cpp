#include<iostream>
#include<climits>
using namespace std;

//brute force we are doing a lot of repeated work

int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */

    // base case

    if(n <= 1){
        return 0;///non strps needed
    }

    int x = INT_MAX;
    int y = INT_MAX;
    int z = INT_MAX;

    //ih
    if(n % 2 == 0){
        x = countStepsTo1(n/2);
    }

    if(n % 3 == 0){
        y = countStepsTo1(n/3);
    }

    z = countStepsTo1(n-1);

    //is

    return min(min(x,y) , z) +1;
}

//memotization 

int helper_cst1 (int *arr , int n){

    if(n<=1){
        return 0;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    int x=INT_MAX;
    int y=INT_MAX;
    int z=INT_MAX;

    if( n % 2 == 0){
        x = helper_cst1(arr , n/2 );
    }

    if( n % 3 == 0){
        y = helper_cst1(arr , n/3 );
    }

    z = helper_cst1(arr , n-1 );

    arr[n] = min (min (x,y) , z);

    return arr[n];


}

int count_steps_to_1(int n){

//if n = 1 , we need zero steps 
//if n = 2 , we need one step
//if n = 3 , we need one step just devide by 3 , so one step

    int* arr = new int[n+1];

    for(int i{0} ; i < n+1 ; i++ ){
        arr[i] = -1;
    }

    int ans = helper_cst1(arr , n);

    delete [] arr;
    return ans;
}

//Dynamic programming approach

int countStepsTo1_dynamic(int n){

	int *arr = new int [n+1];
    
    arr[0] = 0;
    arr[1] = 0;
    
    for(int i{2} ; i < n+1 ; i++ ){
        
        int x = INT_MAX;
        int y = INT_MAX;
        int z = arr[i-1];
        
        
        if(i % 2 == 0){
            x = arr[i/2];
        }
        
        if(i % 3 == 0){
            y = arr[i/3];
        }
        
        arr[i] = min( min(x,y) , z ) + 1;

    
    }

    int ans = arr[n];
    
    delete [] arr;
    
    return ans;

}


int main (){
    
    cout<<"Enter number  ";
    int n{0};
    cin>>n;
    cout<<"Min steps needed to convert "<<n<<"to 1 is "<<countStepsTo1(n)<<endl;
}