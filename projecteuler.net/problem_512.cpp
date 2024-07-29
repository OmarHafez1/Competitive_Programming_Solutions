#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ull unsigned long long
#define ll long long

vector<int> phi_from_1_to_n(int n) {
    vector<int>phi(n + 1, 1), sieve(n + 1, -1);
    for(int i = 2; i <= n; i++) {
        if(sieve[i] == -1) {
            sieve[i] = i;
            for(long long j = 1ll * i * i; j <= n; j += i)
                sieve[j] = i;
        }
    }
    for(int i = 2; i <= n; i++) {
        int p = sieve[i], j = i;
        while(j % p == 0) {
            phi[i] *= p;
            j /= p;
        }
        phi[i] = (phi[i] / p) * (p - 1) * phi[j];
    }
    return phi;
}

signed main() {
    int N = 5e8;
    auto phi = phi_from_1_to_n(N);
    ull ans = 0;
    for(int n = 1; n <= N; n+=2) {
        ans += phi[n];
    }
    cout << ans;
}   

