/*
Longest Increasing Subsequence
Send Feedback
Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
Line 1 : An integer N 
Line 2 : Elements of arrays separated by spaces
Output Format
Line 1 : Length of longest subsequence
Input Constraints
1 <= n <= 10^3
Sample Input :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2:
3
1 2 2
Sample Output 2 :
2
*/



#include<iostream>
#include<climits>
#include<vector>
using namespace std;



bool is_sorted(vector<int> arr){
    
    for (int i = 1 ; i < arr.size() ; i++) {
        if(arr[i-1] > arr[i]){
            return false;
        }
    }

    return true;

}
  

int lis (int * arr , int n , vector <int> sub){

    if(n==0){
        if(is_sorted(sub)){
            return sub.size();
        }else{
            return -1;
        } 
    }    

    //ih
    int case1 = lis(arr+1  , n - 1 , sub);
    sub.push_back(arr[0]);
    int case2 = lis(arr+1 , n-1 , sub);

    //is
    return max(case1,case2);

}

int lis (int * arr , int n ){
    vector<int> sub;
    return lis(arr , n , sub);
}



//dp
using namespace std;


 int lis_dp(int arr[], int n) {
		
     if(n == 0){
         return 0;
     }
     int *ans = new int[n]; //ans[i] will store the max length of largest sub sequece if ou arr has i elments from the begienning\
     
     ans[0] = 1 ;  //0 index represents first elmenet so  if out size is one , max lenegth of the lis should be atleast one
     
     for(int i = 1 ; i < n ; i++){
         
         ans[i] = 1; //min len of this can be 1
         for(int j = i-1 ; j >= 0 ; j--){
             
             if(arr[i] > arr[j]) { //then it can be a part of the queue / subseuqnce 
                 //we add it in the subsequnce and see if the length of that subsseqnce is greater than the
                 //the one we have already acheived
                 int possible_ans = ans[j] + 1 ; //add my num to the end
                 ans[i] = max(ans[i] , possible_ans); // the maximum d the two gets stored in ans
             }else{
                 continue;
             }
        }
     }
     
     //now our longest increasing subsequnces could have ended at any of the indices so we need to check
     //ans i bascially stores the maximum length odf a subsequnce whch can be created if out arr end at index i
     //so arr[n-1] , may not always be the ans
     int best = 0;
     for(int i = 0 ; i < n ; i++){
         if(ans[i] > best){
             best = ans[i];
         }
     }
    delete [] ans;
     return best;
}

int main(){
    
    int n;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter values : ";

    for(int i {0} ; i < n ; i++){
        cin>>arr[i];
    }
 
    // pair<int,int> p ;
    // p.first= INT_MIN; //max_elemnts;
    // p.second= 0;
    cout <<lis_dp1(arr,n);
    
    delete [] arr;

}