#include <vector>

using namespace std;

 
bool is_sorted(vector<int> arr){
    
    for (int i = 1 ; i < arr.size() ; i++) {
        if(arr[i-1] > arr[i]){
            return false;
        }
    }

    return true;

}
  

int lis (int * arr , int n , vector <int> sub){

    if(n==0){
        if(is_sorted(sub)){
            return sub.size();
        }else{
            return -1;
        }
    }    

    //ih
    int case1 = lis(arr+1  , n - 1 , sub);
    sub.push_back(arr[0]);
    int case2 = lis(arr+1 , n-1 , sub);

    //is
    return max(case1,case2);

}

int lis (int * arr , int n ){
    vector<int> sub;
    return lis(arr , n , sub);
}