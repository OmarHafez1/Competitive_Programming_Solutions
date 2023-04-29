//======================================================
// Author      : Omar_Hafez
// Created     : 20 December 2022 (Tuesday)  8:31:22 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

vector<int> lm(100001);

vector<int> factorize(int n) {
    vector<int> res;
    while(n > 1) {
        if(res.size() == 0 || lm[n] != res.back())
            res.push_back(lm[n]);
        n/=lm[n];
    }
    return res;
}

int rad(int n) {
    int res = 1;
    for(auto x : factorize(n)) {
        res *= x;
    }
    return res;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    lm[1] = 1;
    for(int i = 2; i < lm.size(); i+=2) {
        lm[i] = 2;
    }
    for(int i = 3; i < lm.size(); i+=2) {
        if(lm[i]) continue;
        for(int j = i; j < lm.size(); j += i) {
            lm[j] = i;
        }
    }

    vector<pair<int, int>> ans;
    for(int i = 1; i <= 100000; i++) {
        ans.push_back({rad(i), i});
    }
    sort(ans.begin(), ans.end());
    cout << ans[10000-1].second;
}
     
     