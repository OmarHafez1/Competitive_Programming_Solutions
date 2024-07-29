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

int a[200005], b[200005];

void calculate() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    int dif = INT_MAX, f;
    for(int i = 0; i < n; i++) {
        if(b[i] > a[i]) swap(a[i], b[i]);
        ans += a[i]-b[i];
        if(b[n] >= b[i] && b[n] <= a[i]) dif = 0;
        dif = min(dif, abs(a[i]-b[n]));
        dif = min(dif, abs(b[i]-b[n]));
    }
    ans += dif+1;
    cout << ans << endl;

}