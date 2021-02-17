/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/


#include<bits/stdc++.h>
using namespace std;
#define MAXN 102


int solve(char Graph[][MAXN],int N, int M);

int main()
{
    //bacciallly a 2d char array 
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}


//this is teh final paths reursive func ,
//it takes the visite array along with the string "CODINGNINJA" and  variable p 
//which tell us which tell us the inedex for our string or the next chae which we have to find
//it marks a char visited , upon visit and this stops us from infinte recusrive calls

int paths(char Graph[][MAXN],int N, int M , int i , int j,int p , char* word , bool** visited){

    visited[i][j] = true ;

    //base
    if(word[p-1] == 'A'){
        return 1;
    }

    for(int x = i-1 ; x <= i+1 ; x++){
        for(int y = j-1 ; y <= j+1 ; y++){
            if( x < 0 || y < 0 || x >=N || y >= M || visited[x][y]){
                continue;
            }
            if(Graph[x][y] == word[p]){
                int ans = paths(Graph , N , M , x , y , p+1 , word , visited);
                if(ans == 1){
                    return 1;
                }
            }
        }
    }

    return 0 ;


}

//this function will be caalled when we find c and what is does is :->
//it forms a 2D matric to keep track of the elements which we are vistsing when we start DFS from
//particular C , we  calll anther fucntion and feed our visited matrix to it
//along with this the next funcion is a overloaded version of below func
//it also takes the word coding ninjs along with the index where we are and the next letter we need to find

int paths(char Graph[][MAXN],int N, int M , int i , int j ){

    //we eenter this when we find a C
    bool** visited = new bool*[N];
    for(int i {0} ; i<N ; i++ ){
        visited[i] = new bool[M];
        for(int j{0} ; j<M ; j++){
            visited[i][j] = false;
        }
    }

    char word [] = {"CODINGNINJA"} ;

    int ans = paths(Graph , N , M , i , j , 1 , word , visited);
    for(int i = 0 ; i < N ; i++){
        delete[] visited[i];
    }
    delete[] visited;
    return ans;
}

//we find C and call the recursive function C because that whats lead to codingninjas using DFS
int solve(char Graph[][MAXN],int N, int M)
{
	
   for(int i = 0 ; i < N ; i++){
       for(int j = 0 ; j < M ; j++){

           if(Graph[i][j] == 'C'){

               int ans = paths(Graph , N , M , i , j );
               if(ans == 1){
                   return 1;
               }
           }
       }
   }

    return 0;
}
