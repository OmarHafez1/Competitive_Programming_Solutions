#include <bits/stdc++.h>
using namespace std;

int GCD[101][101];

bool ok(int a, int b, int c, int d) {
    int total = (a*b+b*c+c*d+d*a-GCD[a][b]-GCD[b][c]-GCD[c][d]-GCD[a][d])/2+1;
    int tmp = sqrt(total) + .00001;
    return tmp*tmp == total;
}

signed main() {
    int m, ans = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            GCD[i][j] = __gcd(i, j);
        }
    }
    cin >> m;
    for(int a = 1; a <= m; a++) {
        for(int b = 1; b <= m; b++) {
            for(int c = 1; c <= m; c++) {
                for(int d = 1; d <= m; d++) {
                    ans += ok(a, b, c, d);
                }
            }
        }
    }
    cout << ans;
}   

