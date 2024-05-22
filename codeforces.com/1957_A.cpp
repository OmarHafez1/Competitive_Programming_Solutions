#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define EPS .0000001
#define MOD 1e9+7

void calculate();

int a[101];
signed main() {
    memset(a, 0, sizeof(a));
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

void calculate() {
    int n;
    cin >> n;
    int tmp;
    while(n--) {
        cin >> tmp;
        a[tmp]++;
    }
    int ans = 0;
    for(int i = 1; i <= 100; i++) {
        ans += a[i]/3;
        a[i] = 0;
    }
    cout << ans << endl;
}