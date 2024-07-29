
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ll long long

#define MOD 1234567891

bool check(int n, int p, int m) {
    // n ^ (2 ^ p+offset) < m ^ 2^offset
    // 2 ^ p+offset * log2(n) < 2^offset * log2(m)
    // p+loglog(n) < loglog(m)
    return ((log2(log2(n)) + p) <= log2(log2(m)));
}

int a[10000+2];

bool solve(ll n, ll m) {
    if(m < 0) return 0;
    ll left = 2, right = n, mid;
    while(left <= right) {
        mid = (left+right)/2;
        ll tmp = m;
        for(int i = 2; i <= mid; i++) {
            // i ^ (2 ^ (X+OFFSET)) > (mid+1) ^ (2 ^ OFFSET) 
            // 2 ^ (X) * log2(i) > log2(mid+1)
            // X + log2(log2(i)) > log2(log2(mid+1));
            ll tmp2 = (log2(log2(mid+1)) - log2(log2(i))); 
            while(check(i, tmp2, mid+1)) {
                tmp2++;
            }
            tmp -= tmp2;
            a[i] = tmp2;
        }
        if(tmp == 0) {
            for(int i = mid+1; i <= n; i++) {
                a[i] = 0;
            }
            return 1;
        }
        if(tmp < 0) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    return 0;
}

ll exponential_mod(ll n, ll p, ll m) {
    if(p == 0) return 1;
    if(p&1) return (exponential_mod(n, p-1, m)*n)%m;
    ll tmp = exponential_mod(n, p/2, m)%m;
    return (tmp*tmp)%m;
}

int main() {
    ll n = 1e4, m = 1e16;
    ll offset = max(m/(n-1)-1, 0ll);
    solve(n, m-offset*(n-1));
    ll ans = 0;
    for(int i = 2; i <= n; i++) {
        ans += exponential_mod(i, exponential_mod(2, a[i]+offset, MOD - 1), MOD);
        ans %= MOD;
    }
    cout << ans;
}   