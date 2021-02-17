/*

Coin Tower
Send Feedback
Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?
Input Format :
Contains three value N,X,Y as mentioned in the problem statement
Output Format :
A string containing the name of the winner like “Whis” or “Beerus” (without quotes)
Constraints:
1<=N<=10^6
2<=X<=Y<=50
Sample Input :
 4 2 3
Sample Output :
 Whis

*/

#include<iostream>
#include <climits>
using namespace std;

int min_steps (int n , int x , int y){

//base case
    if(n==0){
        return 0;
    }

    //i ll do everyhing in mmy power to not let the next move be the finishing move

    int c1 = INT_MAX , c2 = INT_MAX , c3 = INT_MAX;

    //min steps to chalne hi padhenge
    c1 = min_steps(n-1 , x , y);

    //we cant let the other one win
    if(x <= n && n-x != x && n-x!=y && n-x != 1){//if this happens i ll lose

    c2 = min_steps(n-x , x ,y );
    }

    if(y <= n && n-y != x && n-y!=y && n-y != 1){//if this happens i ll lose

    c2 = min_steps(n-y , x ,y );

    }

    //is

    int ans = min(c1,min(c2,c3))+1;
    return ans;

}


//memoization
int min_steps (int n , int x , int y , int*arr){

//base case
    if(n==0){
        return 0;
    }

    //check
    if(arr[n] != -1){
        return arr[n];
    }
    //i ll do everyhing in mmy power to not let the next move be the finishing move

    int c1 = INT_MAX , c2 = INT_MAX , c3 = INT_MAX;

    //min steps to chalne hi padhenge
    c1 = min_steps(n-1 , x , y,arr);

    //we cant let the other one win
    if(x <= n && n-x != x && n-x!=y && n-x != 1){//if this happens i ll lose

    c2 = min_steps(n-x , x ,y,arr );
    }

    if(y <= n && n-y != x && n-y!=y && n-y != 1){//if this happens i ll lose

    c3 = min_steps(n-y , x ,y,arr );

    }

    //is

    int ans = min(c1,min(c2,c3))+1;
    arr[n] = ans;
    return arr[n];

}

//dp


//dp solution

int coin_tower_step_dp(int n , int x , int y){

    int*arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1; 
    arr[x] = 1;
    arr[y] = 1; //min 1 step lagega att all these pts playing smartly

    for(int i = 1; i <= n ; i++){

        if(i == 1 || i == x || i == y){
            arr[i] = 1;
            continue;
        } 

        int c1 = arr[i-1];
        int c2 = INT_MAX;
        int c3 = INT_MAX;
        //we cant go down a path where the other person wins
        if(x<=i && i-x  != 1 && i-x != x && i-x!=y ){
            c2 = arr[i-x];
        }

        if(y<=i && i-y!= 1 && i-y != x && i-y!=y ){
            c3 = arr[i-y];
        }        

        arr[i] = min(c1,min(c2,c3)) + 1;
    }
    int ans = arr[n];
    delete [] arr;

    return ans;
}


/*
CN LOGIC
our arr[i] shows the probability of success of a player who got the first chance with i coins in the stack
so what we know is that if there ar 1 , X or Y coins my probabilty of sucess is 100% hence as at all thes e would be 1
, now if we are at arr[i] we need to check the ans at arr[i-1] , which shoes whether person playng firstbhand at arr[i-1]
looses or wins , similiarly for arr[i-x] and arr[i-y] , we should the path where the next player looses , or indiirectly we win
 if  any of the 3 , is false , that ean the next player whos removing coins from that stack looses and we win 
 if all the thhree are true , mean the person whos playing after uss , will win no mater wwhat 
 hame aisa chalna hai ki hamara next banda hare , to ham wahi path lege jaha next bnda har rha hoga 
 if any of the paths is false , it means going down that path will lead us to vectory , and such path exist 
 soo arr[ i] becomes true 
*/
bool coin_tower_step_dp_CN(int n , int x , int y){

    bool*arr = new bool[n+1];
    arr[0] = 0;
    arr[1] = 1; 
    arr[x] = 1;
    arr[y] = 1; //min 1 step lagega att all these pts playing smartly

    for(int i = 1; i <= n ; i++){

        if(i == 1 || i == x || i == y){
            arr[i] = true;
            continue;
        } 

        bool c1 = arr[i-1];
        bool c2 = 1;
        bool c3 = 1;
        //we cant go down a path where the other person wins
        if(x<=i  ){
            c2 = arr[i-x];
        }

        if(y<=i ){
            c3 = arr[i-y];
        }        

        arr[i] = !(c1&&c2&&c3);
    }
    
    bool ans = arr[n];
    delete [] arr;

    return ans;
    

}

int main(){

    //cout<<"Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . In one move player can remove 1 or X or Y coins from the tower .";
    cout<<"Lets see who wins ! "<<endl;
    int n=0 ;
    cout <<"Enter the number of coins - ";
    cin>>n;
    cout<<"Enter how many additionals coins can be removed vesides the default 1 coint removal (2 values X,Y) ";
    int x = 0, y = 0 ;
    cin>>x>>y;

    int ans =coin_tower_step_dp(n , x , y);

    if(ans%2 == 0){
        cout<<"Whiz";
    }else{
        cout<<"Beerus";
    }
    cout<<" will win the game ! "<<endl;
}