#include <bits/stdc++.h>
#define int long long
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
using namespace std;
bool vis[100002];
int dp[100005];
vector<int> adj[100005];

void dfs(int v){
    vis[v] = 1;
    dp[v] = 0;
    for(auto it:adj[v]){
        if(!vis[it]){
            dfs(it);
        }
        dp[v] = max(dp[v],1+dp[it]);
    }

}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n;i++){
          if(!vis[i]){
            dfs(i);
          }
    }

    int ma = 0;
    for (int i = 1; i <=n;i++){
          ma = max(ma, dp[i]);
    }
    cout << ma << endl;
}