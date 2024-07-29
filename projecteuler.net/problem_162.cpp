#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

int dp[18][2][2][2];

int solve(int len, bool a, bool one, bool zero) {
    if(len == 0) return (a&&one&&zero);
    int &tmp = dp[len][a][one][zero];
    if(~tmp) return tmp;
    int res = 0;
    for(int d = 0; d < 16; d++) {
        res += solve(len-1, a | (d == 10), one | (d == 1), zero | (d == 0));
    }
    return tmp = res;
}

signed main() {
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 3; i <= 16; i++) {
        for(int d = 1; d < 16; d++) {
            ans += solve(i-1, d == 10, d == 1, 0);
        }
    }
    stringstream ss;
    ss << hex << ans;
    string res(ss.str());
    for(auto &ch : res) {
        if(ch >= 'a') {
            ch = (char)(ch-'a'+'A');
        }
    }
    cout << res;
}   

