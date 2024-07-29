#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define int ull

#define LIMIT 9*9*19
#define MOD 1000000000

int dp[21][LIMIT], cnt[21][LIMIT];

signed main() {
    for(int i = 0; i <= 9; i++) {
        dp[1][i*i] = i;
        cnt[1][i*i] = 1;
    }
    for(int i = 2; i <= 20; i++) {
        for(int sum = 1; sum < LIMIT; sum++) {
            for(int d = 0; d <= 9 && sum + d*d < LIMIT; d++) {
                cnt[i][sum+d*d] += cnt[i-1][sum];
                dp[i][sum+d*d] += dp[i-1][sum]*10+d*cnt[i-1][sum];
                dp[i][sum+d*d] %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j*j < LIMIT; j++) {
            ans += dp[i][j*j];
            ans %= MOD;
        }
    }
    cout << ans;
}   
