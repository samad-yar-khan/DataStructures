/*

Code : K largest elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25

*/

#include<iostream>
using namespace std;
#include<queue>
#include <vector>


//same logic as k_smallestbut we use a min pq 

vector<int> kLargest(int input[], int n, int k){

    //explaination of inbuild pq in notes
    priority_queue<int , vector<int> , greater<int>> pq;

    //insert first k elements to pq
    for (int i{0} ; i < k ;i++){
        pq.push(input[i]);
    }

    //we asusume the k ellemnts in pq to be the max such that 
    //even the min of those will be larger than the array elements
    //so if our min is small than an elemnst , we pop it off
    //isnsert that lements
    for(int i = k ; i < n ; i++){
        if(input[i] > pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }

    vector <int> ans;
   while(!pq.empty()){
    ans.push_back(pq.top());
    pq.pop();
    }

    return ans;
}

int main(){
    cout<<"Number of lements you wish to  enter - ";
    int n;
    cin>>n;
    
    int *arr = new int [n];
    cout<<"Enter Elmenets - ";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    cout<<"how many largests lements  u waant? ";
    int k;
    cin>>k;

    vector<int> ans = kLargest(arr,n,k);

    for(auto v:ans){
        cout<<v<<" ";
    }

    cout<<"\n";
}
