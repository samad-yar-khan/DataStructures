/*
bascially lind the length of the larest substring in these 2 strings 
ex S = "abc"
   T = 'xyz'
   output = 0

ex S = "abcdefh"
   T = "xaybelwqh"
   output = 4(a b e h ) 
*/

#include <iostream>
#include <string>
using namespace std;

//brute force approach

int lcs_r(string S , string T ){

    //base case
    if (S.length() == 0 || T.length() == 0){
        return 0; // if either if the string is smpty my max lcs len is 0
    }

    //IS
    //my first chars match so they already form a part of my lcs , no i need to check further in botth strngs
    //whatever ans i get from there my will be incresed my 1 (1st char) and returned
    if(S.at(0) == T.at(0)){
        return 1 + lcs_r(S.substr(1) , T.substr(1));
    }

    int case1 = lcs_r(S.substr(1) , T);
    int case2 = lcs_r(S , T.substr(1));

    int ans =  max (case1 , case2);
    return ans;

}

//memoization approach
//we will be creating a 2d array which stores the lcs of sbustrings of S&T 
//ans[m][n] will store the lcs of the substring of S of len m and ssubtring of
// T of len n

int lcs_memo(string S , string T , int** ans){

    int m = S.length();
    int n = T.length();
    //base case
    if(S.length() == 0 || T.length() == 0){
        return 0;
    }

    //checking 
    if(ans[m][n] != -1){
        return ans[m][n];
    }

    int answer{0};

    if(S.at(0) == T.at(0)){
        answer= 1 +  lcs_memo(S.substr(1) , T.substr(1) , ans);
    }else{
        int c1 = lcs_memo(S.substr(1) , T , ans);
        int c2 = lcs_memo(S , T.substr(1) , ans);

        answer = max(c1,c2);
    }
    
    //save your answer
    ans[m][n] = answer;

    return answer;

}


int lcs_memo(string S , string T){

    int m = S.length(); 
    int n = T.length();

    int **ans = new int*[m+1];
    for(int i = 0 ; i < m+1 ; i++){
        ans[i] = new int[n+1];
    }

    for(int i = 0 ; i < m+1 ; i++){
        for( int j = 0 ; j <n+1 ; j++){
            ans[i][j]=-1; //just to check in our helper function
        }
    }

    int output  = lcs_memo( S ,  T , ans); 

    for(int i = 0 ; i < m+1 ; i++){
        delete [] ans[i];
    }
    delete [] ans;

    return output;
}

int lcs_dp(string S , string T ){

    int m = S.length() ;
    int n = T.length() ;

    int **arr = new int* [m+1];

    for(int i=0 ; i < m+1 ; i++){
        arr[i] = new int[n+1];
    }

    //i have my 2dd aray ready where our index i inex will represnent th length of S
    // and j will represent the lnegth of T 
    // each cell ex arr[i][j] wil represent the lcs of a substring of S of len i and  
    //of a substring To flnegth j
    //hence first row and column will be zero

    //row 0
    for(int i=0 ; i < n+1 ; i++){
        arr[0][i]=0;
    }

    //column 0
    for(int i{0} ; i < m+1 ; i++){
        arr[i][0] = 0;
    }

    for(int i = 1 ; i < m+1 ; i++){
        
        for(int j = 1 ; j < n+1 ; j++){

            //fiest index of substrings of len i ans j
            int x = S.length() - i;
            int y = T.length() - j ;

            if(S.at(x) == T.at(y)){
                arr[i][j] = 1 + arr[i-1][j-1];
            }else{
                int c1 = arr[i-1][j];
                int c2 = arr[i][j-1];
                int c3 = arr[i-1][j-1];
                //we dot really need c3  , we could have put max (c1,c2)
                arr[i][j] = max(c3,max(c1,c2));

            }
        }
    }

    int ans = arr[m][n];

    for (int i = 0; i < m+1 ; i++)
    {
       delete [] arr[i];
    }
    delete [] arr;
    
    return ans;

}

int main(){

    cout <<"Enter the two strings ";
    string S;
    string T;
    cin>>S>>T;

    cout <<"The largest common substring in " <<S<< " "<<T<<" is "<<lcs_dp(S,T)<<endl;
}


