#include <bits/stdc++.h>
#define int long long
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
using namespace std;
void solve();
int dp[3003][3003];

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }

    for (int i = n - 1; i >= 0;i--){
        for (int j = i; j < n;j++){
            if(i==j){
                dp[i][j] = v[i];
            }else{
                dp[i][j] = max(v[i]-dp[i+1][j], v[j]- dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n - 1];
}