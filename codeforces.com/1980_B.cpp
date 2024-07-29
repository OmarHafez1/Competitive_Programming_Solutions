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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

int a[105];

void calculate() {
    int n, f, k;
    cin >> n >> f >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int v = a[f-1];
    sort(a, a+n, greater<>());
    a[n] = INT_MAX;
    for(int i = 0; i < k; i++) {
        if(a[i] == v) {
            cout << ((a[k] == v)? "MAYBE" : "YES") << endl;
            return;
        } 
    }
    cout << "NO" << endl;
}