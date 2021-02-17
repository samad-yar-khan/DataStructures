#include<iostream>
using namespace std;

void printSubsetsOfArray(int input[], int size , int output[] , int op_size){

    //base case
    if(size == 0){
        for(int i = 0 ; i < op_size ; i++){
            cout<<output[i]<<" ";
        }
        cout<<'\n';
        return ;
    }

    int *op_2 = new int[op_size+size+1];
    //we need to make a copy of our output to go two ways
    for(int i = 0 ; i < op_size ; i++){
        op_2[i] = output[i];
    }
    //if we dont include our first element in output
    printSubsetsOfArray(input+1 , size-1 , output , op_size);

    op_2[op_size] = input[0]; //add my elemdnt to the start
    op_size++;
    printSubsetsOfArray(input+1 ,size-1 , op_2 , op_size);


    delete [] op_2;
}

void printSubsetsOfArray(int input[], int size) {       
	// Write your code here

    int*output = new int[size];
    printSubsetsOfArray(input , size , output , 0);
    delete [] output;

}
