//======================================================
// Author      : Omar_Hafez
// Created     : 29 September 2022 (Thursday)  6:58:14 AM
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

vector<int> primes;
vector<int> ways(100);

void solve(int ind, int sum) {
    if(ind >= primes.size()) return;
    if(sum+primes[ind] >= ways.size()) return;
    solve(ind, sum+primes[ind]);
    ways[sum+primes[ind]]++;
    solve(ind+1, sum);
}

int main() { 
    vector<bool> tmp = get_primes(100);
    for(int i = 2; i < tmp.size(); i++) {
        if(tmp[i]) primes.push_back(i);
    }
    solve(0, 0);
    for(int i = 0; i < 100; i++) {
        if(ways[i] > 5000) {
            cout << i;
            return 0;
        }
    }
}
     
     