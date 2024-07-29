#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ull unsigned long long
#define ll long long

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

ll mod_exp(ll base, ll exponent, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to calculate (A / B) % P
ll mod_div(ll A, ll B, ll P) {
    return (A * mod_exp(B, P - 2, P)) % P;
}

int calc(int p) {
    int fact = p-1;
    int res = p-1;
    for(int k = 2; k <= 5; k++) {
        fact = mod_div(fact, p-k+1, p);
        res += fact;
        res %= p;
    }
    return res;
}

signed main() {
    int N;
    cin >> N;
    auto isP = primes_sieve(N);
    ull ans = 0;
    for(int i = 5; i <= N; i+=2) {
        if(isP[i]) {
            ans += calc(i);
        }
    }
    cout << ans;
}   

