#include<iostream>
using namespace std;


int* merge_sorted(int* arr1 ,int size1, int *arr2,int size2){

int *arr = new int[size1 + size2];

int i=0;
int j=0;
int k=0;

while(i<size1 && j<size2){
    if(arr1[i]<=arr2[j]){
        arr[k]=arr1[i];
        i++;
        k++;
    }else{
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

while(i<size1){
    arr[k]=arr1[i];
    i++;
    k++;
}

while(j<size2){
    arr[k]=arr2[j];
    j++;
    k++;
}

return arr; 
}


void merge_sort(int* arr,  int size ){
    if(size==1 || size ==0){
        return;
    }

    int mid = size/2;
    merge_sort(arr , mid);
    merge_sort(arr+mid , size-mid);

    int *ans = merge_sorted(arr , mid , arr+mid,size-mid);

    for(int i{0} ; i<size ;i++){
        arr[i]=ans[i];
    }

    delete [] ans;
}

int main(){
    int a [10]{10, 9 ,8 ,7,6,5,4,3,2,1};

    merge_sort(a,10);

    for(int i{0} ; i<10 ; i++){
        cout<<a[i]<<" ";
    }
}