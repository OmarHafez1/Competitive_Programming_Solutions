#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double

#define int ull

ll N = 6227020800;

vector<int> primes = {2, 3, 5, 7, 11, 13};
int powers[6] = {10, 5, 2, 1, 1, 1};

vector<int> nums;

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

void go(int ind, int n, int phi) {
    if(phi == N) {
        nums.push_back(n);
        return;
    }
    if(ind >= primes.size() || phi > N || phi%(13*13) == 0 || phi%(11*11) == 0 || phi%(7*7) == 0 || phi%(5*5*5) == 0 || phi%729 == 0 || phi%2048 == 0) {
        return;
    }
    go(ind+1, n, phi);
    if(ind >= 6) {
        go(ind+1, n*primes[ind], phi*(primes[ind]-1));
    } else {
        int p = 1;
        for(int i = 0; i <= powers[ind]; i++) {
            go(ind+1, n*p*primes[ind], phi*p*(primes[ind]-1));
            p *= primes[ind];
        }
    }
}

void gen(int ind, int n) {
    if(ind == 6) {
        if(n+1 > 13 && isPrime(n+1)) {
            primes.push_back(n+1);
        }
        return;
    }
    int p = 1;
    for(int i = 0; i <= powers[ind]; i++) {
        gen(ind+1, n*p);
        p *= primes[ind];
    }
}

signed main() {
    gen(0, 1);
    go(0, 1, 1);
    sort(nums.begin(), nums.end());
    cout << nums[150000-1];
}   