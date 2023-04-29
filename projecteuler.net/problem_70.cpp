//======================================================
// Author      : Omar_Hafez
// Created     : 15 December 2022 (Thursday)  9:26:56 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

int N = 1e7;
vector<int> lp(N+1);

vector<int> prime_factorization(int n) {
    vector<int> res;
    while(n > 1 && n >= lp[n]) {
        if(res.size() == 0 || res.back() != lp[n]) {
            res.push_back(lp[n]);
        }
        n /= lp[n];
    }
    return res;
}

int phi(int n) {
    int res = n; 
    for(auto x : prime_factorization(n)) {
        res *= (1-1.0/x);
    }
    return res;
}

bool permutaion(int a, int b) {
    string sa = to_string(a);
    string sb =  to_string(b);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    return (sa == sb);
}

int main() { 
    for(int i = 2; i < N; i+=2) {
        lp[i] = 2;
    }
    for(int i = 3; i < N; i+=2) {
        if(lp[i]) continue;
        int tmp = i;
        while(tmp < N) {
            lp[tmp] = i;
            tmp += i;
        }
    }
    long long ans_n = 2, ans_phi = 1;
    for(int n = 2; n < N; n++) {
        int tmp = phi(n);
        if(permutaion(tmp, n)) {
            if(n*ans_phi < ans_n*tmp) {
                ans_n = n;
                ans_phi = tmp;
            }
        }
    }
    cout << ans_n;
}
     
     