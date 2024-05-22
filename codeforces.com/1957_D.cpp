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

#define N 100010

int a[N], xs[N][30][2];

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

void calculate() {
    int n;
    cin >> n;
    int tmp = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp ^= a[i];
        for(int j = 0; j < 30; j++) {
            xs[i][j][0] = xs[i-1][j][0];
            xs[i][j][1] = xs[i-1][j][1];
            xs[i][j][!!(tmp & (1 << j))]++;
        }
    }
    for(int x = 1; x <= n; x++) {
        for(int y = x; y <= n; y++) {
            for(int z = y; z <= n; z++) {
                int tmp = 0;
                for(int i = x; i <= z; i++) {
                    tmp ^= a[i];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int t = 30;
        while(!((1 << t) & a[i])) t--;
        ans += (xs[i-1][t][0]+1)*(xs[n][t][0]-xs[i-1][t][0]);
        ans += xs[i-1][t][1]*(xs[n][t][1]-xs[i-1][t][1]);
    }
    cout << ans << endl;
}
