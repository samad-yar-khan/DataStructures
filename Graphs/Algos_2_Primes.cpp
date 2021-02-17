/*
Code : Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/

/*
LOGIC :

//1)INPUT
    //-> we  take input of the wighted graph in an adjacency matric in our main fucntion
    -> edges[x][y] stores the weight of edge x---y or y---x , if edge doesnt exist , value of edge weight will be zero
2)Prims  step 1
    -> We maintain some propertis of each vertex 'i' in different arrays 
    -> We asume that  each node will only have one parent and only one parent vertex will lead t its path to avoid cyclisation
    -> We maintain PARENT , WEIGHT and VISITED status of each vertex
     
    *initialise weighhts of all vertices to infinity 
    *initialise visited status to false as , none of the edges have been visited so far

    step2

    ->now we mark 0 as the source vertx and mark its paarent to be -1 and its wt to be 0 
    ->now we go to all unvited neighbors of 0 and if theri wt is more than their edge wt through us
    matab agar unka wt initially 10 hai , ya unse pochne wale edge ka wt 10 hai and hamar edge jo us vertii tak jata hai
    agar uska wt 10 se kam hai , that means we should go to that vertex through our vertex 
    so in this case we iitilise its wt to the wt through us and we will upate that our vertex is its parents vertex noow
    ham uske parent hai ab kyu uska rasta hame hokar jarra hai
    ya ham us tak tree pocha rahe hai

    ->now we  go the next minimun weighted unvisited  vertex and go through all its unvisusted vertex and repeaat the same process
    ->now there are V vertices and at max we vist each vertex once , and we dont even dont do any work at the last vertex 
      because by the time we reach there all other vertices will be viisted already , so in reality we ony need v-1 iterations 
     but wejust visit the last vertex (masti mai noot really a reason)
    ->but through this we can see ki ham har evrtex pe ek bar hi jayenge 
    ->to bas V itteration h chahiye jaha ham ye sab kam karke
    har vertex ka parent , wt and visted status pdate karenge
*/

#include <iostream>
#include <climits>
using namespace std;

//this function gives us tthe next min weighted vertex out of the left unvisted vertices  
int next_vertex (bool*visited , int * weight , int V){

    int min_vertex = -1 ;
    int min_vertex_weight = INT_MAX;
    for(int i {0} ; i < V ; i++){
        if(!visited[i] && min_vertex_weight> weight[i]){
            min_vertex=i;
            min_vertex_weight = weight[i];
        }
    }

    return min_vertex;
}


//this function is the Prims ALGO
void prim(int**edges , int V , int E){

    bool *visited = new bool[V];
    int *parent = new int[V];
    int * weight = new int[V];

    for(int i{0} ; i < V ; i++){
        visited[i] = false;
        weight [i] = INT_MAX; //infinite weight initially
    } 

    //mark zero as source
    weight[0] = 0 ;
    parent[0] = -1 ;

    //we ll max visit all v vertices so only v iteation are needed

    for(int i{0} ; i < V ; i++){

        int min_vertex = next_vertex(visited , weight , V);
        visited[min_vertex] = true;
        for(int j{0} ; j < V ; j++){

            if(!visited[j] && edges[min_vertex][j]!=0 ){

                if(edges[min_vertex][j] < weight[j]){
                    parent[j] = min_vertex;
                    weight[j] = edges[min_vertex][j];
                }
            }
        }
    }

    for(int i = 1 ; i < V ; i++){

        if(i < parent[i]){
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }else{
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }


}

int main()
{
    int V, E;
   
    cout<<"Enter the number of vertices followed by edges \n";
    cin>>V>>E;
    //adjacencys m atrix
    int**edges = new int*[V];
    for(int i {0} ; i <V ; i++){
        edges[i]  = new int[V];
        for(int j = 0 ; j < V ; j++){
            edges[i][j] = 0 ;
        }
    } 
    cout<<"Enter all the edges and their weights \n";
    for(int i{0} ; i < E ; i++){
        int x = 0 , y = 0 , wt = 0 ;
        cin>>x>>y>>wt;

        edges[x][y] = wt;
        edges[y][x] = wt;
    }

    cout<<"MSP using prims : \n";
    prim(edges , V , E );

    return 0;
}
