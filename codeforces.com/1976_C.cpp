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

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

#define N 200005

int a[N], b[N], rsa[N], rsb[N], ca[N], cb[N], s[N];

int bs(int left, int right, int val, int a[]) {
    int mid, res = right;
    while(left <= right) {
        mid = (left+right+1)/2;
        if(a[mid] > val) right = mid-1;
        else if(a[mid] < val) left = mid+1;
        else {
            res = mid;
            right = mid-1;
        }
    }
    return res;
}

void calculate() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n+m+1; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n+m+1; i++) {
        cin >> b[i];
    }

    s[0] = ca[0] = cb[0] = 0;
    for(int i = 1; i <= n+m+1; i++) {
        s[i] = s[i-1]; ca[i] = ca[i-1]; cb[i] = cb[i-1];
        if(a[i] > b[i]) ca[i]++, s[i] += a[i];
        else cb[i]++, s[i] += b[i];
    }
    rsa[n+m+2] = rsb[n+m+2] = 0;
    for(int i = n+m+1; i; i--) {
        rsa[i] = rsa[i+1]+a[i];
        rsb[i] = rsb[i+1]+b[i];
    }

    int x = n, y = m, sum = 0;
    for(int i = 1; i <= n+m+1; i++) {
        if(x == 0) {
            cout << (sum + rsb[i+1]) << " ";
            y--;
            sum += b[i];
        } else if(y == 0) {
            cout << (sum + rsa[i+1]) << " ";
            x--;
            sum += a[i];
        } else {
            int t1 = bs(i+1, n+m+1, x+ca[i], ca);
            int t2 = bs(i+1, n+m+1, y+cb[i], cb);
            int t = min(t1, t2);
            cout << (sum + s[t]-s[i] + (t1 < t2? (rsb[t+1]) : (rsa[t+1]))) << " ";
            if(a[i] > b[i]) x--, sum += a[i];
            else y--, sum += b[i];
        }
    }
    cout << endl;
}