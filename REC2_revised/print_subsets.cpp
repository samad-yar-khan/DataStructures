#include<iostream>
using namespace std;

void print_subset (int input[],int size,int output[],int size_output,int n=0){
     if(size==0){
         for(int i=0;i<n ;i++){
             cout<<output[i]<<" ";
         }
         cout<<endl;
         return;
     }
    
    int *output_2= new int [size_output];
    for(int i=0;i<size_output;i++){
        output_2[i]=output[i];
    }
    
    print_subset (input+1,size-1,output,size_output,n);
    output_2[n]=input[0];
    print_subset (input+1,size-1,output_2,size_output,n+1);
    
    delete [] output_2;
        
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
	int *output = new int [size];
    print_subset(input,size,output,size);
    delete [] output ;
    
}
