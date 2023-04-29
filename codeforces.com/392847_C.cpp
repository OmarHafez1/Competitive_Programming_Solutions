//============================================================================
// Author      : Omar_Hafez
// Created     : 03 August 2022 (Wednesday)  5:25:06 AM
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
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a, a+n);
    vector<pair<int, int>> x;
    x.emplace_back(mp[a[0]], a[0]);
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) continue;
        x.emplace_back(mp[a[i]], a[i]);
    }
    if(x.size() < k) {
        cout << "I'm not happy";
        return 0;
    }
    sort(x.begin(), x.end(), greater<>());
    for(int i = 0; i < k; i++) {
        cout << x[i].second << " ";
    }

}
