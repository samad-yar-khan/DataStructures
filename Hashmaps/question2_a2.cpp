#include <iostream>
using namespace std;

#include<unordered_map> 
#include <vector>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    
    //our map hold two values for each key
    //1 ) int - its first index in arr
    //2 ) bool - T - noot yet used in a seq
    //           F- already used ina seq and wont be useed to form seperate seq


    unordered_map<int , pair<int , bool>> map;

    for(int i{0} ; i < n  ; i++){
        //insert all keys once
        if(map.count(arr[i])<1){
    	map[arr[i]].first=i; // index
    	map[arr[i]].second=true;
        }
	}


    
    /*start will have thhe index of the starting inddex of seq of max length 
    this index is corresponding to our array
    index storage became necessary because in case of two sequences oof same 
    same size we need to output the one which comes earlier in the arr or whoes index is
    smallr*/
    int start = 0;
    int maxlen = 0;
    
    for(int i = 0 ; i < n ; i++){
        //only check for seq if its not part of a a seq aready i.e. boolF
        if(map[arr[i]].second){
            map[arr[i]].second = false;
            int s{map[arr[i]].first};
            int len = 1;
            int prev = arr[i]-1;

            //check  for numbers smaller tha it to fit the seq an set the min nums index as s
            //increase len with iteration
            while(map.count(prev) > 0){
                s=map[prev].first;
                len++;
				map[prev].second=false;
                prev--;
            }
            //check larger consecutive nos
            int next = arr[i]+1;
            while(map.count(next)){
                len++;
                map[next].second=false;
                next++;
            }

            //cases to consider a change in ans
            if(len == maxlen && s<start){
                maxlen = len;
                start=s; 
            }

            if(len > maxlen){
                maxlen = len;
                start=s;
            }
        }
    }
    
    vector <int> ans ;
    
    for(int i =0 ; i < maxlen ; i++){
        ans.push_back(arr[start] + i);
    }
    
    return ans;
}

int main(){
    
    int arr[13]{2 ,12, 9 ,16 ,10 ,5 ,3 ,20 ,25 ,11 ,1 ,8 ,6};
    vector<int> ans = longestConsecutiveIncreasingSequence(arr,13);

    for(auto s:ans){
        cout<<s<<" ";
    }
}