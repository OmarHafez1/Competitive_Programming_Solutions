//============================================================================
// Author      : Omar_Hafez
// Created     : 12 March 2023 (Sunday)  3:10:29 PM
//============================================================================

 /*   
                ________
               /        \
              / /      \ \
     ________/ /        \ \________
    /        \            /        \ 
   / /      \ \  ______  / /      \ \
  / /        \ \________/ /        \ \ 
  \            /        \            /
   \  ______  / /      \ \  ______  /    
    \________/ /        \ \________/
    /        \            /        \
   / /      \ \  ______  / /      \ \   
  / /        \ \________/ /        \ \
  \            /        \            /    
   \  ______  / /      \ \  ______  /
    \________/ /        \ \________/
             \            /     
              \  ______  / 
               \________/ 

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long

#define N 4e7

// O(n log log(n))
vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

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


signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    vector<bool> isPrime = get_primes(N+1);
    vector<int> phi = phi_1_to_n(N+1);
    int ans = 0;
    for(int i = 2; i < N; i++) {
        if(isPrime[i]) {
            int n = i;
            for(int j = 0; j < 23 && n > 1; j++) {
                n = phi[n];
            }
            if(n != 1 && phi[n] == 1) {
                ans += i;
            }
        }
    }
    cout << ans;
    
}
