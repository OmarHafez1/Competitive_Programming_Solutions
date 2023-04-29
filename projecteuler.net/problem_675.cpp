//============================================================================
// Author      : Omar_Hafez
// Created     : 01 October 2022 (Saturday)  2:02:49 PM
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

using ull = unsigned long long;

int MOD = 1000000087;
#define N 10000000

int sp[N];

void Sieve(){
    for (int i = 2; i <= N; i += 2) sp[i] = 2;
    for(int i = 3; i <= N; i++) {
        if(sp[i]) continue;
        for(int j = i; j <= N; j+=i) {
            if(!sp[j])
                sp[j] = i;
        }
    }
}

vector<pair<int, int>> factorize(int k) {
    vector <int> factorizations;
    vector<pair<int, int>> ans;
    while(k>1) {
        factorizations.push_back(sp[k]);
        k/=sp[k];
    }
    int cnt = 1;
    for(int i = 1; i < factorizations.size(); i++) {
        if(factorizations[i] == factorizations[i-1]) cnt++;
        else {
            ans.push_back({factorizations[i-1], cnt});
            cnt = 1;
        }
    }
    ans.push_back({factorizations.back(), cnt});
    return ans;
}

ull modInverse(ull a, ull b) {
  ull x = 0, y = 1, u = 1, v = 0;
  ull mm = b;
  while (a) {
    ull q = b/a; ull r = b%a;
    ull m = x - u*q; ull n = y - v*q;
    b = a; a = r; x = u; y = v; u = m; v = n;
  }
  return (x+mm)%mm;
}

signed main() { 
    Sieve();
    vector<int> count(N+100);
    ull ANS = 0;
    ull lstAns = 1;
    for(int i = 2; i <= N; i++) {
        vector<pair<int, int>> factorizations = factorize(i);
        for(auto x : factorizations) {
            ull TMP = ((lstAns%MOD)*(modInverse((count[x.first]*2+1), MOD)))%MOD;
            count[x.first] += x.second;
            TMP *= ((count[x.first]*2)+1)%MOD;
            TMP%=MOD;
            lstAns = TMP;
            lstAns %= MOD;
        }
        ANS += lstAns;
        ANS %= MOD;
    } 
    cout << ANS%MOD;
}
