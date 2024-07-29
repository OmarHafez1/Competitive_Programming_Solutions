#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ull unsigned long long
#define ll long long
#define ld long double

signed main() {
    int n = 2000;
    cin >> n;
    int a[n+1][n+1];
    int s[n*n+1];
    for(ll k = 1; k <= 55; k++) {
        s[k] = (100003-200003*k+300007*k*k*k)%1000000-500000;
    }
    for(int k = 56; k <= n*n; k++) {
        s[k] = (s[k-24]+s[k-55]+1000000)%1000000 - 500000;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[j][i] = s[(j-1)*n+i];
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        for(int j = 1; j <= n; j++) {
            sum = max(sum+a[i][j], a[i][j]);
            ans = max(ans, sum);
            sum2 = max(sum2+a[j][i], a[j][i]);
            ans = max(ans, sum2);
        }
        int x = i, y = 1;
        while(x <= n && y <= n) {
            sum3 = max(sum3+a[x][y], a[x][y]);
            ans = max(ans, sum3);
            x++; y++;
        }
        x = 1, y = i;
        while(x <= n && y > 0) {
            sum4 = max(sum4+a[x][y], a[x][y]);
            ans = max(ans, sum4);
            x++; y--;
        }
    }
    cout << ans;
}   

