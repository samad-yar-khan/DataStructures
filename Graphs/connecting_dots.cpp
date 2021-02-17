/*
Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/


#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

int check_circle(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited  , int i , int j );
int check_circle_2(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited , int i , int j , int position);
int solve(char board[][MAXN],int n, int m);

int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}

int solve(char board[][MAXN],int n, int m){

    //my visited matrix will have a  bool and index value , to tell what is the index of that 
    //visited positon in my seqeunce , this wll help us maintain o(M*N)complexity , avoid repettion


    pair<bool , int >** visited = new pair <bool , int >*[n];
    for(int i = 0 ; i < n ; i ++ ){

        visited[i] = new pair<bool , int >[m];
        for( int j = 0 ; j < m ; j++ ){

            visited[i][j].first=false;
            visited[i][j].second=0;

        }

    }
    int ans = 0 ;
    bool break_loop= false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){

            if(!visited[i][j].first){
                ans = check_circle(board , n , m , board[i][j] , visited , i , j );
                if(ans == 1){
                    break_loop= true;
                    break;
                }
            }

        }
        if(break_loop){
            break;
        }

    }

    for(int i{0} ; i < n ; i++){
        delete[] visited[i];
    }
    delete[] visited;
    return ans ;
}

//basccia;;y whata happens it wit visited we also strore the posiition of that elmenst in the color que
//if the queue runs into itself , by subtracting the positions we can isntanty tell if the diiif or position is equal to 4 or not
//and we can  give the aswe accordngy
int check_circle_2(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited , int i , int j , int position)
{

    visited[i][j].first= true ;
    visited[i][j].second = position ;

    //base cases

    //x will be added to i and y added to j an this will be check at ffour positins
    //up , left , down , right and thats what ww wilsh to do

//kind of like a video game controller , up , down , left rigt 
    int x[4] ={-1,0,1,0};
    int y[4] ={0,-1,0,1};

    //thiis for loop compensates for all below if else stateenst and checks all the positions whicha re needed  
    for(int k = 0 ; k < 4 ; k++){

        int new_i = i + x[k]; //this is basically the next adjacent cell
        int new_j = j + y[k];

        if(new_i >=0 && new_i <n && new_j >=0 && new_j < m && board[new_i][new_j] == color){//this check if the coordinate we are lookng up are wihin bounds

            int num_positions = position - visited[new_i][new_j].second + 1 ; //tells numver of positiosn between the this next dot and our dot
            //for a circle to occur this should be min 4

            //IF ANY OF THE FOUR CELLS ARE PRE VISITED AND THE loop / circle occurs after a minimun of 4 dots 
            //in the sequnce , then its a circle and we return true
            if(visited[new_i][new_j].first && num_positions >=4){
                return 1;
            }
        }
    }

    // if( i-1 >= 0 && board[i-1][j] == color ){
    //     if(visited[i-1][j].first &&  (position - visited[i-1][j].second +1 >= 4 )){
    //         return 1;
    //     }
    // }
    //  if( j-1 >= 0 && board[i][j-1] == color ){
    //     if(visited[i][j-1].first &&  (position - visited[i][j-1].second +1 >= 4 )){
    //         return 1;
    //     }
    // }
    //  if( i+1 < n && board[i+1][j] == color ){
    //     if(visited[i+1][j].first &&  (position - visited[i+1][j].second +1 >= 4 )){
    //         return 1;
    //     }
    // }
    //  if( j+1 < m && board[i][j+1] == color ){
    //     if(visited[i][j+1].first &&  (position - visited[i][j+1].second +1 >= 4 )){
    //         return 1;
    //     }
    // }

    //IS 
    // We go on checking of any of the adjaccent mcell is of our color and within bounds
    //if we find one which is not viited , we call recursion on it 
    //if a circle is  found via the routr , we return true 
    //if we come out of the lloop it means , we codulnt find the aans via any of the paths and we return false
    int ans = 0 ;

    for(int k = 0 ; k < 4 ; k++){

        int new_i = i + x[k]; //this is basically the next adjacent cell
        int new_j = j + y[k];

        if(new_i >=0 && new_i <n && new_j >=0 && new_j < m && board[new_i][new_j]==color){//this check if the coordinate we are lookng up are wihin bounds

            if(!visited[new_i][new_j].first){
                
                ans = check_circle_2(board , n , m , color , visited , new_i , new_j , position+1);
                if(ans == 1){
                    return 1;
                }

            }

        }
    }

    //the above loops replaced all the below if else using somewtaht like a joystick concept 
    //using array x and y , where we check up down lefta nd riigght


    // if( i-1 >= 0 && board[i-1][j] == color ){
    //     if(!visited[i-1][j].first){
    //         ans = check_circle_2(board , n , m , color , visited , i-1 , j , position+1);
    //         if(ans == 1){
    //             return 1;
    //         }
    //     }
    // }

    //  if( j-1 >= 0 && board[i][j-1] == color ){
    //     if(!visited[i][j-1].first){
    //         ans = check_circle_2(board , n , m ,color, visited , i , j-1 , position+1);
    //         if(ans == 1){
    //             return 1;
    //         }
    //     }
        
    // }

    //  if( i+1 < n && board[i+1][j] == color ){
    //    if(!visited[i+1][j].first){
    //        ans = check_circle_2(board , n , m , color , visited , i + 1 , j , position+1);
    //         if(ans == 1){
    //             return 1;
    //         }
    //    }
    // }
    //  if( j+1 < m && board[i][j+1] == color ){
    //     if(!visited[i][j+1].first){
    //        ans = check_circle_2(board , n , m , color , visited , i , j+1 , position+1);
    //         if(ans == 1){
    //             return 1;
    //         }
    //    }
    // }

    return 0 ;




}

int check_circle(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited , int i , int j ){

    int ans = check_circle_2(board , n , m , color , visited , i , j , 0 );
    return ans;
}
