#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string s = "100001000101100101010001011000010100000000010100100001001010000000000000000000000000";
vector<int> a(85, 2);

ll dp[85][3];
ll solve(int i, int val) {
    if(i == s.size()) return val == 0;
    if(dp[i][val] != -1) return dp[i][val];
    if(a[i]+val == 3) {
        return dp[i][val] = solve(i+1, 2);
    }
    if(a[i]+val > 0) {
        return dp[i][val] = solve(i+1, 2) + solve(i+1, 0);
    }
    return dp[i][val] = solve(i+1, 0);
}

signed main() { 
    for(int i = 0; i < s.size(); i++) {
        a[i] = s[i]-'0';
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;
}
    