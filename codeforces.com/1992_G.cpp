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
#define MOD 1000000007
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

#define _MAX 5005
int triangle[_MAX + 1][_MAX + 1];
void makeTriangle() {
    int i, j;
    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1
    for(i = 1; i < _MAX; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            triangle[i][j] %= MOD;
        }
    }
}
int nCr(int n, int r) {
    if(n < 0) return 1;
    if(r > n) return 0;
    return triangle[n][r];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    makeTriangle();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

int mul(int a, int b, int c) {
    a *= b;
    a %= MOD;
    a *= c;
    return a%MOD;
}

void calculate() {
    int n, ans = 0;
    cin >> n;
    for(int sz = 0; sz <= n; sz++) {
        for(int m = sz+1; m <= 2*sz+1; m++) {
            if(m > n) {
                m = 2*sz+1;
            }
            ans += mul(m, nCr(min(m-1, n), m-sz-1), nCr(n-m, sz-m+sz+1));
            ans %= MOD;
        }
    }
    cout << ans << endl;
}