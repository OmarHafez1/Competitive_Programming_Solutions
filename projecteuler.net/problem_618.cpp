#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

#define MOD 1000000000

vector<int> primes;

vector<bool> primes_sieve(int n) {
    vector<bool> isP(n+1, 1);
    isP[0] = isP[1] = 0;
    for(int i = 4; i <= n; i+=2) isP[i] = 0;
    for(int i = 3; i <= n; i+=2) {
        if(!isP[i]) continue;
        for(int j = i*2; j <= n; j+=i) {
            isP[j] = 0;
        }
    }
    return isP;
}

int dp[5200][47000];

ull solve(int ind, int n) {
    if(n == 0) {
        return 1;
    }
    if(primes[ind] > n || ind == primes.size()) {
        return 0;
    }
    if(~dp[ind][n]) return dp[ind][n];
    return dp[ind][n] = ((solve(ind, n-primes[ind])*primes[ind])%MOD + solve(ind+1, n))%MOD;
}

signed main() {
    auto isPrime = primes_sieve(50000);
    primes.push_back(2);
    for(int i = 3; i <= 50000; i+=2) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
    memset(dp, -1, sizeof(dp));
    int a = 0, b = 1, c;
    int ans = 0;
    for(int i = 2; i <= 24; i++) {
        c = a+b;
        a = b;
        b = c;
        ans += solve(0, c);
        ans %= MOD;
    }
    cout << ans;
}   

