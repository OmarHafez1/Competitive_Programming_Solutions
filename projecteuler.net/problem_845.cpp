#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ull

int cnt[10];
int limit[100];
int N;

int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (int)round(exp(res));
}

int combo(int n) {
    int tot = n, res = 1;
    for(int i = 0; i < 10; i++) {
        res *= nCr(tot, cnt[i]);
        tot -= cnt[i];
    }
    return res;
}

int calc(int ind) {
    if(ind == N) return 1;
    int res = 0;
    if(cnt[limit[ind]] > 0) {
        cnt[limit[ind]]--;
        res = calc(ind+1);
        cnt[limit[ind]]++;
    }
    for(int d = 0; d < limit[ind]; d++) {
        if(cnt[d] == 0) continue;
        cnt[d]--;
        res += combo(N-ind-1);
        cnt[d]++;
    }
    return res;
}
vector<bool> isPrime;

int prime_digit_sum(int ind, int d, int sum) {
    if(ind == N) {
        if(!isPrime[sum]) return 0;
        return calc(0);
    }
    if(d > 9) return 0;
    int res = prime_digit_sum(ind, d+1, sum);
    cnt[d]++;
    res += prime_digit_sum(ind+1, d, sum+d);
    cnt[d]--;
    return res;
}

int solve(int n) {
    N = (int)log10(n)+1;
    for(int i = N-1; ~i; i--) {
        limit[i] = n%10;
        n /= 10;
    }
    return prime_digit_sum(0, 0, 0);
}

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
    memset(cnt, 0, sizeof(cnt));
    isPrime = primes_sieve(1e5);
    int target = 1e16;
    int left = 1e12, right = 1e18, mid, ans = -1;
    while(left <= right) {
        mid = (left+right)/2;
        int tmp = solve(mid);
        if(tmp == target) {
            ans = mid;
            right = mid-1;
        } else if(tmp < target) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    cout << ans;
}  
