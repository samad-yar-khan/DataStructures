/*
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/


// #include <iostream>
// #include<algorithm>
// #include <queue>
// #include <vector>
#include <bits/stdc++.h> 

using namespace std;

vector <int> comp(int** edges ,int V ,int SV ,bool* visited){

    queue<int>pending;
    pending.push(SV);
    visited[SV] = true;
    vector<int> graphs_c;
    graphs_c.push_back(SV);

    while(!pending.empty()){

        int c = pending.front();
        pending.pop();

        for(int i = 0 ; i < V ; i++ ){
            if(c==i || visited[i]){
                continue;
            }
            if(edges[c][i] == 1){
                pending.push(i);
                graphs_c.push_back(i);
                visited[i]= true;;
            }
        }

    }
    return graphs_c; 

}


void all_componets (int**edges , int V){

    bool*visited = new bool[V];
    for(int i{0} ; i < V ; i++){
        visited[i] = false;
    }

    vector<vector<int>> componenets ;

    for(int i{0} ; i < V ; i++){
        if(!visited[i]){
            componenets.push_back(comp(edges , V , i , visited));
        }
    }

    for(auto i : componenets){
       sort(i.begin() , i.end());
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    delete[] visited;

}


int main()
{
    int V, E ;
    cin >> V >> E;

    int** edges = new int*[V];
    for(int i{0} ; i < V ; i++){
        edges[i] = new int[V];
        for(int j = 0 ; j < V ; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0 ; i < E ; i++){
        int x = 0 , y = 0 ;
        cin>>x>>y;
        edges[x][y] = 1;
        edges[y][x] = 1;

    }


    all_componets(edges , V);
    for(int i{0} ; i<V ; i++){
        delete[] edges[i];
    }
    delete[] edges ;

    
    return 0;
}
