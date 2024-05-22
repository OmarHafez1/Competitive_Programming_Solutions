#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define int ll
#define MOD 1000000007

int N, ans = 0, n = 10;

int dp[10][41][1 << 10];

int solve(int d, int ind, int bitmask) {
    if(ind == n) return (bitmask == (1 << 10) - 1);
    if(d < 0 || d > 9) return 0;
    int& tmp = dp[d][n-ind][bitmask];
    if(~tmp) return tmp;
    return tmp = solve(d-1, ind+1, bitmask | 1 << d) + solve(d+1, ind+1, bitmask | 1 << d);
}

signed main() {
    cin >> N;
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    while(n <= N) {
        for(int d = 1; d < 10; d++) {
            ans += solve(d, 0, 0);
        }
        n++;
    }
    cout << ans/2;
}



