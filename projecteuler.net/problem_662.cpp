#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double

#define endl '\n'
#define newl cout<<endl

#define EPS .0000001
#define MOD 1000000007

set<ull> fab;
set<pair<int, int>> moves;
int dp[10001][10001];
int N, M;

int go(int x, int y) {
    if(x == N && y == M) {
        return 1;
    }
    if(x > N || y > M) return 0;
    int &tmp = dp[x][y];
    if(~tmp) return tmp;
    int &tmp2 = dp[y][x];
    if(~tmp2) return tmp2;
    int res = 0;
    for(auto &m : moves) {
        res += go(x+m.first, y+m.second);
        res %= MOD;
    }
    return tmp = tmp2 = res;
}

signed main() {
    cin >> N >> M;
    for(ull a = 0, b = 1, c = 1; c <= 1000000000LL; fab.insert(c), c = a+b, a = b, b = c) {}
    for(int x = 0; x <= N; x++) {
        for(int y = x; y <= M; y++) {
            int tmp = x*x+y*y;
            int ss = sqrt(tmp)+EPS;
            if(ss * ss == tmp) {
                if(fab.find(ss) != fab.end()) {
                    moves.insert({x, y});
                    if(x != y)
                        moves.insert({y, x});
                }
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << endl;
}

