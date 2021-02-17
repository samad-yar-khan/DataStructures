#include<iostream>
using namespace std;;

int partition_function(int*arr , int si , int ei) { //si = starting index && ei = end index

    //first task is t see the

    int count{0};
    //here we just calculate how many elments are smaller than first elment or equal to it
    for(int i = si+1 ; i <=ei ; i++){
        if(arr[i]<=arr[si]){
            count++;
        }
    }
    //count is the number of elments smaller than our elemnst 
    //so now to we need to leave "count" number of elemnts satarting from si and place our elment ar corect pos

    int correct_position = si+count;
    //now swap my lements and pur it at correct pos

    int temp = arr[correct_position];
    arr[correct_position] = arr[si];
    arr[si] = temp;

    //now we need to  bring all elenets smaller than first elment to the left of it and all elments larger than it to thr right of it

    int i = si , j = ei;
    //we swwap elements if they are both at the wrong place

    while(i < correct_position && j > correct_position ){
        //we 
        if(arr[i] <= arr[correct_position] && arr[j] <= arr[correct_position]){ //ellemnt at j is at wrong position whule element at is on the corrects side so we just incremnet i and see if we find a pplace where both are at wrong place

            i++;
            
        }else if(arr[i] > arr[correct_position] && arr[j] > arr[correct_position]){
            j--;
        }else if(arr[i] <= arr[correct_position] && arr[j] > arr[correct_position]){
             i++;
             j--;
        }else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    return correct_position;
}


void quick_sort(int* arr , int si , int ei){

    //base case
    if(si>=ei){
        return;
    }

    //is
    int pivot = partition_function(arr, si , ei);

    //ih
    quick_sort(arr,si,pivot-1);
    quick_sort(arr ,pivot+1 , ei);

}