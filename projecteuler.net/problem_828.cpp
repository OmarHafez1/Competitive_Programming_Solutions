#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define EPS .0000001
#define MOD 1005075251

int target;
int mn;
int bitmask = 0, sum = 0;
int a[6];
void solve() {
    int countTMP = 0;
    for(int i = 0; i < 6; i++) {
        if(bitmask ^ (1 << i)) {
            countTMP++;
            if(a[i] == target) {
                mn = min(mn, sum);
                return;
            }
        }
    }
    if(countTMP == 1) return;
    for(int i = 0; i < 6; i++) {
        if(bitmask & (1 << i)) continue;
        for(int j = i+1; j < 6; j++) {
            if(bitmask & (1 << j)) continue;
            int x = a[i], y = a[j];
            bool ox = 0, oy = 0;
            if(x < 0) {
                ox = 1;
                x *= -1;
                sum += x;
            }
            if(y < 0) {
                oy = 1;
                y *= -1;
                sum += y;
            }
            bitmask ^= (1 << j);
            a[i] = x+y;
            solve();
            if(x > y) {
                a[i] = x-y;
                solve();
            }
            if(y > x) {
                a[i] = y-x;
                solve();
            }
            a[i] = x*y;
            solve();
            if(x > 0 && y%x == 0) {
                a[i] = y/x;
                solve();
            } 
            if(y > 0 && x%y == 0) {
                a[i] = x/y;
                solve();
            }
            sum -= ox*x+oy*y;
            bitmask ^= (1 << j);
            a[i] = (x * (ox? -1 : 1));
        }  
    }
}

signed main() { 
    int ans = 0, pw = 3;
    while(scanf("%lld:%lld,%lld,%lld,%lld,%lld,%lld", &target, &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) == 7) {
        for(auto &x : a) x*=-1;
        mn = INT_MAX;
        solve();
        if(mn == INT_MAX) mn = 0;
        ans += mn*pw;
        ans %= MOD;
        pw = (pw*3)%MOD;
    }
    cout << ans;
}
