#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ull unsigned long long
#define int ull

signed main() {
    // a(n) = a(n-1) + a(n-2) + A000045(n-2).
    // 0, 1, 2, 3, 6, 11, 20, 36, 64, 113, 198, 345, 598, 1032, 1774, 3039, 5190, 8839, 15016, 25452, 43052, 72685, 122502, 206133, 346346, 581136, 973850, 1630011, 2725254, 4551683, 7594748, 12660660, 21087448, 35094377, 58360134, 96979089, 161042110, 267248664

    int fab[101];
    int seq[101];
    fab[0] = 0;
    fab[1] = 1;
    for(int i = 2; i <= 100; i++) {
        fab[i] = fab[i-1]+fab[i-2];
    }
    seq[0] = 0; seq[1] = 1; seq[2] = 2; seq[3] = 3;
    for(int i = 4; i <= 100; i++) {
        seq[i] = seq[i-1]+seq[i-2]+fab[i-2];
    }
    int ans = 0, n;
    
    cin >> n;
    int left = 0, right = 100, mid, m;
    while(left <= right) {
        mid = (left+right)/2;
        if(fab[mid] == n) {
            m = mid;
            break;
        } else if(fab[mid] > n) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    
    for(int i = 1; i < m; i++) {
        ans += seq[i];
    }
    cout << ans;
}   

