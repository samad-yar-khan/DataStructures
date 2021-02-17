/*

Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3

*/

#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55


//logic 
//if i find a 1 i call cake_size fnction on tht 1 o know the size of that piece of 1s containig that peice
//now  insisde my cake size func , i maek my elemnet visted and then call recursion on the 1st whih share edge with
//my 1 and havent been viisteed , recusion gives me an ans  and i add my 1 to it ad retuen the fianl ans 
int cake_size (int n,char cake[][NMAX] , int i , int j , bool**visited  ){

    visited[i][j]= true;
    int x[4]={-1,0,1,0};
    int y[4]={0,-1,0,1};

    //induction hypotheisis
    int small_ans = 0;
    for(int k = 0 ; k < 4 ; k++){
        
        int i_next = i+x[k];
        int j_next = j+y[k];

        if(i_next >=0 && i_next < n && j_next >=0 && j_next < n ){
            if(cake[i_next][j_next]=='1' && !visited[i_next][j_next]){
                small_ans+=cake_size(n,cake ,i_next,j_next,visited);
            }
        }
    }

    //induction step
    int total_ans = small_ans+1; //i add my one to all the 1s wwhich were returned by recursion an stored in small output

    return total_ans;
}

int solve(int n,char cake[NMAX][NMAX])
{
	bool**visited = new bool*[n];
    for(int i{0} ; i < n ; i++){
        visited[i] = new bool[n];
        for(int j{0} ; j < n ; j++){
            visited[i][j] = false;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for(int j{0} ; j < n ; j++){
            if(!visited[i][j] && cake[i][j] == '1'){
                int temp = cake_size(n , cake , i , j , visited  );
                ans = max(ans,temp);
            }
        }
    }
    

    for(int i{0} ; i< n ; i++){
        delete[] visited[i];
    }
    delete[] visited;
    return ans;
}

int main()
{
	int n;
	cin>>n;
    char cake[NMAX][NMAX];
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}