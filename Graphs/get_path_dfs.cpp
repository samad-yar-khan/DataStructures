/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include <iostream>
#include <vector>
using namespace std;

void get_path(int** edges , int V , int vertex_1 ,int vertex_2);
vector<int> get_path(int** edges , int V, int vertex_1 ,int vertex_2,bool* visited);


int main()
{
    int V = 0 , E = 0 ;
    cin >> V >> E;

    //adjacency matrix
    int** edges = new int* [V];
    for(int i = 0 ; i < V ; i ++){
        edges [i] = new int[V];
        for(int j = 0 ; j < V ; j++ ){
            edges [i][j] = 0 ;
        }
    }

    //setting the edges
    for(int i{0} ; i < E ; i++){

        int x = 0 , y = 0 ;
        cin>>x>>y;

        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    int vertex_1 = 0 , vertex_2 = 0 ;
    cin>>vertex_1>>vertex_2;

    get_path(edges , V , vertex_1 , vertex_2);
    
    for(int i = 0 ; i < V ; i++){
        delete [] edges[i];
    }
    delete [] edges;


    return 0;
}

void get_path(int** edges , int V , int vertex_1 ,int vertex_2){

    bool* visited = new bool[V];
    for(int i{0} ; i<V ; i++){
        visited[i] = false;
    }

    vector<int> ans = get_path(edges , V , vertex_1 , vertex_2 , visited);
    for (auto v:ans){
        cout<<v<<" ";
    }
    
    delete [] visited;

}
vector<int> get_path(int** edges , int V, int vertex_1 ,int vertex_2,bool* visited){

    //base 
    visited[vertex_1] = true;
    if(vertex_1 == vertex_2){
        vector<int> ans;
        ans.push_back(vertex_1);
        return ans;
    }

    for(int i = 0 ; i < V  ; i++){

        if(i==vertex_1 ||visited[i]){
            continue;
        }
        if(edges[vertex_1][i] == 1){
            vector<int> ans_t = get_path( edges , V , i , vertex_2 , visited );
            if(ans_t.size() != 0){
                ans_t.push_back(vertex_1);
                return ans_t;
            }
        }
    }

    vector<int> ans;
    return ans ;

}