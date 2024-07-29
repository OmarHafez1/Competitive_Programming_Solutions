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

bool isP(ull n) {
    int tmp = sqrt(n)+.00001;
    return (tmp*tmp == n);
}

bool ok(ull x, ull y, ull z) {
    // x+y z
    // x  y+z
    if(isP((x+y)*(x+y)+z*z)) return 1;
    return 0;
}

int M(int n) {
    // We can improve this brute force by generating Pythagorean triples instead.. 
    // But this simple implementation is good enough for the problem constrains.
    int sum = 0;
    for(int x = 1; x <= n; x++) {
        for(int y = x; y <= n; y++) {
            for(int z = y; z <= n; z++) {
                sum += ok(x, y, z);
            }
        }
    }
    return sum;
}

signed main() {
    int left = 1000, right = 2000, mid, ans = 0;
    while(left <= right) {
        mid = (left+right)/2;
        if(M(mid) > 1e6) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans;
}   
