/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1
*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//this function helps us visit an certain island group 
//si is the starting island


//iteratve logic is faster but consumes some extra space 
//maybe due to fucntion callig
void visit_iterative(int** edges , int n , int SI , bool* visited ){
    
    queue<int> pending;
    pending.push(SI);
    visited[SI] = true;

    while(!pending.empty()){

        int c = pending.front();
        for(int i = 0 ; i <  n ; i++){
            if( c==i || visited[i] ){
                continue;
            }
            if(edges[c][i] == 1){
                visited[i] = true;
                pending.push(i);
            }
        }
    }

}

void visit (int** edges , int n , int SI , bool* visited ){
    visited[SI] = true ;
    
    for(int i = 0 ; i < n ; i++){
        if(visited[i] || i==SI){
            continue;
        }
        if(edges[SI][i] == 1){
            visit(edges , n , i , visited);
        }
    }
    return ;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{

    //i need to have a ,map of my islands to know what are my components 
    //and which islands are connected and which arent 
    //for this we are gonna use an adjacency matrix 
    //and keep track of island groups

    int**edges = new int*[n];
    for(int i=0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j{0} ; j < n ; j++ ){
            
            edges[i][j] = 0 ; //no paths / islabns connected till now

        }
    }

    for(int i{0} ; i < m ; i++){
        int x = 0 ; 
        int y = 0 ;

        x = u[i];
        y = v[i]; //we have one set of cordinates x and y now 

        //now the values in the lists u and i starts from 1 and go to N
        //but our indices of adacency matric go from 0 to N-1
        //so if we are given that we have island 1  connected to  island 2
        //we can interpret this as island 0 to connecte to island 1 
        //and this wont change our results
        x-=1; //reason mentioned above 
        y-=1;

        edges[x][y] = 1; //island are connected bothw ways
        edges[y][x] = 1; //in reality island x+1 is connected to island y+1 and vice versa

    }

    bool*visited = new bool[n];
    for(int i{0} ; i<n ; i++){
        visited[i] =  false; //not visited till now 
    }

    //we need to make a function wehch tells us how many visits are needs to the islad region to go through 
    //all the island 
    //suppose i take  a fligjt to island 1 so i can travel to all other island  by car and dont need any more
    //flight tickets ,but if a certain group is disn=conneced we ll take flight to one pf the islands 
    //in that group and then travel the whoe region by car
    int tickets = 0 ;
    for(int i = 0 ; i < n ; i++){

        if(!visited[i]){
            visit(edges , n , i , visited);
            tickets+=1;
        }
    }
    
    for(int i{0} ; i < n ; i++){
        delete[] edges[i];
    }    
    delete [] edges;
    return tickets;
}


int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}