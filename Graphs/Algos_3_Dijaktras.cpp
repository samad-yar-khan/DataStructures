
/*

Code : Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5

*/

#include <iostream>
#include <climits>
#include <queue>
using namespace std;

int min_distance_vertex(int* distance ,bool* visited,int V){

    int min_vertex = -1 ;
    for(int i = 0 ; i < V ; i++){
        if(!visited[i] && (min_vertex == -1 || distance[i] < distance[min_vertex])){
            min_vertex = i;
        }
    }
    return min_vertex;
}

void   Djaktras(int**edges,int V ,int E){
    cout<<"DJAKSTRAS ALGO FOUND THE MIN DISTANCE OF EACH VERTEX FROM SOURCE VRTEX 0 "<<endl;
    bool*visited = new bool [V]; //for viisted status
    int*distance =  new int[V]; //distabce from source

    //initilaise that none of the vertcs have been visited so  far and distance of all vertices to be infinitty
   

    for(int i{0} ; i < V ; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    //now we need to make 0 the source vertex ad calculate the distanc of each vertex from 0
    distance[0] = 0 ;
    for(int i = 0 ; i < V ; i++){ //compexity---> V

        int current_vertex  = min_distance_vertex(distance , visited ,V);//complexity->>>V
        visited[current_vertex] = true;
        //go through all unviisted neibours and update curent distttance if distance through current vertex iss smaller
        for(int j{0} ; j < V ; j++){///----> V iteartaions

            if(!visited[j]&&edges[current_vertex][j]!=0){
                int my_distance = distance[current_vertex] + edges[current_vertex][j];
                int existing_distance = distance[j];
                if(my_distance < existing_distance){
                    distance[j] = my_distance;
                }
            }
        }
    }
    //Overall compexity is O(V(V+V)) = O(V^2)
    //we can inprove this compexity bb usinga a priorti quue instead of min function
    //and using edge list instead of the goddam adjacency matrix
    cout<<"edge    distance"<<endl;;
    for(int i = 0 ; i < V ; i++){
        cout<<i<<"        "<<distance[i]<<endl;
    }

    delete [] visited;
    delete [] distance;
}


int main()
{
    int V{0}, E{0};
    cout <<"Ente the number of vertices and edges for your weighted graph : ";
    cin >> V >> E;

    //adjacency matrix
    int**edges  = new int*[V];
    for(int i{0} ; i < V ; i++){
        edges[i] = new int[V];
        for(int j{0}  ; j < V ; j++){
            edges[i][j] = 0;
        }
    }

    //input
    cout<<"Enter all the "<<E<<" edges followed by their weight "<<endl;
    for(int i {0} ; i < E ; i++ ){

        int x {0} , y{0} , wt{0}; //edges have some wt
        cin>>x>>y>>wt;

        edges[x][y] = wt;
        edges[y][x] = wt;
    
    }

    Djaktras(edges,V ,E);

    for(int i{0} ; i < V ; i++){
        delete[]edges [i];
    }
    delete[] edges ;
    
    return 0;
}
