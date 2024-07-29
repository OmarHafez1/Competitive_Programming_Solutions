#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;
    if((n - 1) % 6 != 0 && (n + 1) % 6 != 0) return 0;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int A(int n) {
    int r = 111;
    for(int k = 4; ; k++) {
        r = r*10+1;
        r%=n;
        if(r == 0) return k;
    }
    return 0;
}

signed main() {
    int cnt = 0, ans = 0;
    for(int n = 91; cnt < 25; n+=2) {
        if(n%5 == 0) continue;
        if(isPrime(n)) continue;
        if((n-1)%A(n) == 0) {
            cnt++;
            ans += n;
        } 
    } 
    cout << ans;
}   

