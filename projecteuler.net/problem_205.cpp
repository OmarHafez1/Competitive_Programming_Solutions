#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> totals1, totals2;

void P(int ind, int sum) {
    if(ind == 9) {
        totals1.push_back(sum);
        return;
    }
    for(int i = 1; i <= 4; i++) {
        P(ind+1, sum+i);
    }
}

void C(int ind, int sum) {
    if(ind == 6) {
        totals2.push_back(sum);
        return;
    }
    for(int i = 1; i <= 6; i++) {
        C(ind+1, sum+i);
    }
}

signed main() {
    cout << fixed << setprecision(7);
    P(0, 0);
    C(0, 0);
    ll t = totals1.size() * totals2.size();
    sort(totals2.begin(), totals2.end());
    ll e = 0;
    for(auto &x : totals1) {
        int pos = lower_bound(totals2.begin(), totals2.end(), x)-totals2.begin();
        if(pos == totals2.size()) pos--;
        if(totals2[pos] >= x) pos--;
        e += pos+1;
    }
    cout << (round(e*1e7/t)/1e7);
}   
