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

template <class E> struct csr {
    vector<int> start;
    vector<E> elist;
    explicit csr(int n, const vector<pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    pair<int, vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = min(low[v], low[to]);
                } else {
                    low[v] = min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    vector<vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        vector<vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    vector<pair<int, edge>> edges;
};
struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 1 : 0), 2 * j + (g ? 0 : 1));
        scc.add_edge(2 * j + (g ? 1 : 0), 2 * i + (f ? 0 : 1));
    }

    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        add_clause_xor(i, !f, j, g);
    }

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }

    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    vector<bool> answer() { return _answer; }

  private:
    int _n;
    vector<bool> _answer;
    scc_graph scc;
};

signed main() {
    int n, m;
    cin >> n >> m;
    two_sat ts(m);
    bool a[n];
    for(auto &x : a) cin >> x;
    vector<int> ms[n];
    int x, tmp;
    for(int i = 0; i < m; i++) {
        cin >> x;
        while(x--) {
            cin >> tmp;
            ms[tmp-1].push_back(i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i]) ts.add_clause_and(ms[i][0], 1, ms[i][1], 1), ts.add_clause_and(ms[i][0], 0, ms[i][1], 0);
        else ts.add_clause_and(ms[i][0], 1, ms[i][1], 0), ts.add_clause_and(ms[i][0], 1, ms[i][1], 0);
    }
    cout << (ts.satisfiable()? "YES" : "NO");
}   

