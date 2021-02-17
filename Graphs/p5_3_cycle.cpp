/*

3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1

*/

//incorrect logic 

#include<iostream>
#include<vector>
using namespace std;


int check(int n , int**edges , pair <bool , int>* visited , int vertex, int position ){

	visited[vertex].first = true ;
	visited[vertex].second = position;

	int ans = 0 ; 

	//base case
	//if we see a previsited vertex has and edge with us and we dffer by 3 posistions , thats means its a cycle and we add 1 to oour ans

	for(int j = 0 ; j < n ; j++){
		
		if(edges[vertex][j] == 1 && visited[j].first && j!=vertex){

			int distance = position-visited[j].second + 1; //firts we check if a connected vrtex is frminga a 3 cycle with us r not

			if(distance == 3){
				ans+=1;
			}

		}

	}

	//iH + Is
	//we visited all unviste paths and store their ans in our ans 
	for(int j = 0 ; j < n ; j++){
		
		if(edges[vertex][j] == 1 && !visited[j].first && j!=vertex){

			ans+=check(n , edges , visited , j , position+1);

		}

	}

	return ans ;



}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    //reprsent these edges using and eadjcency matrix on a amap

    int**edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            edges [i][j] = 0 ; //no connectons till now
        }
    }

    for(int i = 0 ; i < m ; i++){
        int x = u[i]-1;
        int y = v[i]-1;//becais our marix indexing stars from zero but our elments are from 1 to N

        edges[x][y] = 1;
        edges[y][x] = 1;
    }

	int ans = 0 ;
	//with the bellow matrix we aim at checking a vertex if its visited an noting down its position
	//while traversing in dfs poition 
	//if wee run into a previsited vertex and the diff of position is euqal to 3
	//that emean we have got  cyclle of 3

	pair<bool , int>* visited = new pair<bool , int>[n];
	for(int i = 0 ; i < n ; i++){
		visited[i].first = true ;
		visited[i].second = 0 ;
	}

	for(int i {0} ; i < n ; i++){
		if(!visited[i].first){
			ans += check(n , edges , visited , i , 0 );
		}
	}
	
	


	delete [] visited;
	for(int i = 0 ; i < n ; i++ ){
		delete [ ] edges [i];
	}
	delete [ ]edges ;
	return ans;
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
