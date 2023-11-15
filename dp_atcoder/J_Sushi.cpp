#include <bits/stdc++.h>
#define ll double
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
using namespace std;

ll dp[303][303][303];
ll solve(int o ,int t, int th, int& n){
    if(o<0 || t<0 || th<0 ) return 0;
    if(th==0 && t==0 && o==0) return 0;

    if(dp[o][t][th]>0)
        return dp[o][t][th];

    int rem = o + t + th;
    ll exp_val = n + o * solve(o - 1, t, th, n) + t * solve(o + 1, t - 1, th, n) + th * solve(o,t+1, th-1, n);

    return dp[o][t][th] = exp_val/rem;
}

int main()
{
    int n;
    cin >>n;
    int o=0, t=0, th=0;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if(x==1) o++;
        else if(x==2) t++;
        else th++;
    }
   memset(dp, -1, sizeof dp);
   cout << fixed << setprecision(9) << solve(o,t,th, n);
}
