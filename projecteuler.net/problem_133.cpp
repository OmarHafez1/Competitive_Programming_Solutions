#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define int ull


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

int exponential_mod(int n, int p, int m) {
    if(p == 0) return 1;
    if(p&1) return (exponential_mod(n, p-1, m)*n)%m;
    int tmp = exponential_mod(n, p/2, m)%m;
    return (tmp*tmp)%m;
}

int modExponentiation(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd, multiply base with the result
            result = (result * base) % mod;
        }
        exp = exp >> 1; // exp = exp // 2
        base = (base * base) % mod; // Change base to base^2 % mod
    }
    return result;
}

int calculateRepunitsMod(int x, int m) {
    int modValue = 9 * m;
    int exponent = pow(10, x);
    int powerMod = modExponentiation(10, exponent, modValue);
    int repunitMod = (powerMod - 1) / 9;
    return repunitMod % m;
}

int divs(int n) {
    for(int i = 0; i < 19; i++) {
        if(calculateRepunitsMod(i, n) == 0) return 1;
    }
    return 0;
}

signed main() {
    int ans = 2+3, N = 100000;
    for(int i = 5; i < N; i+=2) {
        if(!isPrime(i)) continue;
        if(!divs(i)) ans += i; 
    }
    cout << ans;
}   

