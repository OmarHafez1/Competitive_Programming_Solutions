#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define endl '\n'

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define EPS .0000001
#define MOD 1e9+7
#define PI 3.14159265358979323846

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define rsor(x) sort(all(x), greater<>())

#define uset unordered_set
#define mset multiset
#define umset unordered_multiset

template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;

signed main() {
    int n, m;
    cin >> n >> m;
    bool oc[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> oc[i];
    }
    vector<int> adj[n+1];
    for(int i = 1; i <= m; i++) {
        int cnt, door;
        cin >> cnt;
        while(cnt--) {
            cin >> door;
            adj[door].push_back(i);
        }
    }
    vector<pair<int, int>> graph[m+1];
    for(int i = 1; i <= n; i++) {
        int u = adj[i][0], v = adj[i][1];
        graph[u].push_back({v, oc[i]});
        graph[v].push_back({u, oc[i]});
    }
    int color[m+1];
    memset(color, -1, sizeof(color));
    for(int i = 1; i <= m; i++) {
        if(~color[i]) continue;
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &w : graph[u]) {
                int v = w.first, c = w.second;
               // cout << u << " " << v << " " << c << endl;
                if(~color[v]) {
                    if(c) {
                        if(color[v] != color[u]) {
                            cout << "NO";
                            return 0;
                        }
                    } else {
                        if(color[v] == color[u]) {
                            cout << "NO";
                            return 0;
                        }
                    }
                } else {
                    color[v] = color[u]^(!c);
                    q.push(v);
                }
            }
        }
    }
    cout << "YES";
}   

