
#include<iostream>
#include<queue>
using namespace std;

//thes efunctions wil print the graphs for disconected trees asswell
//what we did earlier was that we just put starting vertex as 0 and rinted alll elemets connected to it 
//but that is not enoough if our grahs consists of more componenents 
//so what we doo is we chose diifeent vals of Sstarti ng vertex for the print functn from our vsted arra
//in this way all components get places 

void print_dfs(int **edges , int n , int sv , bool* visited ){

    cout<<sv<<" ";
    visited[sv] = true ;

    for(int i = 0 ; i < n ; i++ ){
        
        if(i == sv || visited[i]){
            continue;
        }
        if(edges[sv][i]==1){
            print_dfs(edges , n , i , visited);
        }
    }

}   

void DFS(int **edges , int n){
    
    bool* visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }

    for(int i = 0 ; i < n ; i++ ){
        if(!visited[i]){
            print_dfs(edges , n , i , visited);
        }
    }

    
}

 void print_bfs (int**edges ,int n , int SV , bool*visited){

    queue<int> pending_v ;
    pending_v.push(SV);
    visited[SV] = true;

    while(!pending_v.empty()){
        
        int current_vertex = pending_v.front();
        cout<<current_vertex<<" ";
        pending_v.pop();
        for(int i = 0 ; i < n ; i++){
            if(current_vertex==i){
                continue;
            }

            if( edges[current_vertex][i] == 1 && !visited[i] ){
                pending_v.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS (int ** edges , int n){

    bool*  visited = new bool [n];
    for(int i {0} ; i < n ; i++){
    visited[i] = false;
    }
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            print_bfs (edges , n , i , visited);
        }
    }
    delete[] visited;
}


int main() {
    int V, E; 
    cout<<"Enter no of vertices followed by number of edges - ";
    cin >> V >> E;

    //addacency matrix
    int**edges = new int*[V];
    for(int i = 0 ; i < V ; i++){
        edges[i] = new int[V];

        for(int j = 0 ; j < V ; j++ ){
            edges[i][j] = 0 ; //0 indicates no edge bw vertex i and j
        }
    }

    //input 
    cout<<"Enter the edges in pairs of edges - "<<endl;
    for(int i{0} ; i < E ; i++){
        int x = 0 , y =  0 ;
        cin>>x>>y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    BFS(edges , V);
    cout<<"\n";
    DFS(edges , V );

    for(int i = 0 ; i < V ; i++){
        delete [] edges[i];
    }
    delete[] edges ;
    return 0;
}


/*
7
8
0 1
0 2
1 3
1 4`
3 5
4 5
5 6
*/