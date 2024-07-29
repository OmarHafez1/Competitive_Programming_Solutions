#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define int ull

int exponential_mod(int n, int p, int m) {
    if(p == 0) return 1;
    if(p&1) return (exponential_mod(n, p-1, m)*n)%m;
    int tmp = exponential_mod(n, p/2, m)%m;
    return (tmp*tmp)%m;
}

int calc(int a, int b) {
    if(b == 1) return a;
    return exponential_mod(a, calc(a, b-1), 1e8);
}

signed main() {
    int a, b;
    cin >> a >> b;
    cout << calc(a, b);
}   