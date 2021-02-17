#include <iostream>
using namespace std;
#include <climits>

//bruteforce

int getMaxMoney_rec(int *arr , int n){
    
    //base
    if(n<=0){
        return 0;
    }

    int case1 = arr[0] + getMaxMoney_rec( arr+2 ,n-2);
    int case2 = getMaxMoney_rec(arr+1 , n-1);

    return max(case1,case2);

}

//memoization

int getMaxMoney_memo(int *arr , int n , int *ans){
    
    
    //base case
    if(n <= 0){
        return 0;
    }
    
    //check 
    if(ans[n] != -1){
        return ans[n];
    }
    
    //ih ans save
	int case1 = INT_MIN;
    int case2 = INT_MIN;
    
	case1 = arr[0] + getMaxMoney_memo(arr+2 , n-2 , ans);
    case2 = getMaxMoney_memo(arr+1 , n-1 , ans);
    
    //savs
    ans[n] = max(case1 , case2 );
    return ans[n];

}

int getMaxMoney_memo(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
	int *ans = new int [n+1];
    
    for(int i {0} ; i < n+1 ; i++){
        ans[i] = -1;
    }
    
    
    int temp  = getMaxMoney_memo(arr, n , ans);
    delete [] ans;
    return temp;
}
//dp
//TC = O(n)
//SC = O(N)
int getMaxMoney_DP(int arr[], int n){

    int *ans = new int[n+1];
    
    ans[0] = 0 ; //for zero array
    ans[1] = arr[n-1]; //for size 1 array we can only have last element;
    
    
    for(int i = 2 ; i <= n ; i++){
        
        int index = n-i;
        int case1 = ans[i-1]; //didnt loot my house and loote dthe next houese
        int case2 = ans[i-2] + arr[index]; //looted my houese an the alternate houese
        
        ans[i] = max(case1 , case2);
        
    }
        
    int temp = ans[n];
    delete [] ans;
    return temp;
    
    
}

//we see that at one point we are just using three elmenets 
//case if i loot next house
//case if i loot current houes and alterates
//max oof thd two / final answer

//so we get a  dp soln with space complexity = O(1)
//tc = O(n)

int getMaxMoney_DP2(int arr[], int n){

    //at a time we are dealng with just 3 elments so we do that
    
    int loot_alternate = 0 ; //loot my house
    int loot_next = arr[n-1]; //loot next house
    int max_loot = 0;
    
    for(int i = 2 ; i <= n ; i++){
        
        int index = n-i;
        int loot_this = arr[index]+loot_alternate;
        
        max_loot = max(loot_this , loot_next);
        
        if(i < n){
            loot_alternate = loot_next;
            loot_next = max_loot;
        }
        
    }
    return max_loot;
}


int main(){

    cout <<"Number of houses you can loot : ";
    int n{0};
    cin>>n;
    int *arr = new int[n];

    cout<<"Enter money in each house - ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    cout<<"Max amount you can loot without looting consecutive houses - ";
    int ans =  getMaxMoney_DP2(arr , n);
    cout<<ans<<endl;

    delete [] arr;


}