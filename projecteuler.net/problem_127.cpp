#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

vector<bool> primes_sieve(ull n) {
    vector<bool> isP(n+1, 1);
    isP[0] = isP[1] = 0;
    for(ull i = 4; i <= n; i+=2) isP[i] = 0;
    for(ull i = 3; i <= n; i+=2) {
        if(!isP[i]) continue;
        for(ull j = i*2; j <= n; j+=i) {
            isP[j] = 0;
        }
    }
    return isP;
}

signed main() {
    int N;
    cin >> N;
    int limit = 2*N+10;
    auto isP = primes_sieve(limit);
    ull primes[(int)3e6];
    primes[0] = 2;
    int sz = 1;
    for(int i = 3; i < limit; i+=2) {
        if(isP[i]) {
            primes[sz++] = i;
        }
    }
    ll ans = N-1;
    for(ull n = 2; n <= N; n++) {
        ull t = n*n*2-1;
        for(int i = 0; i < sz && primes[i] <= 2*n; i++) {
            if(t%primes[i] == 0) {
                ans--;
                break;
            }
        }
    }
    cout << ans;
}   

