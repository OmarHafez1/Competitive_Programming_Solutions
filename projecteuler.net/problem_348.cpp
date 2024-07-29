#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

set<int> st;
map<int, int> mp;

bool isPlaindromic(int n) {
    string s = to_string(n);
    for(int i = 0; i < s.size()/2; i++) {
        if(s[i] != s[s.size()-i-1]) return 0;
    }
    return 1;
}

signed main() {
    for(int a = 2; a <= 100000; a++) {
        for(int b = 2; a*a+b*b*b < 1e9; b++) {
            if(!isPlaindromic(a*a+b*b*b)) continue;
            st.insert(a*a+b*b*b);
            mp[a*a+b*b*b]++;
        }
    }
    int ans = 0, cnt = 5;
    for(auto &x : st) {
        if(mp[x] == 4) {
            ans += x;
            cnt--;
        }
        if(cnt == 0) break;
    }
    cout << ans;
}   

