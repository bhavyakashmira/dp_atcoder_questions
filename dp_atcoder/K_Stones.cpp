#include <bits/stdc++.h>
#define int long long
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
using namespace std;



int32_t main()
{
    int n,k;
    cin >> n>>k;
    vector<int> v(n);
    for (int i = 0; i<n;i++)
        cin >> v[i];

    vector<bool> dp(k + 1);
    for (int i = 0; i <= k;i++){
        for (int j = 0; j <n;j++){
            if(i>=v[j] && !dp[i-v[j]]){
                dp[i] = true;
            }
        }
    }

    if(dp[k])
        cout << "First";
    else
        cout << "Second";
}