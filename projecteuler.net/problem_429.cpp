#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull
#define MOD 1000000009

int N;

int exponential_mod(int n, int p, int m) {
    if(p == 0) return 1;
    if(p&1) return (exponential_mod(n, p-1, m)*n)%m;
    int tmp = exponential_mod(n, p/2, m)%m;
    return (tmp*tmp)%m;
}

signed main() {
    N = 100000000;
    cin >> N;
    bool isP[N+10];
    memset(isP, 1, sizeof(isP));
    int ans = 1;
    for(int i = 2; i < N; i = (i&1)? i+2 : i+1) {
        if(!isP[i]) continue;
        for(int j = i+i; j <= N; j+=i){
            isP[j] = 0;
        }
        int tmp = N;
        int sum = 0;
        while(tmp) {
            sum += tmp/i;
            tmp/=i;
        }
        sum = exponential_mod(i, sum, MOD);
        ans *= (1+(sum*sum)%MOD)%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}



