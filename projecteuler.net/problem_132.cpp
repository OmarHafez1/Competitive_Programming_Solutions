#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

ull mod_exp(ull base, ull exponent, ull mod) {
    ull result = 1;
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
ull mod_div(ull A, ull B, ull P) {
    return (A * mod_exp(B, P - 2, P)) % P;
}

ull exponential_mod(ull n, ull p, ull m) {
    if(p == 0) return 1;
    if(p&1) return (exponential_mod(n, p-1, m)*n)%m;
    ull tmp = exponential_mod(n, p/2, m)%m;
    return (tmp*tmp)%m;
}

bool isPrime(ull n) {
    if(n <= 1) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;
    if((n - 1) % 6 != 0 && (n + 1) % 6 != 0) return 0;
    for(ull i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

signed main() {
    // (10**(10**9)-1)/9
    // (10**2-1)/9
    ull ans = 0; 
    for(ull m = 5, cnt = 0; cnt < 40; m+=2) {
        if(!isPrime(m)) continue;
        if((mod_div(exponential_mod(10, 1e9, m)-1, 9, m)+m)%m == 0) {
            ans += m;
            cnt++;
        }
    }
    cout << ans;
}   

