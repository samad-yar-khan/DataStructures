/*
Code : Min Cost Path
Send Feedback
Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)
Output Format :
Minimum cost
Constraints :
1 <= m, n <= 20
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
*/

#include <iostream>
#include <climits>
using namespace std;

//brute force aproach 
//we just call rec to the cell in the right , diiagnol and down 
//we see whcih path gives min csot , add our cost to it and return


int minCostPath(int **input , int m , int n , int x , int y  ){ // x and y are row an cols
    
    //int base case
    if(x == m-1 && y == n-1){
        return input[m-1][n-1];
    }
    
    //IH
    
    int c1 = INT_MAX , c2 =INT_MAX , c3 = INT_MAX ;
    
    if( x < m-1 && y < n-1 ){ //diagonal check
        c1 =  minCostPath(input , m , n , x+1 , y+1 );
    }
    if(x  <m-1 ){ //we cant move right if we are at the boundry
        c2 =  minCostPath(input , m , n , x+1 , y);
    }
    if(y < n-1){ //we cant move down if we are at the boorion
        c3 =  minCostPath(input , m , n , x , y+1);
    }
    
    //is
    
    int ans = min(c1,min(c2,c3)) + input [x][y];
    return ans;
    
}
int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    return  minCostPath (input , m , n ,  0 , 0);
}


//memoization aproach
int helper (int ** matrix , int m , int n , int**ans , int x = 0 , int y = 0){

    //base case
    if(x == m-1 && y == n-1){
        return matrix[x][y];
    }

    //inducton steep
    if(x >= m || y >= n ){ //this indicates that we are out of bound of our matrix
        return INT_MAX;
    }

    if(ans[x][y] != -1){
        return ans[x][y];
    }


    //indxton hypitheses
    int c1 = helper(matrix , m , n , ans , x+1 , y);
    int c2 = helper(matrix , m , n , ans , x+1 , y+1);
    int c3 = helper(matrix , m , n , ans , x , y+1);
    
    ans[x][y] = min(c1,min(c2,c3)) + matrix[x][y];
    return ans[x][y];



} 

int min_cost_path_memo (int ** matrix , int m , int n ){

    //my ans [i][j] willl store min path from ans[i][j]  to ans[m-1][n-1]
    int** ans = new int* [m];
    for(int i = 0 ; i < m ; i++){
        ans[i]= new int [n]; 
        for(int j=0 ; j < n ; j++){
            ans[i][j] =  -1;
        }
    }
  
    int mincost = helper ( matrix , m ,  n , ans);



    for(int i = 0 ; i < m ; i++){
      delete [] ans[i];
    } 

    delete [] ans;

    return mincost;
}

//dp appproach

int min_cost_dp(int ** matrix , int m , int n ){
    
      int** ans = new int* [m];
    for(int i = 0 ; i < m ; i++){
        ans[i]= new int [n]; 
        for(int j=0 ; j < n ; j++){
            ans[i][j] =  -1;
        }
    }



    ans [m-1][n-1] = matrix [m-1][n-1]; //last box

    for(int i= m-1 ; i >=0 ; i-- ){

        for(int j = n-1 ; j >= 0 ; j --){


            //this is kind of like my base case
            if(i == m-1 && j== n-1){
                continue; //we dont do anything at the last cell
            }

            int c1 = INT_MAX , c2 = INT_MAX , c3 = INT_MAX;

            if(i < m-1 && j < n-1){
                c1 = ans[i+1][j+1];
            }
            if( i < m-1 ){
                c2  = ans[i+1][j];
            }
            if( j< n-1 ){
                c3 = ans [i][j+1];
            }

            ans[i][j]= min(c1, min(c2,c3))  + matrix[i][j];

        }

    }


    int temp = ans[0][0];


    for(int i = 0 ; i < m ; i++){
      delete [] ans[i];
    } 

    delete [] ans;
    return temp;

}

//in this appproach we fill last row fist , then last column  and thne the rest of the matrix
int min_cost_dp_2(int **matrix , int m , int n){
    
    int** ans = new int* [m];
    for(int i = 0 ; i < m ; i++){
        ans[i]= new int [n]; 
        for(int j=0 ; j < n ; j++){
            ans[i][j] =  -1;
        }
    }

    ans [m-1][n-1] = matrix[m-1][n-1];
    //fill lasttrow
    for(int col = n-2 ; col >= 0 ; col--){
        ans[m-1][col] = matrix[m-1][col] + ans[m-1][col+1]; //last row but to the right
    }

    //fill last colum
    for( int row = m-2 ; row >= 0 ; row--){
        ans[row][n-1] = matrix[row][n-1] +  ans[row+1][n-1];
    }

    //fill the rest of the ans matriz
    for(int i = m-2 ; i >=0 ; i--){
        for(int j = n-2 ; j >=  0 ; j--){
            ans[i][j] = min(ans[i+1][j] , min(ans[i+1][j+1],ans[i][j+1])) + matrix[i][j];
        }

    }
    int temp = ans[0][0];




    for(int i = 0 ; i < m ; i++){
      delete [] ans[i];
    } 

    delete [] ans;
    return temp;

}



int main(){

    cout<<"The program will tell you the lowest cost to reach the last index from 0,0 "<<endl;

    int m {0};
    int n {0};

    cout<<"Enter number of rows and colums of matrix - ";
    cin>>m >> n;

    int** input = new int*[m];
    for(int i{0}  ; i < n ; i++){
        input[i] = new int [n];
    }

    cout <<"Entw the values row wise - \n";

    for(int i = 0 ; i < m   ; i++){
        for(int j = 0 ; j <  n ; j++){
            cin>>input[i][j];
        }
        
    } 

    int ans = min_cost_dp(input, m , n);
    cout<<"Min cost if we go from 0,0  to "<<m<<','<<n<<" is "<<ans;


    for(int i{0}  ; i < n ; i++){
        delete [] input[i];
    }

    delete [] input;



}