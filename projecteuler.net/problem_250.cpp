#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define endl '\n'
#define newl cout<<endl

#define EPS .0000001
#define MOD 10000000000000000LL

int a[250255];
int dp[260][250260];

int exponential_mod(int n, int p, int m) {
    if(p == 0) return 1;
    if(p&1) return (exponential_mod(n, p-1, m)*n)%m;
    int tmp = exponential_mod(n, p/2, m)%m;
    return (tmp*tmp)%m;
}

int go(int i, int sum) {
    sum %= 250;
    if(i == 250251) return (sum == 0);
    if(~dp[sum][i]) return dp[sum][i];
    return dp[sum][i] = (go(i+1, sum+a[i])+go(i+1, sum))%MOD;
}

signed main() {
    for(int i = 1; i <= 250250; i++) {
        a[i] = exponential_mod(i, i, 250);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(1, 0)-1;
}

