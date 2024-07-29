#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ll long long
#define ull unsigned long long
#define int ull

signed main() {
    int ans = 17+305+5473, cnt = 3;
    int lst = 5473;
    for(int n = 1; ; n++) {
        int m = sqrt(lst*17.944271-n*n);
        bool t1 = n&1, t2 = m&1;
        m += !(t1^t2);

        for(; (n*n+m*m)*1.0/lst < 17.944272; m += 2) {
            if(__gcd(n, m) != 1) continue;
            int a = n*n+m*m, b = 2*n*m, c = m*m-n*n;
            if(c > b) swap(c, b);
            if(2*c+1 == b || 2*c == b+1) {
                cnt++;
                ans += a;
                if(cnt == 12) {
                    cout << ans;
                    return 0;
                }
                lst = a;
                break;
            }
        }
    }
}   

