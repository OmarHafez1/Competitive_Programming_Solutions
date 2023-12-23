#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
#define int ull

map<int, bool> mp;

bool isPrime(ull n) {
    if(mp.count(n)) {
        return mp[n];
    }
    if(n == 2 || n == 5) return 1;
    if (n < 2 || n%2 == 0 || n%5 == 0) 
    return mp[n] = 0;
    for(ull i = 3; i*i <= n; i+=2) {
    if(n%i == 0) return mp[n] = 0;
    }
    return mp[n] = 1;
}

int getSum(int n) {
    int k = n;
    int sum = 0;
    while(k) {
        sum += k%10;
        k /= 10;
    }
    return sum;
}

bool isHarshed(int n) {
    return (n%getSum(n) == 0);
}

bool isStrongHarshed(int n) {
    return isPrime(n/getSum(n));
}


int ans = 0;
#define LIMIT 100000000000000

void dfs(int n) {
    for(int i = 0; i < 10; i++) {
        if(n*10+i >= LIMIT) return;
        if(isHarshed(n*10+i)) {
            dfs(n*10+i);
        } else if(i&1) {
            if(isStrongHarshed(n) && isPrime(n*10+i)) {
                ans += n*10+i;
            }
        }
    }
}

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    for(int i = 1; i <= 9; i++) {
        dfs(i);
    }
    cout << ans;

}
     
     