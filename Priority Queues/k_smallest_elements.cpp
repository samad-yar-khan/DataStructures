/*
Code : K smallest Elements
Send Feedback
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k smallest elements
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
5
3
2
1
*/
#include<iostream> 
using namespace std;
#include <queue>
#include <vector>

//APPROACH
/*
we want k min elemnets out of the given n elements
if we want the min of n elemensts , we assumne our first ekmenet to be the min and then
iterate and compare to each element of the loop and repace min with the element if its smaller

Here we try to follow a similiar approach 
->we consider the first k aalements to be the smallest in the arr such that even the largest of these
k elments is smallers than the rest of the array
->we compare max of the k elments to the next array elment and if its smaller tha the largest of k
then it desreved to be in these k elments . so we  add this to out group k and kick of the pre
existing largest element such that at the end we have k elements 
->if our max is smallers we dont do anything 
->now we have to just check the max of the k and also dlete the max in one case
->so most effecient data structure would be a max priority queue.

*/

vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here
    priority_queue<int> k_elments;

    //entered first k lements to out pq and we consider them to be the smallest inn the array
    //even if we pick the max of these k it should be smaller than the rest of the array

    for (int i{0} ; i<k ;i++ ){
        k_elments.push(input[i]);
    }

    //comparison time 

    for(int i=k ; i<n ; i++){
        //if out max in k is larger than our array element we will pop of our largest (already done by pop
        //func in max pq)
        if(input[i] < k_elments.top()){
            k_elments.pop();
            k_elments.push(input[i]);
        }

    }

    vector<int>  ans ;

    while (k_elments.size()!=0){
        ans.push_back(k_elments.top());
        k_elments.pop();
    }

    return ans;

}
