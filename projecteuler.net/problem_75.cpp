//======================================================
// Author      : Omar_Hafez
// Created     : 29 September 2022 (Thursday)  11:42:47 AM
//======================================================

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

int N = 15e5;

signed main() { 
    int ans = 0;
    vector<int> count(N+1);
    for(int n = 1; n < 1000; n++) {
        for(int m = n+1; m < 1000; m += (n&1? 2 : 1)) {
            int L = 2*m*(m+n);
            if(L > N) break;
            if(__gcd(n, m) != 1) continue;
            int LL = 0;
            for(int k = 1; k <= N/10; k++) {
                LL += L;
                if(LL > N) break;
                ans += (count[LL] == 1? -1 : count[LL] == 0? 1 : 0);
                count[LL]++;
            }
        }
    }
    cout << ans;
}