//======================================================
// Author      : Omar_Hafez
// Created     : 30 September 2022 (Friday)  3:29:01 PM
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

int factorial[10];

int calc(int n) {
    int res = 0;
    while(n) {
        res += factorial[n%10];
        n/=10;
    }
    return res;
}

int main() { 

    factorial[0] = 1;
    for(int i = 1; i < 10; i++) {
        factorial[i] = i*factorial[i-1];
    }

    int ans = 0;
    for(int i = 1; i < 1e6; i++) {
        set<int> st;
        int tmp = i;
        while(st.find(tmp) == st.end()) {
            st.insert(tmp);
            tmp = calc(tmp);
        }
        ans += (st.size() == 60);
    }
    cout << ans;
    
}