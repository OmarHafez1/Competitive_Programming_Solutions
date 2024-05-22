#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

vector<int> primes;

vector<bool> prime_sieve(int n) {
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

signed main() { 
    int n;
    cin >> n;
    auto isP = prime_sieve(n/2);
    primes.push_back(2);
    for(int i = 3; i < n/2; i+=2) {
        if(isP[i]) primes.push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < primes.size() && primes[i] <= sqrt(n); i++) {
        for(int j = i+1; j < primes.size(); j++) {
            if(primes[i]*primes[j] > n) break;
            int mx = 0;
            int t1 = primes[i];
            while(t1 < n) {
                int t2 = primes[j];
                while(t1*t2 <= n) {
                    mx = max(mx, t1*t2);
                    t2 *= primes[j];
                }
                t1 *= primes[i];
            }
            ans += mx;
        }
    }
    cout << ans;
} 
   