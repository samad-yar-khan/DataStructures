#include<iostream>
using namespace std;


void printSubsetSumToK(int input[], int size,int*output , int size_op ,int k){

    //base case
    if(size == 0 ){
        if(k == 0 ){

            //agar size 0 ate i k bhi echaust hogya tabhi subseq sums to k and we
            //print it , otherwise we terminate calls at  n == 0 anyways
            for(int i = 0 ; i < size_op ; i++){
                cout<<output[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }

    int *output_2 = new int [size+size_op];
    for(int i{0} ; i < size_op ; i++){
        output_2[i] = output[i];
    }   
    // IH we either include our elment in output or we dont
    printSubsetSumToK(input+1 , size-1 , output , size_op , k);

    output_2[size_op] = input[0];
    
    printSubsetSumToK(input+1 , size-1 , output_2 ,size_op+1 , k - input[0]);

}


void printSubsetSumToK(int input[], int size, int k) {

    int*output = new int[size];

     printSubsetSumToK(input , size , output , 0 , k );
    
    delete [] output;

}
