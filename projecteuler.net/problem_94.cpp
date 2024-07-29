#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ull unsigned long long
#define int ull

#define EPS .0000001

#define N 1e9

bool ok(int a, int c) {
    if(c == 0 || (c*c)%4 != 0) return 0;
    int h = a*a-(c*c)/4;
    int tmp = sqrt(h)+EPS;
    if(tmp*tmp != h || tmp == 0) return 0; 
    return (2*tmp*c)%4 == 0;
}

signed main() {
    int ans = 0;
    for(int i = 1; i*3-1 <= N; i++) {
        if(ok(i, i-1)) {
            ans += i*3-1;
        }
        if(ok(i, i+1)) {
            ans += i*3+1;
        }
    }
    cout << ans;
}   
