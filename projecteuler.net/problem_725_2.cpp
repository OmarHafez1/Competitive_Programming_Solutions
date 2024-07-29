#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double

#define MOD (ull)1e16

signed main() {
    int N;
    cin >> N;
    ull dp[N+1][10+1][18+1];
    ull cnt[N+1][10+1][18+1];
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    dp[0][0][0] = 0;
    cnt[0][0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int mx = 0; mx <= 9; mx++) {
            for(int d = 0; d <= 9; d++) {
                for(int s = 0; s+d <= 18; s++) {
                    dp[i][max(mx, d)][s+d] += dp[i-1][mx][s]*10+cnt[i-1][mx][s]*d;
                    dp[i][max(mx, d)][s+d] %= MOD;
                    cnt[i][max(mx, d)][s+d] += cnt[i-1][mx][s];
                    cnt[i][max(mx, d)][s+d] %= MOD;
                }
            }
        }
    }
    ull ans = 0;
    for(int i = 1; i <= 9; i++) {
        ans += dp[N][i][2*i];
        ans %= MOD;
    }
    cout << ans;
}   