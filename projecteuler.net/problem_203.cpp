//======================================================
// Author      : Omar_Hafez
// Created     : 12 December 2022 (Monday)  1:59:39 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

bool isPrime(ull n) {
  if(n == 2 || n == 5) return 1;
  if (n < 2 || n%2 == 0 || n%5 == 0) 
    return 0;
  for(ull i = 3; i*i <= n; i+=2) {
    if(n%i == 0) return 0;
  }
  return 1;
}

signed main() { 

    vector<ull> primes;
    for(ull i = 2; i < 100; i++) {
      if(isPrime(i)) {
        primes.push_back(i*i);
      }
    }
    int N = 51;
    vector<vector<ull>> pascal_triangle(N+1, vector<ull> (N+1));
    pascal_triangle[1][1] = 1;
    for(int i = 2; i <= N; i++) {
      for(int j = 1; j <= i; j++) {
        pascal_triangle[i][j] = pascal_triangle[i-1][j-1]+pascal_triangle[i-1][j];
      }
    }
    set<ull> st;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= i; j++) {
        st.insert(pascal_triangle[i][j]);
      }
    }
    ull ans = 0;

    for(auto x : st) {
      bool ok = 1;
      for(int i = 0; i < primes.size() && primes[i] <= x; i++) {
        if(x%primes[i] == 0) {
          ok = 0;
          break;
        } 
      }
      if(ok) {
        ans += x;
      }
    }
    cout << ans;

}