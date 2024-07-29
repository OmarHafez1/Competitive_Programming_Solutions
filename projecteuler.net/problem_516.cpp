#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

int MOD = 1LL << 32;
int N, ans = 0;

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

vector<int> pool, primes;

bool canMUL(int x, int y) {
    return (log(x)+log(y) <= log(N));
}

void S(int ind, int n) {
    if(n > N) return;
    if(ind == primes.size()) {
        for(auto &x : pool) {
            if(canMUL(x, n)) {
                ans += x*n;
                ans %= MOD;
            } else {
                return;
            }
        }
        return;
    }
    if(canMUL(n, primes[ind])) {
        S(ind+1, n*primes[ind]);
    }
    return S(ind+1, n);
}

signed main() {
    cin >> N;
    for(int n = 1; n <= N; n*=2) {
        for(int x = n; x <= N; x*=3) {
            for(int y = x; y <= N; y*=5) {
                if(y+1 > 5 && y+1 <= N && isPrime(y+1)) {
                    primes.push_back(y+1);
                }
                pool.push_back(y);
            }
        }
    }
    sort(pool.begin(), pool.end());
    S(0, 1);
    cout << ans;
}   

