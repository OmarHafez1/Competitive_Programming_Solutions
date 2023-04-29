//======================================================
// Author      : Omar_Hafez
// Created     : 28 April 2023 (Friday)  11:09:33 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define int ll
#define endl '\n'

int a[100001], b[100001];
int n;

bool ok(int t) {
    int lst = a[0]+t*b[0];
    for(int i = 1; i < n; i++) {
        if(a[i]+t*b[i] < lst) return 0;
        lst = a[i]+t*b[i];
    }
    return 1;
}

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    freopen("plants.in", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    
    cin >> n;
    bool done = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i) {
            if(a[i] < a[i-1]) {
                done = 0;
            }
        }
    }
    if(done) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int mx = b[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1] && b[i] <= mx) {
            cout << -1;
            return 0;
        }
        if(a[i] == a[i-1] && b[i] == mx) {
            cout << -1;
            return 0;
        }
        mx = max(mx, b[i]);
    }
    int tmp = n;
    for(int i = 1; i < n; i++) {
        if(b[i] < b[i-1]) {
            n = i;
        }
    }
    int l = 0, r = 2e9, mid;
    while(l < r) {
        mid = (l+r)/2;
        if(ok(mid)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    n = tmp;
    cout << (ok(r)? r : -1);
}
     
     /*
    
        2 3 1 4
        1 2 4 3

     */