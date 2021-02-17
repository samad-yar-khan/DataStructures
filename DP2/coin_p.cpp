#include<bits/stdc++.h>

using namespace std;


void solve(){
    int n; cin>>n;
    vector<long long> v(n);
    for(auto& i: v) cin>>i;
    int x; cin>>x;
    vector<vector<int>> dp(n+1 , vector<int> (x+1,0));
    dp[0][0] = 1;

    for(int i=1; i<=n; ++i){
        dp[i][0] = 1;
        for(int j=1; j<=x; ++j){
            dp[i][j] = dp[i-1][j];
            if(j-v[i-1]>=0)
                dp[i][j] += dp[i][j-v[i-1]];
        }
    }  
    cout<<dp[n][x];
}


int main(){

}