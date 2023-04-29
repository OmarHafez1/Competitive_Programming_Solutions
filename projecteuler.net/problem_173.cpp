//============================================================================
// Author      : Omar_Hafez
// Created     : 12 March 2023 (Sunday)  4:00:25 PM
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

signed main() { 
    int ans = 0;
    int N = 1e6;
    for(int i = 1; (i-2)*4+4 <= N; i++) {
        int total = (i-2)*4+4+8;
        int lst = total;
        while(total <= N) {
            lst+=8;
            ans++;
            total += lst;
        }
    }
    cout << ans;
}
