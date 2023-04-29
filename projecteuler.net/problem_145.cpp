//======================================================
// Author      : Omar_Hafez
// Created     : 15 December 2022 (Thursday)  10:20:53 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

bool ok(int n) {
    int m = 0;
    int sum = n;
    while(n) {
        m *= 10;
        m += n%10;
        if(m == 0) {
            return 0;
        }
        n/=10;
    }
    sum += m;
    while(sum) {
        if((sum%10)%2 == 0) return 0;
        sum /= 10;
    }
    return 1;
}

signed main() { 
    int ans = 0;
    for(int i = 1; i < 1000000000; i++) {
        if(ok(i)) ans++;
    }
    cout << ans;
}
    
     