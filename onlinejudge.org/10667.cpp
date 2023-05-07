//============================================================================
// Author      : Omar_Hafez
// Created     : 06 May 2023 (Saturday)  1:36:36 PM
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

// some hacks
#define endl '\n'
#define newl cout<<endl;

void calculate();

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    int t;
    cin >> t;
    while(t--) {
        calculate();
        newl;
    }
}

void calculate() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n+10, vector<int> (n+10, 1));
    for(int i = 0; i <= n; i++) {
        a[i][0] = 0;
        a[0][i] = 0;
    }
    int x1, y1, x2, y2;
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                a[i][j] = -100000;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = i; k <= n; k++) {
                for(int w = j; w <= n; w++) {
                    ans = max(ans, a[k][w]-a[i-1][w]-a[k][j-1]+a[i-1][j-1]);
                }
            }
        }
    }
    cout << ans;
}
