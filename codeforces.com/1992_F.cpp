#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define endl '\n'

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define EPS .0000001
#define MOD 1e9+7
#define PI 3.14159265358979323846

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define rsor(x) sort(all(x), greater<>())

#define uset unordered_set
#define mset multiset
#define umset unordered_multiset

template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;

void calculate();

#define N 200005

int a[N];
int b[N];
bool used[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(used, 0, sizeof(used));
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}


void calculate() {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    int i1 = 0, i2 = 0;
    for(int i = 2; i*i <= k; i++) {
        if(k%i == 0) {
            used[i] = 0;
            used[k/i] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) continue;
        if(k%a[i] != 0) continue;
        for(int j = 0; j < i1; j++) {
            if(b[j]*a[i] > k) continue;
            if(b[j]*a[i] == k) {
                ans++;
                for(int w = 0; w < i2; w++) {
                    used[b[w]] = 0;
                }
                i1 = 0;
                i2 = 0;
                break;
            }
            if(used[b[j]*a[i]]) continue;
            used[b[j]*a[i]] = 1;
            b[i2++] = b[j]*a[i];
        }
        if(!used[a[i]]) {
            used[a[i]] = 1;
            b[i2++] = a[i];
        }
        i1 = i2;
    }

    cout << ans << endl;
}