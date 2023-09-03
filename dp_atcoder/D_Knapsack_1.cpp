#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n, w;
    cin >> n >> w;
    vector<int> v(n), b(n);
    int dp[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i <n; i++)
    {
        cin >> v[i] >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + b[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w];
}