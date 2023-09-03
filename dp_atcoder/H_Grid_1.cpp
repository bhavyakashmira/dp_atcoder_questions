#include <bits/stdc++.h>
#define int long long
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
using namespace std;
char grid[1005][1005];
int dp[1002][1002];
int mod = 1e9 + 7;

int32_t main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <n;i++){
        for (int j = 0; j <m;j++){
            cin >> grid[i][j];}
    }

    dp[0][0] = 1;
    for (int i = 0; i <n; i++){
        for (int j = 0; j<m;j++){
        if(grid[i][j]=='#'){
            dp[i][j] = 0;
            continue;
        } 
        if(i>0)
            dp[i][j] += dp[i - 1][j];
        dp[i][j] %= mod;
        if(j>0)
            dp[i][j] += dp[i][j - 1];
        dp[i][j] %= mod;
    }
    }
    cout << dp[n-1][m-1] << endl;

}