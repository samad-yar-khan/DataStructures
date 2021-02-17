/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int subset(int input[], int n, int** output) {
    // Write your code here
	//base case
    //empty input
    if(n==0){
        output[0][0] = 0;
        return 1;
    }
    
    //induction hypothesis 
    //we pass the smallwr output and expect our ourtput to have all subsests 
    //and it returns the number of subests in output
    int small_output_rows = subset(input+1 , n-1 , output);
    	
    for(int i = 0 ; i < small_output_rows ; i++){//traverse the 2d rowd
        
        int cols = output[i][0]; //pehle jagah number of cols haiw which represnets size of subseq
        
        for(int j{1} ; j <= cols ; j++){
            output[i+small_output_rows][j+1] =output[i][j]; //apme elments n rows skip karkee agey kare copy ardiye and first pe apne elemnet dalunga 
        }
        output[i+small_output_rows][0] = output[i][0]+1;
        output[i+small_output_rows][1] = input[0];
    }
    
    //we double the rows in each output 
    return small_output_rows*2;
     
}

int main(){

    cout<<"Enter size of input array (<20): ";
    int n{0};
    cin>>n;

    int* arr = new int[n];
    
    cout <<"Enter array elements : ";
    for(int i{0} ; i < n ; i++){
        cin>>arr[i];
    }

    int**output = new int*[(int)pow(2,n)];
    for(int i{0} ; i < (int)pow(2,n) ; i++){
        output[i] =  new int[n];
    }

    int rows = subset(arr , n , output);

    for(int i = 0 ; i < rows ; i++){

        for(int j{1} ; j <= output[i][0] ; j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;

    }


    for(int i{0} ; i < (int)pow(2,n) ; i++){
        delete [] output[i];
    }
    delete[] output;

    delete[] arr;

}
