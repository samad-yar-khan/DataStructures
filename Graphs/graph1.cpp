
#include<iostream>
using namespace std;

void print(int** edges , int n , int starting_vertex , bool * visited);

int main(){

    int n = 0  , e = 0 ;
    

    cout<<"Enter number of vetices of the graph - ";
    cin>>n;
    cout<<"Enter number of edges of the graph -  ";
    cin>>e;

    //now we need a 2d array , whivh keeps a chck of ours edges ,
    //assume that my edges are numbereed from [0 to n-1]

    //adjaceny matryix

    int ** edges = new int*[n];

    for(int i = 0 ; i < n ; i++){
        
        edges[i]=new int[n];
        //initilaise the array
        for(int j = 0 ; j < n ; j++ ){
            edges[i][j] = 0; // 0 signifies there is no edges bw i,j and 1 signifies that edge exisst
        } 
    }

    //we need to fill the ajaceny array
    cout<<"Enter the edges - "<<endl;
    for(int i = 0 ; i < e  ; i++){
        int x = 0 , y= 0 ;
        cin>>x>>y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    //printing the edges 
    //sv s the starting vertex
    int sv =  0; //starting value
    bool*visited = new bool [n];
    
    //visited will store iif a vertex has already been visited or not
    //this helps avoid infinite recusrive calls and duplicate printing in the print func
    //initiallise the visited matriix
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }

    print( edges , n , sv , visited );


    //freeing memory
    for(int i = 0 ; i < n ; i++){
      delete [] edges [i]; 
    }
    delete [] visited;
    delete [] edges;
}

//now this is a dfs or depth first appoach , as once we go down a vertex / edge , we wont come back till all 
//vertices are printed to tthe depth 

void print(int** edges , int n , int sv , bool*visited){

    cout<<sv<<" ";
    visited[sv] = true; //signifies that sv has been vvisted
 
    for(int j = 0 ; j < n ; j++){
        
        if(visited[j] == true  || j == sv){
            continue;
        }

        if(edges[sv][j] == 1){
            print(edges , n , j , visited );
        }
    }

    return ;
}

