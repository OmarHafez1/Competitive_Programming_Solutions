#include <bits/stdc++.h>
using namespace std;

bool seven_segment[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

int used_bits_count[10] = {0};
int trans[10][10] = {0};

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

int sam_clock(int n) {
    int res = 0;
    while(n) {
        res += used_bits_count[n%10];
        n/=10;
    }
    return res*2;
}

int last = -1;

int max_clock(int next) {
    if(last == -1) {
        last = next;
        return sam_clock(next)/2;
    }
    int a = last, b = next;
    int res = 0;
    while(a > 0 && b > 0) {
        res += trans[a%10][b%10];
        a/=10;
        b/=10;
    }
    if(a) res += sam_clock(a)/2;
    if(b) res += sam_clock(b)/2;
    last = next;
    return res;
}

int turn_max_clock_off() {
    if(last == -1) return 0;
    int res = sam_clock(last)/2;
    last = -1;
    return res;
}

int digitalRoot(int n) {
    int res = 0;
    while(n) {
        res += n%10;
        n /= 10;
    }
    return res;
}

signed main() {
    for(int i = 0; i <= 9; i++) {
        for(auto &b : seven_segment[i]) used_bits_count[i] += b;
    }
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int s = 0; s < 7; s++) {
                trans[i][j] += !!(seven_segment[i][s]^seven_segment[j][s]);
            }
        }
    }
    auto isP = primes_sieve(2e7+10);
    int ans = 0;
    for(int i = 1e7+1; i < 2e7; i+=2) {
        if(!isP[i]) continue;
        int x = i;
        int sam = 0, max = 0;
        int tmp = x;
        do {
            sam += sam_clock(tmp);
            max += max_clock(tmp);
            x = tmp;
        } while((tmp = digitalRoot(x)) != x);
        max += turn_max_clock_off();
        ans += abs(max-sam);
    }
    cout << ans;
}
