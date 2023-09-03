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
    int t=1;
    while (t--)
    {
        solve();
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> v(n),dp(n, INT_MAX);
    for (int i = 0; i < n;i++)
        cin >> v[i];
    dp[0] = 0, dp[1] = abs(v[0] - v[1]);
    for (int i = 2; i < n;i++){
        dp[i] = min(dp[i - 1] + abs(v[i - 1] - v[i]), dp[i - 2] + abs(v[i] - v[i - 2]));
    }

        cout << dp[n-1] << endl;
}