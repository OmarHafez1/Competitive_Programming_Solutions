#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ull

#define endl '\n'
#define newl cout<<endl

#define EPS .0000001
#define MOD 1e9+7

bool isPS(int n) {
    int tmp = sqrt(n);
    return tmp*tmp == n;
}

signed main() {
    int N = 64e6;
    int a[N+10];
    memset(a, 0, sizeof(a));
    int ans = 0;
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            a[j] += i*i;
        }
        if(isPS(a[i])) ans += i;
    }
    cout << ans;
}
