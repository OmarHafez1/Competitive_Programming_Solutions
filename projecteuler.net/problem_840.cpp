#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

#define MOD 999676999
#define N 50000


signed main() {
    int D[N+10];
    int dp[N+5];
    for(int i = 0; i <= N; i++) {
        D[i] = 1;
    }
    for(int i = 2; i <= N; i++) {
        for(int j = 2; i*j <= N; j++) {
            D[i*j] = (D[i]*j+D[j]*i)%MOD;
        }
    }
    memset(dp, 0, sizeof(dp));
    for(int j = 0; j <= N; j++) {
        dp[0] = 1;
    }
    for(int d = 1; d <= N; d++) {
        for(int n = d; n <= N; n++) {
            dp[n] += dp[n-d]*D[d]%MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans;
}   