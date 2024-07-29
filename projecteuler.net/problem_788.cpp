#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define MOD 1000000007

int N;

int dp[2026][2][2026];

int solve(int ind, int d, int cnt) {
    if(ind == N) {
        return (cnt > N/2);
    }
    int &tmp = dp[ind][d][cnt];
    if(~tmp) return tmp;
    int res = 0;
    for(int i = (ind == 0); i < 10; i++) {
        res += solve(ind+1, d, cnt+(d == i));
        res %= MOD;
    }
    return tmp = res%MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    for(N = 1; N <= n; N++) {
        for(int j = 0; j <= N; j++) 
            for(int k = 0; k <= N; k++)
                dp[j][0][k] = dp[j][1][k] = -1;
        ans += (solve(0, 0, 0)+(solve(0, 1, 0)%MOD)*9)%MOD;
        ans %= MOD;
    }
    cout << ans;
    
}   