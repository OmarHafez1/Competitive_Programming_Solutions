#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

bool isPrime(int n) {
    if(n <= 1) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;
    if((n - 1) % 6 != 0 && (n + 1) % 6 != 0) return 0;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int dp[20][20*9];

int go(int k, int sum) {
    if(k == 0) return isPrime(sum);
    int &tmp = dp[k][sum];
    if(~tmp) return tmp;
    int res = 0;
    for(int i = 0; i < 10; i++) {
        res += go(k-1, sum+i);
    }
    return tmp = res;
}

int solve(int k, int n, int sum, int res) {
    if(k == 0) return res;
    int tmp = 0;
    for(int d = 0; d < 10; d++) {
        tmp = go(k-1, sum+d);
        if(tmp <= n) 
            n -= tmp;
        else
            return solve(k-1, n, sum+d, res*10+d);
    }
    return 0;
}

signed main() {
    memset(dp, -1, sizeof(dp));
    int n = 1e16;
    cout << solve(20, n-1, 0, 0);
}   