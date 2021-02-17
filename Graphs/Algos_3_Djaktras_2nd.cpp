#include <iostream>
#include <climits>
#include <queue>
using namespace std;


//change to vector of vector of pais
//my negbouring nodes would be connected to each other and my vertex using ths class
class node {
    public:
    int wt;
    int vertex ;
    node* next;

    node(){
        wt = 0 ;
        vertex = 0;
        next = NULL;
    }

    node(int vertex , int wt , node* next = NULL){
        this->wt = wt ;
        this->vertex = vertex;
        this->next = next;
    }

    ~node(){
        delete next;
    }

};

void add_node(node**heads , node** tails , int x , int y  , int wt){

    if(heads[x] == NULL ){
        heads[x] = new node(y,wt);
        tails[x] = heads[x];
    }else{
        tails[x]->next = new node(y,wt);
        tails[x] = tails[x]->next;
    }

    if(heads[y] == NULL){
        heads[y] = new node(x , wt);
        tails[y] = heads[y];
    }else{
        tails[y]->next = new node(x,wt);
        tails[y] = tails[y]->next;
    }
}

class compare{

    public:
    bool operator() (pair<int,int> v1 , pair<int,int>v2){
        return v1.second>v2.second;
    }
};

void   Djaktras(node**head,node**tail,int V ,int E){

    cout<<"DJAKSTRAS ALGO FOUND THE MIN DISTANCE OF EACH VERTEX FROM SOURCE VRTEX 0 "<<endl;

    bool*visited = new bool [V]; //for viisted status
    pair<int , int>*distances =  new pair<int , int >[V]; //distabce from source

    //initilaise that none of the vertcs have been visited so  far and distance of all vertices to be infinitty
   
    //INITIALISER

    for(int i{0} ; i < V ; i++){
        visited[i] = false;
        distances[i].first = i;
        distances[i].second = INT_MAX;
    }

    //now we need to make 0 the source vertex ad calculate the distanc of each vertex from 0
    distances[0].second = 0 ;

    priority_queue<pair<int,int> , vector<pair<int,int>> , compare> pending;

    pending.push(distances[0]);

    for(int i{0} ; i < V ; i++){
        
        //since we have different distaces of same vertex , it may happene that a same vertex i spopped again

        pair<int , int > min_vertex = pending.top();
        pending.pop();
        int my_vertex = min_vertex.first;

        while(visited[my_vertex]){
            min_vertex = pending.top();
            pending.pop();
            my_vertex = min_vertex.first;
        }

        visited[my_vertex] = true;

        node*neighbours = head [my_vertex];

        while(neighbours!=NULL){

            int neighbour = neighbours->vertex;
            // if(visited[neighbour]){
            //     neighbours = neighbours->next; //i had in initially missed this step . If our neigbour is visted , we need to go to the next before we hit a continue statement
            //     continue;                      // else we run into an infinite loop
            // }
            // int edge_length = neighbours->wt;
            // int distance_through_me = distances[my_vertex].second + edge_length;
            // if(distances[neighbour].second > distance_through_me){
            //     distances[neighbour].second = distance_through_me;
            //     pending.push(distances[neighbour]); //even if its a copy , we will get the min distance at top
            // }
            if(!visited[neighbour]){
                int edge_length = neighbours->wt ;
                int my_distance = edge_length + distances[my_vertex].second;
                if(distances[neighbour].second > my_distance){
                    distances[neighbour].second = my_distance;
                    pending.push(distances[neighbour]);
                }
            }
            neighbours = neighbours->next;
        } 

    }

    for(int i{0} ; i<V ; i++){
        cout<<i<<" "<<distances[i].second<<endl;
    }


}


int main()
{
    int V{0}, E{0};
    // cout <<"Ente the number of vertices and edges for your weighted graph : ";
    cin >> V >> E;

    //adjacency list
    node** head = new node*[V]; //adjacency list
    node** tail = new node*[V];
    for(int i = 0 ; i < V ; i ++)
    {
        head[i]  = NULL;
        tail[i] = NULL;
    }
    
    //input
    // cout<<"Enter all the "<<E<<" edges followed by their weight "<<endl;
    for(int i {0} ; i < E ; i++ ){

    int x=0 ,  y=0 ,  wt= 0;
    
    cin>>x>>y>>wt;
    
    add_node(head , tail ,  x , y , wt);
    
    }

    Djaktras(head,tail, V , E);
    // for(int i{0} ; i < V ; i++){
    //     cout<<i<<"---";
    //     node*my_head = head[i];
    //     while(my_head!=NULL){
    //         cout<<i<<" "<<my_head->vertex<<" "<<my_head->wt<<endl;
    //         my_head=my_head->next;
    //     }
    //     cout<<endl;
    // }
    //

    for(int i = 0 ; i < V ; i++){
        delete head[i];
    }
    delete[] head;
    delete[] tail ;
    return 0;
}
