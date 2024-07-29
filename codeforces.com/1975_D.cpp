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

void calculate();

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

vector<vector<int>> adj;

vector<bool> vis;
int ans = 0;
void calc(int u) {
    for(auto &v : adj[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        ans++;
        calc(v);
        ans++;
    }
}

void calculate() {
    int n;
    cin >> n;
    vis = vector<bool>(n+1);
    adj = vector<vector<int>> (n+1);
    int a, b;
    cin >> a >> b;
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> len = vector<int>(n+1, -1);
    len[a] = 0;
    queue<int> q;
    q.push(a);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto &v : adj[u]) {
            if(len[v] != -1) continue;
            len[v] = len[u]+1;
            q.push(v);
        }
    }
    ans = (len[b]+1)/2;

    vector<int> len2(n+1, -1);
    len2[b] = 0;
    q.push(b);
    int start = 0;
    while(!q.empty()) {
        int u = q.front();
        if(len2[u] == ans && (len[u]+!!(len[b]&1)) == ans) {
            start = u;
        }
        q.pop();
        for(auto &v : adj[u]) {
            if(len2[v] != -1) continue;
            len2[v] = len2[u]+1;
            q.push(v);
        }
    }  
    vector<int> len3 = vector<int>(n+1, -1);
    len3[start] = 0;
    q.push(start);
    int mx = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto &v : adj[u]) {
            if(len3[v] != -1) continue;
            len3[v] = len3[u]+1;
            mx = max(mx, len3[v]);
            q.push(v);
        }
    }
    ans -= mx;
    vis[start] = 1;
    calc(start);
    cout << ans << endl;
}