#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ull

int N;

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

int solve(int ind, __int128 n) {
    if(n > N) return 0;
    if(ind >= primes.size()) return 0;
    int res = 0;
    n *= primes[ind]*primes[ind]*primes[ind];
    while(n <= N) {
        res += N/n;
        for(int j = ind+1; j < primes.size(); j++) {
            int tmp = solve(j, n);
            if(tmp == 0) break;
            res += tmp;
        }
        n *= primes[ind];
    }
    return res;
}

signed main() {
    cin >> N;
    for(int i = 3; i <= 1e6; i+=2) {
        if(isPrime(i)) primes.push_back(i);
    }
    int ans = N;
    for(int i = 0; i < primes.size(); i++) {
        ans += solve(i, 1);
    }
    cout << ans;
}   