/*
Shortest Subsequence
Send Feedback
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3
*/


#include<iostream>
#include<string>
#include<climits>

using namespace std;

//logic - we only work on the first character 
/*
we have two routes 
-> eitehr my first char is a part of the subseq thats not in v or it is not included in the subsequence tahts not in v
-> so basically ether my first chacter is the part od the smallest subseq not presnt in V
   *we try to find this is v and and check for the charcter ahead , if its not presnt in the string v
   then stren of shrtest subseq not prest in v wull be one and weweont do anothing,
   if our first char is presnst in the string V, then we  check for the ans is the substring following our char
 if we assume our char is not in the subseq we ,  cas re on  a smaller S and V will remain saeme
*/



int ans (string S , string V){

    if(S.length() == 0 ){ //mera include karte karte khatamm hi hogya string , isse koi diff string nhi mila , hence intmax
        return INT_MAX;
    }
    // if(V.length()==0){
    //     return 0;
    // }

    int case1 = ans(S.substr(1) , V); //not including my first char 
    
    int case2 = INT_MAX;
    int i=0;
    while(i<V.length() && S[0] != V[i] ){
        i++;
    }
    
    if(i==V.length()){
        return 1; // pehela char hai hi nhi
    }

    case2  = ans(S.substr(1) , V.substr(i+1) );
    if(case2!=INT_MAX ){
        case2++;
    }

    int my_ans = min(case1 , case2);
    
    return my_ans;
}

//memoization
int ans2 (string S , string V , int**output){

    //index of our ans
    int m = S.length();
    int n = V.length();

    //base case
    if(S.length() == 0 ){
        return INT_MAX;
    }
    
    //check
    if(output[m][n]!=-1){
        return output[m][n];
    }

    int case1 = ans2(S.substr(1) , V , output);
    int case2 = INT_MAX;
    int i=0;

    while(i<V.length() && S[0] != V[i] ){
        i++;
    }

    int answer=INT_MAX;


    if(i==V.length()){ //if my eleemnecant be found in array it means the ans should be 1
        answer=1; // pehela char hai hi nhi hai
    }
    else{
        
        case2  = ans2(S.substr(1) , V.substr(i+1) , output);
        if(case2!=INT_MAX ){
            case2++;
        }
        answer = min(case1 , case2);
    }

    output[m][n] = answer;
    return output[m][n];

}
//output[m][n]will store shortest subsequnvce fro string of ength m and n form the end
int shortest_uncommon_subsequqence(string S , string V){

    int row = S.length()+1;
    int col = V.length()+1;
    int **output = new int*[row];
    for(int i = 0 ; i < row ;  i++){
        output[i] = new int[col];
    }

    for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j <col ; j++){
            output[i][j]=-1;
        }
    }

    int fans = ans2(S,V,output); 

    for(int i = 0 ; i < row ;  i++){
        delete [] output[i];
    }
    delete [] output;
    return fans;

}

//dp
int shortest_uncommon_subseq_DP(string S  , string V){
    int m = S.length() +1 ;
    int n = V.length() +1;
    int **output = new int* [m];
    for(int i = 0 ; i < m ; i++){   
           output [i]= new int[n];
    }

    for(int i= 1 ; i <m ; i++){ //i represents length of string s
        output[i][0]=1; //v is empty string
    }

    for(int j = 0 ; j < n ; j++){
        output[0][j] = INT_MAX; // no sttring in S which snt equala to s
    }

    for(int i = 1 ; i < m ; i++){
        for(int j = 1 ; j < n ; j++ ){
            int indexS = (m - 1) - i; //m-1 and n-1 are str length
            int indexV = (n - 1 ) - j;

            int case1 = INT_MAX , case2 = INT_MAX;  //case one is when my char isnt in the strig , case2 is when my char is in the smallesr non common subs

            case1 = output[i-1][j];//didnt include my char

            int l=indexV;
            while ( l < V.length() && V[l] != S[indexS]){
                l++;
            }
            
            if(l == V.length()){
                case2 = 1;
            }else{
                case2 = output[i-1][n-2 - l];
                if(case2!=INT_MAX){
                    case2++;
                }
            }
            output[i][j] = min(case1 , case2);
        }
    }

    int ans = output[m-1][n-1];

    for(int i = 0 ; i < m ; i++){
        delete [] output [i]; 
    }
    delete [] output;
    return ans;    
}

int main( ){
    cout<<"Enter strings - ";

    string S , V;
    
    cin>>S>>V;
    
    int final_ans = shortest_uncommon_subseq_DP(S,V);
    
    cout<<final_ans;

    return 0;
}


