/*
Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

void path(int** edges , int V , int v1 , int v2  ){

    bool*visited = new bool[V];
    for(int i= 0 ; i < V ; i++){
        visited[i] = false;
    }

    queue<int> pending_vertices;
    unordered_map< int , int > parent ;

    // 
    // whenever I push an adjacent vertex onto the queue . I make an entery  onto the map 
    // this entry tells me that which vertex pushed that key vertex on the map ex
    // map[i] = j , signifies that i was ppushed onto the queue by j or j is the adjacent certex of 
    // i which pushed it onto the queue and this helps us retrace the bfs path/shorted path of v1 to v2
    // 

    vector<int> full_path;

    pending_vertices.push(v1);
    visited[v1] = true;

    while(!pending_vertices.empty()){

        int current_vertex = pending_vertices.front();
        pending_vertices.pop();

        //This is the condition when I stop . and i hae reached vw
        if(current_vertex == v2){
            int x = v2;
            full_path.push_back(x);
            while(x!=v1){
                x = parent[x];
                full_path.push_back(x);
            }
        break;
        }

        for(int i = 0 ; i < V ; i++){

            if (current_vertex == i || visited[i]){
                continue;
            }

            if(edges[current_vertex][i] == 1){
                parent[i] = current_vertex;
                visited[i] = true ;
                pending_vertices.push(i);
            }
        }
    }

    for(auto v:full_path){
        cout<<v<<" ";
    }


    delete [] visited ;
}

int main()
{
    int V, E ;
    cout<<"Enter number of  vertices and edges of the graps - ";
    cin>>V>>E;

    //adjacency matrix
    int**edges = new int*[V];
    for(int i{0} ; i < V ; i++ ){
        edges[i] = new int[V];
        for(int j{0} ; j < V ; j++){
            edges[i][j] = 0; //no connections establshes
        }
    } 

    cout<<"Enter the edges (vertex pairs) "<<endl;
    for(int i{0} ; i < E ; i++){
        int x = 0 , y = 0 ;
        cin>>x>>y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    //v1 and v2 are the pertices , the path bw these vertices are needed 
    cout<<"Enter the staring vertex and end vertex - ";
    int v1= 0 , v2 = 0 ;
    cin>>v1>>v2;
    cout<<"Path between "<<v1<<" and "<<v2<<endl;
    path(edges,V,v1,v2);


    for(int i = 0 ; i<V ; i++){
        delete  [] edges[i];
    }
    delete [] edges ;

    return 0;
}

