/*
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
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
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false

*/

#include <iostream>
#include<queue>
using namespace std;

//forward declarations
//BFS approach
bool path_exists(int** edges , int N , int vertex_1 , int vertex_2  );
bool has_path( int** edges , int N , int vertex_1 , int vertex_2  , bool* visited );
//DFS recrsive approach
bool path_exists_DFS(int** edges , int N , int vertex_1 , int vertex_2 );
bool has_path_DFS( int** edges , int N , int vertex_1 , int vertex_2  , bool* visited );


int main() {
    cout<<"This progam takes in a path and lets you kknow if there exists a path between two vertices of the map "<<endl;
    cout<<"\n\n";
    cout<<"Enter the number of vertices followed bby no of edges - ";
    int V, E;
    cin >> V >> E;
    //adjacency matrix 
    int** edges = new int*[V];
    for(int i = 0 ; i < V ; i++){

      edges[i] = new int[V];
      //initialising the adjacency matric to represneted that all oouor verices are disconnected at first
      for(int j = 0 ; j < V ; j++ ){
        edges[i][j] = 0 ;
      }

    }

    //edges input 
    cout<<"Enter all edges (in pairs of i,j i.e. i j signifiees a edge between vertex i & j)- "<<endl;
    for(int i {0} ; i < E ; i++ ){

      int x = 0 , y = 0;
      cin>>x>>y;

      //if x is connexcted y , then y is also connected to x
      edges[x][y] = 1 ;
      edges[y][x] = 1 ;

  }

  //vertices whose connection needs to be checked
  cout<<"Enter the 2  vertices whose connection is to be checked - ";
  int vertex_1 = 0  ,  vertex_2 = 0 ;
  cin>>vertex_1>>vertex_2;

  cout<<boolalpha;
  cout<<"There exists a path from "<<vertex_1<<" to "<<vertex_2<<" : "<<path_exists(edges,V,vertex_1,vertex_2);
  
  cout<<noboolalpha;

  for(int i {0} ; i < V ; i++ ){
    delete[] edges[i];
  }
  delete [] edges;

  return 0;
}


//BFS approach

bool path_exists(int** edges , int N , int vertex_1 , int vertex_2  ){

  bool* visited = new bool [N];
  for(int i{0} ; i < N ; i++ ){
    visited [i] = false;
  }
  bool ans = has_path(edges , N , vertex_1 , vertex_2 , visited);
  
  
  delete [] visited;
  return ans;

}

bool has_path( int** edges , int N , int vertex_1 , int vertex_2  , bool* visited ){

  queue<int> pending_vertices ;
  pending_vertices.push(vertex_1);
  visited[vertex_1] = true;

  while (!pending_vertices.empty())
  {
    
    int current_vertex = pending_vertices.front();
    pending_vertices.pop();

    for(int i = 0 ; i < N ; i++ ){

        if(current_vertex == i || visited[i]){
          continue;
        }

        //if my current vertex and i have a edge connectng em , i ll check if vetex i is vertex2 or not
        if(edges[current_vertex][i] == 1){

          if( i == vertex_2){
            visited[i] = true ;
            return true ;
          }else{
            visited[i] = true ;
            pending_vertices.push(i);
          }
       }
    }

    //if we havent found vertex 2  by this pt then its not there 
    
  }
  return false;
}


//DFS approach
bool path_exists_DFS(int** edges , int N , int vertex_1 , int vertex_2 ){

  bool* visited = new bool[N];
  for(int i{0} ; i < N ; i++){
    visited[i] = false;
  }

  bool ans  = has_path_DFS(edges  , N , vertex_1 , vertex_2 , visited);

  delete [] visited;
  return ans;

}

bool has_path_DFS( int** edges , int N , int vertex_1 , int vertex_2  , bool* visited ){

  //base
  visited[vertex_1] = true;
  
  if(vertex_1 == vertex_2 ){
    return true;
  }

  for(int i = 0 ; i < N ; i++){

    if(visited[i] || i == vertex_1 ){
      continue;
    }

    if(edges[vertex_1][i] == 1){
      bool ans = has_path_DFS(edges , N , i , vertex_2 , visited);
      if(ans){
        return ans;
      }
    }

  }

  return false;
 
}
