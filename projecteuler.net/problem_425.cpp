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

vector<bool> primes_sieve(int n) {
    vector<bool> isP(n+1, 1);
    isP[0] = isP[1] = 0;
    for(int i = 4; i <= n; i+=2) isP[i] = 0;
    for(int i = 3; i <= n; i+=2) {
        if(!isP[i]) continue;
        for(int j = i*2; j <= n; j+=i) {
            isP[j] = 0;
        }
    }
    return isP;
}

signed main() {
    int N, ans = 0;
    cin >> N;
    auto isPrime = primes_sieve(N+10);
    vector<int> primes = {2};
    for(int i = 3; i <= N; i+=2) {
        if(isPrime[i]) primes.push_back(i), ans += i;
    }
    vector<int> adj[N+10];
    for(auto &p : primes) {
        string s = to_string(p);
        s = "0" + s;
        string s2 = s;
        for(int i = 0; i < s.size(); i++) {
            for(int d = (s[i]-'0'+1); d < 10; d++) {
                s[i] = (char)(d+'0');
                int tmp = stoll(s);
                if(tmp <= N && tmp > 1 && isPrime[tmp]) {
                    adj[tmp].push_back(p);
                    adj[p].push_back(tmp);
                }
            }
            s = s2;
        }
    }

    queue<pair<int, int>> q;
    q.push({2, 2});

    int deg[10000010];
    memset(deg, 7, sizeof(deg));
    unordered_set<int> st;
    while(!q.empty()) {
        int u = q.front().first, val = q.front().second; q.pop();
        if(val < u) {
            if(isPrime[u])  ans -= u;
            isPrime[u] = 0;
        }
        val = max(val, u);
        for(auto &v : adj[u]) {
            if(val < deg[v]) {
                deg[v] = val;
                q.push({v, deg[v]});
            }
        }
    }
    cout << ans;
}
