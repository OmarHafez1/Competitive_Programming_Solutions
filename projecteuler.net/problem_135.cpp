//======================================================
// Author      : Omar_Hafez
// Created     : 22 December 2022 (Thursday)  8:21:25 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define int long long

int find_min_a(int z) {
    int left = 1, right = 1e9, mid;
    while(left < right) {
        mid = (left+right)/2;
        int a = 2*mid*z+3*mid*mid-z*z;
        if(a <= 0) {
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return right;
}

signed main() { 
    int N = 1000000;
    vector<int> vis(N+1);
    for(int z = 1; z < N; z++) {
        int a = find_min_a(z);
        int n = (z+2*a)*(z+2*a) - (z+a)*(z+a) - z*z;
        while(1) {
            n = (z+2*a)*(z+2*a) - (z+a)*(z+a) - z*z;
            if(n >= N) {
                break;
            }
            if(n < N)
                vis[n]++;
            a++;
        }
    }   
    int ans = 0; 
    for(int i = 1; i < N; i++) {
        if(vis[i] == 10) {
            ans++;
        }
    }
    cout << ans;
}
     
     