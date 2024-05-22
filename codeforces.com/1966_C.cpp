#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define endl '\n'

#define EPS .0000001
#define MOD 1e9+7

void calculate();

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
        cout << endl;
    }
}

int n;
vector<int> a;

void calculate() {
    cin >> n;
    bool ok = 0;
    a = vector<int>(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int rem = 0;
    int i = 0;
    for(i = 0; i < n; i++) {
        a[i] -= rem;
        if(a[i] == 0) continue;
        if(a[i] > 1) break;
        rem++;
        ok ^= 1;
    }
    if(i < n) {
        ok ^= 1;
    }
    cout << (ok? "Alice" : "Bob");
}