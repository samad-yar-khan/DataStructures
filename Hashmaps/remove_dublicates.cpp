#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector <int> remove_dublicates (int *arr , int size);

int main(){

    cout<<"number of elements of array ? ";
    int n;
    cin>>n;

    int*arr = new int [n];

    cout<<"Enter elmenets - ";
    for(int i{0} ; i < n ; i++){
        cin>>arr[i];
    }

 
    vector <int> ans = remove_dublicates(arr,n);

    cout<<"ARRAY WITH UNIQUE ELMENETS - \n";

    for(auto const &v:ans){
        cout<<v<<" ";
    }

    cout<<endl;


    return 0;
}


vector <int> remove_dublicates (int *arr , int size){

    //isme bacially elmenet dalenge index pe if it hasnt been added 
    //add karene vector mai and update key val too truen signifiying thats it been added
    unordered_map <int , bool> seen ;
    vector <int>  ans;

    for(int i{0} ; i < size  ; i++ ){

        if(seen.count(arr[i]) > 0 ){ //count telle number of time key is present in  the array
        
        continue;
        }    
        else{
            seen[arr[i]] = true;
            ans.push_back(arr[i]);
        }
    
    } 

    return ans;
    
}
