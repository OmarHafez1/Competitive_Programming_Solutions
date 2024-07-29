#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

#define EPS .0000001

bool ok(vector<int> t) {
    int area = t[0]*t[0] - 2*(t[1]*t[2]);
    int s = sqrt(area)+EPS;
    if(s*s != area) return 0; 
    return (t[0]%s == 0);
}

signed main() {
    int N = 100000000;
    int ans = 0;
    for(int n = 1; n*n+(n+1)*(n+1)+2*(n*(n+1))+(n+1)*(n+1)-n*n < N; n++) {
        for(int m = n+1; ; m++) {
            if(!!(n&1) && !!(m&1)) continue;
            if(__gcd(n, m) != 1) continue;
            int a = m*m+n*n;
            int b = 2*m*n;
            int c = (m*m-n*n);
            if(a+b+c >= N) break;
            for(int k = 1; a*k+b*k+c*k < N; k++) {
                ans += (ok({a*k, b*k, c*k}));
            }
        }
    }
    cout << ans;
}
