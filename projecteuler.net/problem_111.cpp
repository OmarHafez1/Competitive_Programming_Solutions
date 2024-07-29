#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

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

int conv(vector<int> &a) {
    int n = 0;
    for(auto &x : a) {
        n *= 10;
        n += x;
    }
    return n;
}

int solve(int ind, int d, int m, vector<int> &a) {
    int n = conv(a);
    if(ind == a.size()) {
        return isPrime(n)*n;   
    }
    if(m == 0) {
        return isPrime(n)*n;
    }
    int res = solve(ind+1, d, m, a);
    for(int i = ind == 0; i <= 9; i++) {
        if(i == d) continue;
        int tmp = a[ind];
        a[ind] = i; 
        res += solve(ind+1, d, m-1, a);
        a[ind] = tmp;
    }
    return res;
}

int S(int n, int d) {
    auto a = vector<int>(n, d);
    if(d == 0) {
        for(int m = 0; m < n-1; m++) {
            int res = 0;
            for(int i = 1; i < 10; i++) {
                a[0] = i;
                res += solve(1, d, m, a);
            }
            if(res) return res;
        }
        return 0;
    }
    for(int m = 0; m < n; m++) {
        int tmp = solve(0, d, m, a);
        if(tmp) return tmp;
    }
    return 0;
}

signed main() {

    int n;
    cin >> n;

    int ans = 0;
    for(int d = 0; d <= 9; d++) {
        ans += S(n, d);
    }
    cout << ans;
    
}   

