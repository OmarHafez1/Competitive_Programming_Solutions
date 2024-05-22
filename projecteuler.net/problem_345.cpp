#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull
#define MOD 1000000007

int a[16][16];
int n;  

int dp[16][1<<15];

int calc(int r, int mask) {
    int ret = 0;
    if(~dp[r][mask]) return dp[r][mask];
    for(int c = 0; c < n; c++) {
        if(mask&(1 << c)) continue;
        mask |= (1 << c);
        ret = max(ret, calc(r+1, mask)+a[r][c]);
        mask ^= (1 << c);
    }
    return dp[r][mask] = ret;
}

signed main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }  
    memset(dp, -1, sizeof(dp));
    cout << calc(0, 0);

}



