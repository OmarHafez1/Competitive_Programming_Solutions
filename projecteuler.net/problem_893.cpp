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

int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
            // 0  1  2  3  4  5  6  7  8  9

int calc(int n) {
    int res = 0;
    while(n) {
        res += cnt[n%10];
        n/=10;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[n+10];
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= n; i++) {
        a[i] = calc(i);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; i*j <= n; j++) {
            a[i*j] = min(a[i*j], a[i]+a[j]+2);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; i+j <= n; j++) {
            a[i+j] = min(a[i+j], a[i]+a[j]+2);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += a[i];
    }
    cout << ans;
    
}   

