#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ull

#define MOD (int)1e16

vector<int> a(10);

vector<vector<int>> ds[10];

void solve(int n, int d) {
    if(n > 9) return;
    a[n]++;
    ds[n].push_back(a);
    a[n]--;
    for(int i = d; i+n <= 9; i++) {
        a[i]++;
        solve(n+i, i);
        a[i]--;
    }
}

long long triangle[2025 + 1][10 + 1];
void makeTriangle() {
    int i, j;
    triangle[0][0] = 1; // C(0, 0) = 1
    for(i = 1; i < 2020+1; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= 9; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            triangle[i][j] %= MOD;
        }
    }
}

int nCr(int n, int r) {
    if(n < 0 || r < 0) return 0;
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    return triangle[n][r];
}

ull N;

int calc(vector<int> &v, int r, int p) {
    int rem = N-1;
    __int128 cnt = 1;
    v[r]--;
    for(int i = 1; i <= 9; i++) {
        cnt *= nCr(rem, v[i]);
        cnt %= MOD;
        rem -= v[i];
    }
    v[r]++;
    return (cnt*p*r)%MOD;
}

signed main() {
    cin >> N;
    makeTriangle();
    solve(0, 1);
    int ans = 0;
    int p = 1;
    for(int i = 1; i <= min(N, 16ULL); i++) {
        for(int n = 1; n <= 9; n++) {
            for(auto &w : ds[n]) {
                for(int r = 1; r <= 9; r++) {
                    ans += calc(w, r, p);
                    ans %= MOD;
                }
            }
        }
        p *= 10;
        p %= MOD;
    }
    cout << ans;
}   