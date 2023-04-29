//======================================================
// Author      : Omar_Hafez
// Created     : 28 April 2023 (Friday)  11:09:33 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define endl '\n'

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    freopen("abc.in", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    
    int n;
    string s;
    cin >> n >> s;
    string store = s;
    int a = 0, b = 0, c = 0;
    vector<int> ia, ic, ib;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') { 
            a++;
            ia.push_back(i);
        }
        else if(s[i] == 'b') {
            b++;
            ib.push_back(i); 
        }
        else {
            c++;
            ic.push_back(i);
        }
    }
    if(a == 0 || c == 0) {
        cout << 0;
        return 0;
    }
    if(b == 0) {
        cout << -1;
        return 0;
    }
    int ans1 = 0, ans2 = 0;
    int t1333 = ib[0];
    bool sss = 0;
    if(ib[0] != a) {
        if(s[a] == 'a') {
            sss = 1;
            swap(ib[0], ia[0]);
        }
        swap(s[a], s[t1333]);
        ans1++;
    }    
    for(int i = 0; i < a; i++) {
        if(s[i] != 'a') {
            ans1++;
        }
    } 
    if(sss) {
        swap(ib[0], ia[0]);
    }
    s = store;

    if(ib[0] != c) {
        if(s[c] == 'a') {
            sss = 1;
            swap(ib[0], ic[0]);
        }
        swap(s[c], s[t1333]);
        ans2++;
    }    
    for(int i = 0; i < c; i++) {
        if(s[i] != 'c') {
            ans2++;
        }
    }
    cout << min(ans1, ans2);
}
     
 