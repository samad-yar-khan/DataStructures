/*
Code : Edit Distance
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 10
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/

#include <iostream>
#include <string>
using namespace std;

//brute force solution 


int editDistance(string S, string T){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */

	//write your code here

    //base  case
    if(S.length() == 0 || T.length() == 0){
        return max(S.length() , T.length());
    }
    

    
    int ans = 0;
    //ih
    if(S.at(0) == T.at(0)){
        ans = editDistance(S.substr(1) , T.substr(1));
    }
    else{
        //add my S's first char at the start  of T
        int c1 =  editDistance(S.substr(1) , T);
        
        //replace first char of T to S's
        int c2 =  editDistance(S.substr(1) , T.substr(1));
        
        //delete first char of T
        int c3 = editDistance(S , T.substr(1));
        
        ans = 1 + min(c1,min(c2,c3));
        
    }
    
    return ans;
    
}


//memoizaion


//arr[m][n]  will store the min operations reqs  to change the sibstring of S of length
// m to substring T of length n
int editDistance_Memo(string S, string T , int**arr){

    //base
    if(S.length() == 0 ||  T.length() ==  0){
        return max( S.length() , T.length() );
    }

    int m = S.length();
    int n = T.length();

    //check if answer exists or not
    if( arr[m][n] != -1 ){
        return arr[m][n];
    }

    int ans = 0;

    if( S.at(0) == T.at(0) ){
        
        ans = editDistance_Memo(S.substr(1) , T.substr(1) , arr);
    
    }else{

        //we add S's first character at the startinng oof T so they maactha and make further changes
        int case1 = editDistance_Memo(S.substr(1) , T , arr);
        
        //we replace T(0) with s(0) and see ho many more steps are req
        int case2 = editDistance_Memo(S.substr(1),T.substr(1) , arr);

        //we delete the firts char of T and see how many more  stes are req to change T to S
        int case3 = editDistance_Memo(S , T.substr(1) , arr);

        ans = min( case1  , min(case2 , case3)) + 1;

    }
    //save the answer
    arr[m][n] = ans;
    return arr[m][n];


}


int editDistance_Memo(string S, string T){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */

    int m = S.length() + 1;
    int n = T.length() + 1;
    
    int** arr = new int* [m+1];
    
    for(int i{0} ; i <= m ; i++){
        arr[i] = new int[n+1];
    }
    
    for(int i{0} ; i <= m ; i++){
        for (int j{0} ; j <= n ; j++ ){
            arr[i][j] = -1 ;
        }
    }
    
    
    int ans = editDistance_Memo(S , T , arr);
    
    for(int i{0} ; i <= m ; i++){
        delete [] arr[i];
    }
    delete  [] arr;

    return ans;
    
}

//Dp approach

int editDistance_dp(string S , string T ){
    int m = S.length() ;
    int n = T.length() ;
    
    int** arr = new int* [m+1];
    
    for(int i{0} ; i <= m ; i++){
        arr[i] = new int[n+1];
    }


//to match the base cases if string of len i and 0 are there , we nee dto perform i operation to make them equal
    //first col
    for(int i = 0 ; i < m+1 ; i++ ){
        arr[i][0] = i;
    }

    //first row
    for(int j = 0 ; j <=n ; j++){
        arr[0][j] = j;
    }

    for(int i = 1 ;  i <= m ; i++){

        for(int j = 1 ; j <= n ; j++){

            int start_index_S = m - i;
            int start_index_T = n- j;

            if(S.at(start_index_S) == T.at(start_index_T)){
                arr[i][j] = arr[i-1][j-1];
            }else{

                int c1 = arr[i-1][j];
                int c2= arr[i-1][j-1];
                int c3 = arr[i][j-1];

                arr[i][j] = min(c1 , min(c2,c3)) + 1;
            }


        }

    }

    int ans = arr[m][n];

    for(int i = 0 ; i < m+1 ; i++){
        delete [] arr[i];
    }

    delete [] arr;

    return ans;

}


int main(){

    string S ; 
    string T ;

    cout <<"enter strings ";
    cin>>S>>T;

    cout<<"Min numebr of steps reqd to change " <<T<<" to "<<S<<" is "<<editDistance_dp(S,T)<<endl;
}