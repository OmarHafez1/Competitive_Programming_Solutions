//============================================================================
// Author      : Omar_Hafez
// Created     : 12 July 2023 (Wednesday)  1:36:27 AM
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

const double PI = 3.141592653589793;
const int MOD = 1e9+7; 
const int INF = 1e9;

//
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using db = double; 

template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;


// loops
#define f0r(i,a) for(int i = 0; i < (a); ++i)
#define f1r(i,a) for(int i = 1; i < (a); ++i)
#define foor(i,a,b) for(int i = (a); i < (b); ++i)
#define r0f(i,a) for(int i = (a)-1; i >= 0; --i)
#define rof(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define fe(a,x) for(auto& a: x)

// some hacks
#define endl '\n'
#define newl cout<<endl;

void calculate();

// fflush(stdout);
// cout << fixed << setprecision(10);

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    while(1) {
        int m;
        cin >> m;
        if(m == 0) return 0;
        string _, __;
        cin >> _ >> __;
        string u, v, w;
        map<string, int> mp;
        int il = 0;
        vector<tuple<int, int, int>> adj[10000];
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            if(!mp.count(u)) {
                mp[u] = il++;
            }
            if(!mp.count(v)) {
                mp[v] = il++;
            }
            adj[mp[u]].push_back({mp[v], w.size(), w[0]-'a'});
            adj[mp[v]].push_back({mp[u], w.size(), w[0]-'a'});
        }
        if(!mp.count(_)) {
            mp[_] = il++;
        }
        if(!mp.count(__)) {
            mp[__] = il++;
        }
        int s = mp[_], e = mp[__];
        if(s == e) {
            cout << "impossivel" << endl;
            continue;
        }
        vector<vector<int>> dp(il+10, vector<int>(27, INF));
        pdqu<tuple<int, int, int>> q;
        dp[s][26] = 0;
        q.push({0, 26, s});
        while(!q.empty()) {
            auto t = q.top(); q.pop();
            int r = get<2>(t);
            int cost1 = get<0>(t);
            int ch1 = get<1>(t);
            for(auto &x : adj[r]) {
                int o = get<0>(x);
                int cost2 = get<1>(x);
                int ch2 = get<2>(x);
                if(ch1 == ch2) continue;
                if(dp[o][ch2] > cost1+cost2) {
                    dp[o][ch2] = cost1+cost2;
                    q.push({cost1+cost2, ch2, o});
                }
            }
        }
        int ans = INF;
        for(int i = 0; i < 26; i++) {
            ans = min(ans, dp[e][i]);
        }
        if(ans == INF) cout << "impossivel";
        else cout << ans;
        newl;
    }
}
