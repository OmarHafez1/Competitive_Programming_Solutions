#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define endl '\n'
#define newl cout<<endl

#define EPS .0000001
#define MOD 1e9+7

signed main() {
    int n;
    cin >> n;
    n++;
    int ans = 0;
    int lst = 2;
    while(lst/2 <= n-1) {
        ans += (n/lst)*(lst/2);
        ans += max(n%lst-lst/2, 0LL);
        lst *= 2;
    }
    cout << ans;
}