#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define endl '\n'
#define newl cout<<endl

#define EPS .0000001
#define MOD 10000000000000000LL

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

signed main() {
    vector<int> primes = {2};
    auto isP = primes_sieve(1600000);
    int sum = 2;
    for(int i = 3; i < 5000; i+=2) {
        if(isP[i]) primes.push_back(i), sum += i;
    }
    int dp[sum+10] = {0};
    for(int i = 2; i <= sum; i++) {
        if(isP[i]) dp[i] = 1;
    }
    for(auto &p : primes) {
        for(int j = sum; j >= p; j--) {
            dp[j] = dp[j];
            dp[j] += dp[j-p];
            dp[j] %= MOD;
        }
    }
    cout << dp[sum];
}
