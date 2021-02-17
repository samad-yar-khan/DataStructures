/*
Kth largest element
Send Feedback
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Try to do this question in less than O(nlogn) time.
Input Format :
Line 1 : An integer N i.e. size of the array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : An integer k
Output Format :
kth largest element
Input Constraints :
1 <= N, Ai, k <= 10^5
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
*/

#include <iostream>
using namespace std;
#include <queue>
#include <vector>

//algo
//we will get the k largest elemnts in or array using a min pq 
//then we will just retunr the min of those k largest elements
//this element will be our kth largest elment
int kthLargest (vector<int> arr, int n, int k){

    priority_queue <int , vector <int> , greater<int>> pq;

    //we assume these k elements to be the largest of the n 
    for(int i{0} ; i < k ; i++){

        pq.push(arr[i]);

    }

    for(int i{k} ; i < n ; i++){

        //if myy min is smaller than the array elements i ll delete it and add the arr elment
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();

    
}


int main(){
    vector <int> arr{1 ,2,3,4,5};

    cout<<kthLargest(arr,5,2);
}