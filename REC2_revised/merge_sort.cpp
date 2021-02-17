#include <iostream>
using namespace std;

//we need a merge sort fuc=nc and func to merge two sorted arrays;

void  merge_two_sorted(int*arr1 , int size_1 , int*arr2 , int size_2 , int*arr3 , int size_3){

    int i{0} , j{0} , z{0};
    while( i < size_1 && j < size_2){
        if(arr1[i]<=arr2[j]){
            arr3[z] = arr1[i];
            i++;
            z++;
        
        }else{
            arr3[z] = arr2[j];
            z++;
            j++;
        }
    }

    while(i < size_1){
        arr3[z] = arr1[i];
        z++ ; 
        i++;
    }


    while(j < size_2){
        arr3[z] = arr2[j];
        z++;
        j++;
    }
}


void  mergeSort(int input[], int size){

    //base case  
    if(size==0 || size ==1 ){
        return ;
    }


    int left_size = size/2;
    int right_size = size-left_size;

    //IH
    mergeSort(input , left_size);
    mergeSort(input+left_size , right_size);

    int*dublicate = new int [size];
    merge_two_sorted(input , left_size , input+left_size , right_size , dublicate , size);

    for(int i = 0 ; i < size ; i++){
        input[i] = dublicate[i];
    }
    delete [] dublicate;
}


void combine_arrays(int *arr_1 ,int size_1, int * arr_2 , int size_2 , int *m){
    int i=0;
    int j=0;
    int final_size = size_1 + size_2;
    int k=0;
    
    
    while(i<size_1&&j<size_2){
        if(arr_1[i]<=arr_2[j]){
            m[k++]=arr_1[i++];
            }
        else{
            m[k++]=arr_2[j++];
            }
    }
            
   while(i<size_1){
        m[k++]=arr_1[i++];
   }

   while(j<size_2){
        m[k++]=arr_2[j++];
        }
}

// void mergeSort(int input[], int size){
// 	// Write your code here
//     if(size<=0||size==1){
//         return;
//         }
//         int mid = size/2;
//         int size_1=mid;
//         int size_2=size-mid;
     
//     mergeSort(input,size_1);
//     mergeSort(input+mid, size_2);
   
//     int *p = new int [size];
//     combine_arrays(input,size_1,input+mid, size_2,p);
    
//     for(int i=0;i<size;i++){
//         input[i]=p[i]; 
//     }
//     delete [] p;
    
    
// }

int main(){

    int n{0};
    cout<<"enter size of array : ";
    cin>>n;
    int*arr = new int[n];
    cout<<"Enter elements : \n";

    for(int i{0} ; i < n ; i++){
        cin>>arr[i];
    }

    mergeSort(arr , n);

    cout<<"Sorted array : \n";
      for(int i{0} ; i < n ; i++){
        cout<<arr[i]<<" ";
    }

    delete [] arr;
}
