#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

#define MOD 1123455689

int n;
int ans = 0;

vector<int> a;

void go(int d, int num) {
    if(d == 10) {
        a.push_back(num);
        return;
    }
    if(num && ceil(log10(num)) == n+1) return;
    go(d+1, num);
    if(num == 0 && d == 0) return;
    go(d, num*10+d);
}

int combination(int n, int k) {
    if (k > n - k) k = n - k; 
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result%MOD;
}

int calc(int x) {
    int cnt[10] = {0};
    while(x) {
        cnt[x%10]++;
        x/=10;
    }
    int res = 1, rem = 0;
    for(int i = 0; i < 10; i++) {
        res *= combination(n-rem, cnt[i]);
        res %= MOD;
        rem += cnt[i];
    }
    return res%MOD;
}

signed main() { 
    cin >> n;
    go(0, 0);
    for(auto &x : a) {
        ans += calc(x)*(x%MOD);
        ans %= MOD;
    }
    cout << ans;
} 