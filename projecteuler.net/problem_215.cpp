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

vector<pair<int, int>> lines;

void go(int n, int ind, int mask) {
    if(n == 0) {
        lines.push_back({mask, ind});
        return;
    }
    if(n <= 1) return;
    go(n-2, ind+1, mask);
    go(n-3, ind+1, mask | (1 << ind));
}

vector<vector<int>> linesSUM;

bool ok(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0, n = a.size()-1, m = b.size()-1;
    while(i < n && j < m) {
        if(a[i] == b[j]) return 0;
        if(a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    while(i < n) {
        if(a[i] == b[m-1]) return 0;
        i++;
    }
    while(j < m) {
        if(b[j] == a[n-1]) return 0;
        j++;
    }
    return 1;
}

vector<int> adj[4000];
int R, N;

int dp[32][10000];

int dfs(int row, int ind)  {
    if(row == 0) {
        return 1;
    }
    int res = 0;
    int &tmp = dp[row][ind];
    if(~tmp) return tmp;
    for(auto &x : adj[ind]) {
        res += dfs(row-1, x);
    }
    return tmp = res;
}

signed main() {
    cin >> N >> R;
    memset(dp, -1, sizeof(dp));
    go(N, 0, 0);
    for(auto &x : lines) {
        int sum = 0;
        vector<int> tmp;
        for(int i = 0; i < x.second; i++) {
            if(x.first & (1 << i)) {
                sum += 3;
            } else {
                sum += 2;
            }
            tmp.push_back(sum);
        }
        linesSUM.push_back(tmp);
    }
    for(int i = 0; i < linesSUM.size(); i++) {
        for(int j = i+1; j < linesSUM.size(); j++) {
            if(ok(linesSUM[i], linesSUM[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < linesSUM.size(); i++) {
        ans += dfs(R-1, i);
    }
    cout << ans;
}
