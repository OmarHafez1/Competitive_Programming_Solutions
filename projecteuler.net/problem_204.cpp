#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

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

vector<int> primes = {2};

int solve(int ind, ull n) {
    if(n > 1e9) return 0;
    if(ind == primes.size()) return 1;
    return solve(ind+1, n) + solve(ind, n*primes[ind]);
}

signed main() {
    for(int i = 3; i < 100; i+=2) {
        if(isPrime(i)) primes.push_back(i);
    }
    cout << solve(0, 1);
}   

