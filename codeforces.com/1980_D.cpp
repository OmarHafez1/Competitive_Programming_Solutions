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

void calculate() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n-1);
    for(int i = 0; i < n-1; i++) {
        b[i] = __gcd(a[i], a[i+1]);
    }
    set<int> pos;
    for(int i = 0; i < n-2; i++) {
        if(b[i] > b[i+1]) {
            pos.insert(i+1);
            pos.insert(i);
            if(i+2 < n)
                pos.insert(i+2);
        }
    }
    if(pos.size() > 5) {
        cout << "NO" << endl;
        return;
    }
    if(pos.size() < 3) {
        cout << "YES" << endl;
        return;
    }
  //  cout << pos.size() << endl;
    for(auto &i : pos) {
        if(i == 0) {
            if(pos.size() == 3) {
                cout << "YES" << endl;
                return;
            }
            continue;
        }
        if(i == n-1) {
            if(pos.size() == 3) {
                cout << "YES" << endl;
                return;
            }
            continue;
        }
        int tmp1 = b[i-1], tmp2 = b[i];
        b[i-1] = __gcd(a[i-1], a[i+1]);
        b[i] = b[i-1];
       // cout << a[i] << " " << b[i-1] << " " << b[i] << endl;
        bool ok = 1;
        for(int i = 0; i < n-2; i++) {
            //cout << b[i] << " ";
            if(b[i] > b[i+1]) {
                ok = 0;
             //   break;
            }
        }
      //   cout << endl;
        if(ok) {
            cout << "YES" << endl;
            return;
        }
        b[i-1] = tmp1;
        b[i] = tmp2;
    }
    cout << "NO" << endl;
}

/*YES
N00O
YES
N00O
YES
YES


NO
YES
YES
YES
YES
YES*/