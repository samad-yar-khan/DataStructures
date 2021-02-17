/*
Code : Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/
#include<iostream>
#include<algorithm>
using namespace std;

class edges {

    public:
    int source;
    int destination;
    int weight;

    edges(){
        source = 0 ;
        destination = 0 ;
        weight = 0 ; 
    }
};

//comparator function
bool compare_weights(edges e1 , edges e2){
    return e1.weight<e2.weight;
}

//this function basicaly returns the parents of a vertex in the mst
int parents(int v , int*parent ){

    int v_i = v;
    int k = parent[v_i];
    while(k!=v_i){
        v_i = k;
        k=parent[v_i];
    }
    return k;
}

int main(){

    int V=0, E=0;
    cout<<"Enter the number of vertices : ";
    cin >> V ;
    cout<<"Enter the number of edges : ";
    cin >> E ;

    cout<<"Enter all edges along with their weighted (Weighted Graphs) : "<<endl;
    edges * input = new edges[E];
    for(int i{0} ; i < E ; i++){
        int x=0 , y= 0  ,z=0 ;
        cin>>x>>y>>z;

        input[i].source = min(x,y);
        input[i].destination = max(x,y);
        input[i].weight = z;
    }

    //now iknow all my edges 
    //what we need to do is sort these edges based on wts
    //this uses a comparator fucnc to sort the edges according to wts

    sort(input , input+E , compare_weights);

    edges *MST = new edges[V-1];
    
    int* parent = new int[V];
    for(int i{0} ; i < V ; i++){
        parent[i]  = i ; //eacch is its owen parents at first
    }

    int count = 0 ;
    int i = 0 ;
    cout<<"MST using kruksals algorithm "<<endl;
    while(count < V-1){

        int V1 = input[i].source;
        int V2 = input[i].destination;
        int P1 = parents(V1,parent);
        int P2 = parents(V2,parent);

        if(P1 == P2){
            i++;
            continue; //if parents are same we sip this dhe
        }
        MST[count] = input[i]; //this is the copy contruor and copies this edge onto our 
        parent[P1] = P2; //because P1 is the top most parenst such that P1 is is own parent
        count++;
        i++;

    }

    for(int i{0} ; i < V-1 ; i++){
        cout<<MST[i].source<<" "<<MST[i].destination<<" "<<MST[i].weight<<endl;
    }

    delete[] MST;
    delete[] input ;
    delete[] parent;
    return 0;
}

