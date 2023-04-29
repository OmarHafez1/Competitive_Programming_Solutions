//============================================================================
// Author      : Omar_Hafez
// Created     : 30 September 2022 (Friday)  11:18:46 AM
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

bool have(vector<int> &a, int val) {
    if(find(a.begin(), a.end(), val) != a.end()) return 1;
    if(val == 6) {
        return find(a.begin(), a.end(), 9) != a.end();
    }
    if(val == 9) {
        return find(a.begin(), a.end(), 6) != a.end();
    }
    return 0;
}

bool check(vector<int> &a, vector<int> &b) {
    for(int i = 1; i*i < 100; i++) {
        int y = (i*i)%10, x = (i*i)/10;
        if(!(have(a, x) && have(b, y)) && !(have(a, y) && have(b, x))) {
            return 0;
        }
    }
    return 1;
}

signed main() { 
    vector<vector<int>> a;
    for(int i = 0; i < 1024; i++) {
        if(__builtin_popcountll(i) != 6) continue;
        vector<int> x;
        for(int j = 0; j < 10; j++) {
            if(i & 1 << j) {
                x.push_back(j);
            }
        }
        a.push_back(x);
    }   
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = i; j < a.size(); j++) {
            if(check(a[i], a[j])) {
                ans++;
            }
        }
    }
    cout << ans;
}
