#define MAXN 101
#include<utility>
using namespace std;
int x[8]={-1,0,1,0};
int y[8]={0,1,0,-1};


bool isValid(int x, int y, int n , int m){
    
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    
    return true;
}
pair<bool , int> isCycle(char board[][MAXN], int n, int m, int row, int col, bool **visited,
int len, int st_i, int st_j){
    
    visited[row][col]=true;
    pair<bool, int> smallOutput;
    smallOutput.first = false;
    smallOutput.second = len;
    
    for(int i=0; i<4; i++){
        
        int new_row = row+x[i];
        int new_col = col+y[i];
        
        if(isValid(new_row, new_col, n, m) && visited[new_row][new_col]==false 
           && board[new_row][new_col]==board[row][col] ){
            
            smallOutput = isCycle(board, n, m, new_row, new_col, visited, len+1, st_i, st_j);
            
            if(smallOutput.first == true){
             
            return smallOutput;
            }
            
           /* if(smallOutput.first==false){
                visited[new_row][new_col]=false;
                
                return smallOutput;
            }*/
        }
        
        if(isValid(new_row, new_col, n, m) && visited[new_row][new_col]==true 
           && new_row == st_i && new_col == st_j){
            
            if(len >=4){
                
                smallOutput.first = true;
                smallOutput.second=len;
                return smallOutput;
            }
        }
    }
    
    visited[row][col]=false;
    return smallOutput;
    
}
int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    
    bool **visited = new bool*[n];
    
    for(int i=0; i<n; i++){
        
        visited[i]=new bool[m];
        for(int j=0; j<m; j++){
            
            visited[i][j]=false;
        }
    }
    
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<m; j++){
            
            if(visited[i][j]==false){
                
                pair<bool, int> ans = isCycle(board, n, m,i, j, visited, 1, i, j);
                
                if(ans.first == true && ans.second>= 4){
                    return 1;
                }
                visited[i][j]=false;
            }
        }
    }
    
    return 0;
}
bool helper(char board[][MAXN], int n, int m, int i, int j, bool **visited, int len, int si, int sj){
    
    
    //base case
    if(i+1==si && j==sj || i-1==si && j==sj || i==si && j+1==sj || i==si && j-1==sj){
 
          
          if(len >=4){
              
              return  true;
          }

    }
    
   
  
    visited[i][j] = true;
    
    if(i+1 < n && j>=0 && j<m ){
        
        if(board[i+1][j] == board[i][j] && !visited[i+1][j]){
            
            bool b = helper(board, n, m, i+1, j, visited, len+1, si, sj);
            
            if(b){
                return  true;
            }
        }
    }
    
    if(i-1>=0 && j>=0 && j<m){
        
        
        if(board[i-1][j] == board[i][j] && !visited[i-1][j]){
            
            bool b = helper(board, n, m , i-1, j, visited, len+1, si, sj);
            
            if(b){
                return true;
            }
        }
    }
    
    if(j+1 < m && i>=0 && i<n){
        
        if(board[i][j+1]==board[i][j] && !visited[i][j+1]){
            
            
            bool b = helper(board, n, m, i, j+1, visited, len+1, si, sj);
            
            if(b){
                return true;
            }
        }
    }
    
    if(j-1>=0 && i>=0 && i<n){
        
        if(board[i][j-1]==board[i][j] && !visited[i][j-1]){
            
            bool b = helper(board, n, m, i, j-1, visited, len+1, si, sj);
            
            if(b){
                return true;
            }
        }
    }
    
    visited[i][j]=false;
    return  false;
}
int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    
    bool **visited = new bool*[n];
    
    for(int i=0; i<n; i++){
        
        visited[i] = new bool[m];
        for(int j=0; j<m; j++){
            
            visited[i][j] = false;
        }
    }
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<m; j++){
            
            
            bool ans = helper(board, n, m, i, j, visited, 1, i, j);
            
            if(ans){
                return  true;
            }
                
            
        }
    }
    
    return  false;
}