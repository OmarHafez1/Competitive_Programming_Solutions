//============================================================================
// Author      : Omar_Hafez
// Created     : 28 September 2022 (Wednesday)  6:45:48 PM
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

vector<bool> get_primes(unsigned long long n) {
  vector<bool> primes(n+1, 1);
  primes[0] = 0;
  primes[1] = 0;
  for (unsigned long long i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (unsigned long long j = i * i; j <= n; j += i)
        primes[j] = 0;
    }
  }
  return primes;
}

signed main() { 
    vector<bool> prime = get_primes(1000000);
    for(int i = 0; i < prime.size(); i++) {
        if(!prime[i]) continue;
        string s = to_string(i);
        vector<int> cnt(10);
        for(char& x : s) {
            cnt[x-'0']++;
        }
        for(int k = 0; k < 10; k++) {
            if(cnt[k] > 1) {
                string r(s.size(), '*');
                for(int w = 0; w < s.size(); w++) {
                    r[w] = ((s[w]-'0') == k? '+' : s[w]);
                }
                int count = 0;
                string start = "-1";
                bool leading_zero = 0;
                for(int w = 0; w < 10; w++) {
                    string tmp = r;
                    for(int m = 0; m < r.size(); m++) {
                        if(tmp[m] == '+') {
                            tmp[m] = (char)(w+'0');
                        }
                    }
                    leading_zero = (to_string(stoi(tmp)).size() != tmp.size());
                    if(prime[stoi(tmp)] && !leading_zero) {
                        count++;
                        if(start == "-1") start = tmp;
                    }
                }
                if(count >= 8) {
                    cout << start;
                    return 0;
                }
            }
        }
    
    }
    
}
    