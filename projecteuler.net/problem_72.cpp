//======================================================
// Author      : Omar_Hafez
// Created     : 15 December 2022 (Thursday)  7:49:02 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

vector<int> low_prime(1000001);

vector<int> prime_factorization(int d) {
    vector<int> res;
    while(d > 1) {
        if(res.size() == 0 || res.back() != low_prime[d])
            res.push_back(low_prime[d]);
        d /= low_prime[d];       
    }
    return res;
}

int lcm(int a, int b) {
    return a*b/__gcd(a, b);
}

int calculate(int d) {
    vector<int> pf = prime_factorization(d);
    int res = d;
    for(auto x : pf) {
        res *= (1-1.0/x);
    }
    return res;
}

signed main() { 
    int n = 1000000;
    for(int i = 2; i <= n; i+=2) {
        low_prime[i] = 2;
    }
    int ls = 3;
    while(ls <= n) {
        if(low_prime[ls]) {
            ls++;
            continue;
        }
        for(int t = ls; t <= n; t+=ls) {
            low_prime[t] = ls;
        }
    }
    unsigned long long ans = 0;
    for(int d = 2; d <= n; d++) {
        ans += calculate(d);
    }
    cout << ans;
}

/*
  ▐ ▌  ▐ ▌
 ▐▌ ▐▌▐▌ ▐▌
 █▄▀▄██▄▀▄█
  ▄  ██▌ ▄
▄▀ █▀██▀█ ▀▄
▐▌▐▌ ▐▌ ▐▌▐▌
 ▐ █    █ ▌
    ▌  ▐
*/

     
     