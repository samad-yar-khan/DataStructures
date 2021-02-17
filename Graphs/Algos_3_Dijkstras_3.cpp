#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class compare{

    public:
    bool operator() (pair<int,int> v1 , pair<int,int>v2){
        return v1.second>v2.second;
    }
    
};

void Dijaktras(vector<pair<int,int>>*edges ,int V ,int E){

    bool*visited = new bool[V];
    pair<int,int>*distances = new pair<int,int>[V] ;
    for(int i{0} ; i < V ; i++){
        visited[i] = false;
        distances[i].first = i ;
        distances[i].second =  INT_MAX;
    }

    distances[0].second = 0 ;
    priority_queue<pair<int,int> , vector<pair<int,int>> , compare> pending;
    pending.push(distances[0]);

    for(int i{0} ; i < V ; i++){

        pair<int,int> min_vertex = pending.top();
        pending.pop();
        if(visited[min_vertex.first]){
        min_vertex = pending.top();
        pending.pop(); 
        }

        visited[min_vertex.first]=true;

        int our_vertex = min_vertex.first;
        int our_distance = min_vertex.second;

        for(int j = 0 ; j < edges[our_vertex].size() ; j++){

            int neighbour = edges[our_vertex][j].first;
            if(!visited[neighbour]){
                if(distances[neighbour].second > our_distance+edges[our_vertex][j].second){
                    distances[neighbour].second=our_distance+edges[our_vertex][j].second;
                    pending.push(distances[neighbour]);
                }
                
            }

        }

    }

    for(int i = 0 ; i < V ; i++){
        cout<<i<<" "<<distances[i].second<<endl;
    }

    
    
}


int main()
{
    int V{0}, E{0};
    cout <<"Ente the number of vertices and edges for your weighted graph : ";
    cin >> V >> E;

    //adjacency matrix
    vector<pair<int,int>>*edges = new vector<pair<int,int>>[V];

    //input
    cout<<"Enter all the "<<E<<" edges followed by their weight "<<endl;
    for(int i {0} ; i < E ; i++ ){

        int x ,  y , wt ;
        cin>>x>>y>>wt;
        pair<int , int>p(y,wt);
        edges[x].push_back(p);
        p.first = x;
        edges[y].push_back(p);
        
    }

    Dijaktras(edges,V ,E);
    delete[] edges ;
    
    return 0;
}
