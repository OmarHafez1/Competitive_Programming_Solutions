#include <bits/stdc++.h>
using namespace std;

signed main() {
    // 4*1 4*3 4*5 4*7 4*9
    // 1 4*2 4*4 4*6 4*8

    vector<int> cnt(10000000+5);
    vector<int> four = {4}, one = {1};
    for(int i = 4+8; i <= 1e6; i+=8) {
        four.push_back(four.back()+i);
        for(int j = four.size()-2; ~j; j--) {
            if(four.back()-four[j] > 1e6) break;
            cnt[four.back()-four[j]]++;
        }
    }
    for(int i = 8; i <= 1e6; i+=8) {
        one.push_back(one.back()+i);
        for(int j = one.size()-2; ~j; j--) {
            if(one.back()-one[j] > 1e6) break;
            cnt[one.back()-one[j]]++;
        }
    }
    int ans = 0;
    for(auto &x : cnt) {
        if(x <= 10 && x >= 1) ans++;
    }
    cout << ans;
}   