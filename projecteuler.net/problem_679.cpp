#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

int dp[20][11][1024][1024];

int solve(int ind, int f, int s, int n) {
    if(ind == 20) {
        return n == 0;
    }
    int &tmp = dp[ind][n][f][s];
    if(~tmp) return tmp;
    int res = 0;
    for(int d = ind == 0; d < 10; d++) {
        if((f & (1 << d)) && (s & (1 << d))) continue;
        if(f & (1 << d)) {
            res += solve(ind+1, f, s | (1 << d), (n*10+d)%11);
        } else {
            res += solve(ind+1, f | (1 << d), s, (n*10+d)%11);
        }
    }
    return tmp = res;
}

signed main() {
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0, 0);    
}   

