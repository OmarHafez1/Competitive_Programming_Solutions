 
//======================================================
// Author      : Omar_Hafez
// Created     : 29 September 2022 (Thursday)  9:51:20 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

vector<bool> get_primes(ull n) {
  vector<bool> primes(n+1, 1);
  primes[0] = 0;
  primes[1] = 0;
  for (ull i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (ull j = i * i; j <= n; j += i)
        primes[j] = 0;
    }
  }
  return primes;
}

vector<bool> prime;

bool check(int n, int m) {
    if(!prime[stoi(to_string(n)+to_string(m))]) return 0;
    if(!prime[stoi(to_string(m)+to_string(n))]) return 0;
    return 1;
}

int main() { 
    prime = get_primes(100000000);
    vector<int> a;
    for(int i = 0; i < 10000; i++) {
        if(prime[i]) a.push_back(i);
    }
    int ans = INT_MAX;
    for(int i1 = 0; i1 < a.size(); i1++) {
        for(int i2 = i1+1; i2 < a.size(); i2++) {
            if(!check(a[i1], a[i2])) continue;
            for(int i3 = i2+1; i3 < a.size(); i3++) {
                if(!check(a[i1], a[i3]) || !check(a[i2], a[i3])) continue;
                for(int i4 = i3+1; i4 < a.size(); i4++) {
                    if(!check(a[i1], a[i4]) || !check(a[i2], a[i4]) || !check(a[i3], a[i4])) 
                        continue;
                    for(int i5 = i4+1; i5 < a.size(); i5++) {
                        if(!check(a[i1], a[i5]) || !check(a[i2], a[i5]) || 
                           !check(a[i3], a[i5]) || !check(a[i4], a[i5])) continue;
                        ans = min(ans, a[i1]+a[i2]+a[i3]+a[i4]+a[i5]);
                    }
                }
            }
        }
    }
    cout << ans;
}