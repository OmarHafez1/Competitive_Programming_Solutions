#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define endl '\n'

#define EPS .0000001
#define MOD 1e9+7

void calculate();

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

void calculate() {
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> mp;
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        mp[a[i]]++;
    }
    vector<int> tmp;
    for(auto &x : st) {
        tmp.push_back(mp[x]);
    }
    sort(tmp.begin(), tmp.end());
    while(tmp.back() >= k) {
        int x = tmp.back();
        tmp.pop_back();
        if(tmp.size() == 0) tmp.push_back(x-1);
        else tmp.back() += (x-1);
    }
    int rem = 0;
    for(auto &x : tmp) rem+=x;
    cout << rem << endl;
}