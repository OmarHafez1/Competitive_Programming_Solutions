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

vector<int> a;
int odds[91];

int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (int)round(exp(res));
}

int calc(int n, bool z) {
    int ds[10];
    memset(ds, 0, sizeof(ds));
    while(n) {
        ds[n%10]++;
        n/=10;
    }
    int res = 1;
    int rem = 10;
    for(int i = 0; i <= 9; i++) {
        if(ds[i] == 0) continue;
        res *= nCr(rem, ds[i]);
        rem -= ds[i];
    }
    if(!z) return res;
    if(ds[0] > 0) {
        int tmp = 1;
        rem = 10-1;
        ds[0]--;
        for(int i = 0; i <= 9; i++) {
            if(ds[i] == 0) continue;
            tmp *= nCr(rem, ds[i]);
            rem -= ds[i];
        }
        res -= tmp;
    }
    return res;
}

int ans = 0;

void count(int ind, int d, int n, int sum) {
    if(ind == 0) { 
        if((sum-(90-sum))%11 == 0) {
            int m = 0;
            int ds[10];
            memset(ds, 0, sizeof(ds));
            int tmp = n;
            while(tmp) {
                ds[tmp%10]++;
                tmp/=10;
            }
            for(int i = 9; ~i; i--) {
                if(ds[i] == 2) continue;
                if(ds[i] == 1) m = m*10+i;
                else {
                    m = m*100+i*10+i;
                }
            }
            ans += calc(n, 1)*calc(m, 0);
        }
        return;
    }
    if(d < 0 || ind < 0) return;
    count(ind, d-1, n, sum);
    count(ind-1, d-1, n*10+d, sum+d);
    count(ind-2, d-1, n*100+d*10+d, sum+2*d);
}  

signed main() {
    count(10, 9, 0, 0);
    cout << ans;
}   

