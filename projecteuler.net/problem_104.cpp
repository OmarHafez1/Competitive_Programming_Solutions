//======================================================
// Author      : Omar_Hafez
// Created     : 22 December 2022 (Thursday)  8:20:51 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;


string add(string a, string b) {
    if(a.size() < b.size()) swap(a, b); 
    int bs = b.size(), as = a.size();
    int car = 0;
    bs--;
    as--;
    while(bs >= 0) {
        int tmp = car + (a[as]-'0' + b[bs]-'0');
        a[as] = tmp%10 + '0';
        tmp/=10;
        car = tmp;
        bs--;
        as--;
    }
    while(as >= 0 && car > 0) {
        int tmp = car + a[as]-'0';
        a[as] = tmp%10 + '0';
        tmp/=10;
        car = tmp;
        as--;
    }
    if(car > 0) {
        a = to_string(car) + a;
    }
    return a;
}

bool ok(string c) {
    if(c.size() < 9) return 0;
    vector<bool> vis(10);
    for(int i = c.size()-1; i >= c.size()-9; i--) {
        if(c[i] == '0') return 0;
        if(vis[c[i]-'0']) return 0;
        vis[c[i]-'0'] = 1;
    }
    vis = vector<bool>(10, 0);
    for(int i = 0; i < 9; i++) {
        if(c[i] == '0') return 0;
        if(vis[c[i]-'0']) return 0;
        vis[c[i]-'0'] = 1;
    }
    return 1;
}

signed main() { 
    string a = "1", b = "1", c = "";
    int cnt = 2;
    while(!ok(c)) {
        cnt++;
        c = add(a, b);
        a = b;
        b = c;
    }
    cout << cnt;
}
     
     