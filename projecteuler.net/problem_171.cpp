#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define i128 __int128
#define int ull

set<int> fs;
vector<vector<int>> fw[50];

vector<int> a(10);

void solve(int f, int lst, int cnt) {
    if(cnt > 20) return;
    int tmp = sqrt(f)+.0001;
    if(tmp*tmp == f && f != 0) {
        fs.insert(tmp);
        fw[tmp].push_back(a);
    }
    for(int i = lst; i <= 9; i++) {
        a[i]++;
        solve(f+i*i, i, cnt+1);
        a[i]--;
    }
}

#define MOD 1000000000

int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (int)round(exp(res))%MOD;
}

int exponential_mod(int n, int p, int m) {
    if(p == 0) return 1;
    if(p&1) return (exponential_mod(n, p-1, m)*n)%m;
    int tmp = exponential_mod(n, p/2, m)%m;
    return (tmp*tmp)%m;
}

int calc(vector<int> &a, int d, int pos) {
    int cnt = 1;
    int total = 19;
    for(int i = 0; i <= 9; i++) {
        cnt *= nCr(total, a[i]-(i == d));
        total -= (a[i]-(i == d));
        cnt %= MOD;
    }
    return (exponential_mod(10, pos, MOD)*cnt*d)%MOD;
}

signed main() {
    solve(0, 1, 0);
    ull ans = 0;
    for(auto &x : fs) {
        for(auto &w : fw[x]) {
            for(int pos = 0; pos < 9; pos++) {
                for(int d = 1; d <= 9; d++) {
                    if(w[d] == 0) continue;
                    ans += calc(w, d, pos);
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans;
}   
