#include <bits/stdc++.h>
#define int long long
#define fr(i, j, n) for (int i = j; i < n; i++)
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
using namespace std;
int prime[1000001];

void solve();

int32_t main()
{
    int t;
    while (t--)
    {
        solve();
    }
}
void solve(){
    int n,k;
    cin >> n>>k;
    vector<int> v(n), dp(n, INT_MAX);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp[0] = 0,dp[1]=abs(v[1]-v[0]);
    for (int i = 2; i < n;i++){
        for (int j = 1; j <=k;j++){
            if(i>=j){
            dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i -j]));
            }
        }
    }
    cout << dp[n - 1] << endl;
}