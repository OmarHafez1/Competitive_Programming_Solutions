#include <bits/stdc++.h>
using namespace std;

#define ld long double

bool bigger(int n, int d1, int d2) {
    return d1*1.0*(log(n)-log(d1)) > d2*1.0*(log(n)-log(d2));
}

int M(int n) {
    int d = 1;
    for(int i = 2; i < n; i++) {
        if(bigger(n, i, d)) {
            d = i;
        }
    }
    return d;
}

bool isTerminating(int n, int d) {
    int dec = __gcd(n, d);
    n /= dec; d /= dec;
    while(d%2 == 0) d/=2;
    while(d%5 == 0) d/=5;
    return d == 1;
}

int D(int n) {
    return pow(-1, isTerminating(n, M(n)))*n;
}

signed main() {
    int N, ans = 0;
    cin >> N;
    for(int n = 5; n <= N; n++) {
        ans += D(n);
    }
    cout << ans;
}   

