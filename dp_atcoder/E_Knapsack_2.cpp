#include <bits/stdc++.h>
#define int long long
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
using namespace std;
int prime[1000001];
int fact[1000001];
const int mod = 1e9 + 7;
const int INF = 1LL << 60;
int32_t main()
{
    int n, w;
    cin >> n >> w;
    vector<int> v(n), b(n);
    int N = 1e5 + 5;
    vector<vector<int>> dp(N, vector<int>(n + 1,INF ));
    for (int i = 0; i < n; i++){
        cin >> v[i] >> b[i];
    }

    dp[0][0] = 0;
    for (int i = 0; i < N; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            if (b[j - 1] <= i){
                dp[i][j] = min(dp[i][j], dp[i-b[j-1]][j-1]+v[j-1]);
            }
        }
    }
    int ans = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        if (dp[i][n] <= w)
        {
            ans = i;
            break;
        }
    }
    cout << ans;
}