/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/


#include <iostream>
using namespace std;

//pretty simple
//just  raverse in bfs fashion in a dfs fashion  , if any node are left unvisitedd the graphs is disconnectd

void visit_all(int** edges , int V , bool* visited , int SV){

    visited[SV] = true;
    for(int i = 0 ; i < V ; i++){

        if(i==SV ||visited[i]){
            continue;
        }

        if(edges[SV][i] == 1){
            visit_all(edges , V  , visited , i);
        }
    }
    
}


bool is_connected(int** edges , int V , int SV ){

    bool*visited = new bool[V];
    for(int i {0} ; i < V ; i++){
        visited[i]  = false ;
    }

    visit_all(edges ,  V ,  visited , SV);
    bool ans = true;
    for(int i = 0 ; i < V ; i++ ){
        if(!visited[i]){
            ans = false;
            break;
        }
    }
    delete [] visited;
    return ans;

}

int main() {
    int V, E;
    cin >> V >> E;

    //adjacncy matrix
    int** edges = new int*[V];
    for(int i{0} ; i < V ; i++){
        edges[i] = new  int[V];
        for(int j{0} ; j < V ; j++ ){
            edges[i][j] = 0;
        }
    }

    //input edges
    int SV{0};
    int x= 0 , y = 0 ;
    for(int i{0} ; i <  E ; i++){
        int x= 0 , y = 0 ;
        cin>>x>>y;

        edges[x][y] = 1;
        edges[y][x] = 1;
        
    }
    SV = y;

    cout<<boolalpha;
    cout<<is_connected(edges , V , SV);

    for(int i{0} ; i<V ; i++){
        delete[] edges[i];
    }
    delete [] edges;

  return 0;
}
