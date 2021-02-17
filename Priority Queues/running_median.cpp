/*
Running median
Send Feedback
You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.
Input Format :
Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces
Output Format :
After each new integer is added to the list print the updated median on a new line
Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4
Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
*/


#include <iostream>
using namespace std;
#include <queue>




void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
    */

    //for median we need asorted array , so instead of sorting it out we keep two heaps    
    //median is the avg of middle two elments if the  no f lements of sorted array are even
    //if there are odd no of elements (in sorted aarr) the middle lement is the median

    //ex left-half: 1 2 3   right-half: 4 5
    //median is 3 (max of left if it has more no of elemnts)/(or top od left max_heap)

        // max heap         //min heap
    //ex left_half: 1 2 3   right-half :4 5 6 
    //same number of elemenst so we just get avg of left max and right min

    //ex left-half: 1 3 6   right-half :10 20 40 80
    //midian = 10 


    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    if(n==0){
        return;
    }
   priority_queue<int> left;
   priority_queue< int , vector<int> , greater<int>> right ;

   left.push(arr[0]);

   cout<<arr[0]<<endl;

   for(int i{1} ; i < n ; i++ ){

       //where to put
       if( arr[i] >= left.top() ){
            right.push(arr[i]);
       }else {
           left.push(arr[i]);
       }

        //balance
       if(left.size() - right.size() == 2){

           right.push(left.top());
           left.pop();

       }else if(right.size() - left.size() == 2){

           left.push(right.top());
           right.pop();
       }

       if(right.size()==left.size()){
           cout<< (left.top() + right.top())/2 <<endl;
       }else if(left.size() > right.size()){
           cout<<left.top()<<endl;
       } else{
           cout<<right.top()<<endl;
       }
   }

}


int main(){

    cout<<"ENTER ARRAY SIZE - ";
    int n{0} ;
    cin>>n;

    int *arr = new int [n];

    cout<<"Enter elments - ";
    for(int i{0} ; i < n ; i++){
        cin>>arr[i];
    }

    cout<<"RUNNING MEDIANS - "<<endl;

    findMedian(arr,n);

    delete []arr;
}