/*
Code: Knapsack (Memoization and DP)
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/
#include<iostream>
#include<climits>
using namespace  std;

//brute force
int knapsack(int* weights, int* values, int n, int maxWeight){

	/* Don't write main().
	*  Don't read input, it is passed as function argument.
	*  Return output and don't print it.
	*  Taking input and printing output is handled automatically.
	*/

	//write your code here
    //base case
    if(n==0 || maxWeight <= 0 ){
        return 0;
    }
    
    //IH
    int case1 = INT_MIN;
    int case2 = INT_MIN;
    
    if(maxWeight >= weights[0]){
       case1 =  knapsack(weights+1,  values+1, n-1, maxWeight - weights[0])+values[0];
    }
    
    case2 = knapsack(weights + 1, values+1, n-1, maxWeight);
    
    //ih
    int ans = max(case1,case2);
    return ans;
}


int knapsack_cn(int* weights, int* values, int n, int maxWeight){

    //base case
    if(n == 0 ||  maxWeight <= 0){
        return 0;
    }

    //inductin hypotheses 

    //if our wt is more tna the max wt then we cantt piick it up any ways so we just move further
    if(weights[0] > maxWeight){
        return knapsack_cn(weights +1 , values + 1 , n-1 , maxWeight);
    }

    //is+ih
    //i include my weight
    int case1 = knapsack_cn(weights+1 , values+1 , n-1 , maxWeight-weights[0]) + values[0];
    int case2 = knapsack_cn(weights+1 , values+1 , n-1 , maxWeight);

    int ans = max(case1,case2);
    return ans;


}

//memoioizaation
//in our rwecursion tree we can see that our value of max_wt can vary from 0-max_wt
//at the ame time the size of our array which we are dealing wth is varying from
//0-n
//so at any time allww erequire is a combination of (n,Wt_max)
//here n is the number of elemnts which we are using in our array from the end and 
//max_wt is the max_wt which we can take
//again my issue was i was too focused on achieving exact (n,Wt_max) pairs but why dont we consider all of them
//whihv will be (n+1)(Wt_maxn+1) ans store all of te=hem in our array/matrix so no repetion occurs

//correct soln , the problem is that the spac compeity we are using is O(n*W) 
//time complexity = O(nW)

int knapsack_memo(int* weights, int* values, int n, int maxWeight , int** ans ){

    if(n== 0 || maxWeight == 0){
        return 0 ;
    }

    if(ans[n][maxWeight] != -1){
        return ans[n][maxWeight];
    }

    if( weights[0] > maxWeight ){
        ans[n][maxWeight] = knapsack_memo(weights +1 , values + 1,n-1 , maxWeight , ans );
    }else{
        int c1 = knapsack_memo( weights + 1 , values + 1 ,n-1, maxWeight - weights[0] , ans ) + values[0];
        int c2 = knapsack_memo( weights + 1 , values + 1 ,n-1, maxWeight  , ans );
        ans[n][maxWeight] = max(c1,c2);
    }

    return ans[n][maxWeight];


}



int knapsack_memo(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    int row = n+1; // and no of elmets can vary from 0 - n
    int cols = maxWeight + 1; //wt can vary form 0 to maxWt

    int **ans = new int*[row];
    for(int i = 0 ; i < row ; i++){
        ans[i] = new int [cols];
    }

    for(int i{0} ; i < row ; i++){

        for(int j =0 ; j <cols ; j++){
            ans[i][j] = -1;
        }
    }

    int answer = knapsack_memo(weights , values , n , maxWeight , ans);



    for(int i = 0 ; i < row ; i ++){
        delete [] ans[i];
    }
    delete [] ans;

    return answer;
}


//dp
int knapsack_dp(int *weights , int *values , int n , int maxWeight){
    
 

	/* Don't write main().
	*  Don't read input, it is passed as function argument.
	*  Return output and don't print it.
	*  Taking input and printing output is handled automatically.
	*/

	//write your code here
	int row = n+1;
    int col = maxWeight +1;
    
	int **arr = new int*[row];
    
    for(int i = 0 ; i < row ; i ++){
        arr[i] = new int[col];
    }
    
    //row zero
    for(int i = 0 ; i < row ; i ++){
        arr[i][0] = 0 ;
    }
   
    //col 0
    for(int j = 0 ; j < col ; j++){
        arr[0][j] = 0;
    }
    
    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            
            int index = n - i;
            
            if(weights[index] > j ){
                arr[i][j] = arr[i-1][j];
            }else{
                arr[i][j] = max(arr[i-1][j] , arr[i-1][j-weights[index]] + values[index]);
            }
        }
    }
    
    int ans = arr[n][maxWeight];
    
    
    for(int i = 0 ; i < row ; i ++){
     	delete [] arr[i];
    }   
    delete [] arr;
    
    return ans;
    
}

//basically we recuded the space complixty to  o(W) and sspace complexity is O(nw)
//what we relaised isn that at any point we just require the previous row to fiill our row 
//so at most we need two array ata a particular pt
//so we just make 2 1D  arrays of size mxwt+1 and fill the second one with the help of the first one
//at each iteration , we switch the row and fill

int knapsack_dp2(int* weights, int* values, int n, int maxWeight){

    int col = maxWeight +1;

    int *arr1 = new int[col]; // this will always be prefilled 
    int *arr2 = new int[col]; //we fill thisusing uppur row / arr1
    
    //first row zero //zwero szie aarray
    for(int j{0} ; j < col ; j++ ){
        arr1[j] = 0 ; 
    }
    
    //filling consective rows
    for(int i = 1 ; i < n+1 ; i++){
    	
        for(int j = 0 ; j < col ; j++ ){
            
            if(j == 0 ){
                arr2[j] = 0 ;
            }
            else{
                
                int index = n-i;
                
                if( weights[index] > j){
                    arr2[j] = arr1[j];
                }else{
                    int case1 = arr1[j] ; //our weight not included
			    	int case2 = arr1[j - weights[index]] + values[index]; // our wt included
                     arr2[j] = max(case1 , case2);
                }
                
            }
            
        }
        
        if(i<n){
            int*temp = arr2;
            arr2 = arr1;
            arr1= temp;
        }
        
    }
    
    int ans = arr2[maxWeight];
    
    delete [] arr1;
    delete [] arr2;
    
    return ans;
    
}


int main(){
    int n{0};

    cout <<"number of weight presenst - ";
    cin>>n;

    int* weights = new int[n];
    cout <<"Ente the weights - ";

    for(int i=0 ; i < n ; i++){
        cin>>weights[i];
    }

    int* vals = new int [n];

    cout <<"Ente the values of your weights - ";

    for(int i=0 ; i < n ; i++){
        cin>>vals[i];
    }

    cout <<"Enter the maximum weight capacity whcih you can hold ";
    int max_weight {0};
    cin>>max_weight;

    int max_value = knapsack_dp2(weights , vals , n , max_weight);

    cout <<"The max value which you can get within you limits is "<<max_value<<endl;

    delete [] weights;
    delete [] vals;

}



