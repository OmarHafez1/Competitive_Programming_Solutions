//======================================================
// Author      : Omar_Hafez
// Created     : 24 December 2022 (Saturday)  11:43:50 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define ld long double

#define point complex<ld>
#define c_vec(a,b) (b)-(a)
#define c_dp(a,b) (conj(a)*(b)).real() // a*b cos(T), if zero -> prep


bool ok(int x1, int y1, int x2, int y2) {
    if(x1 > x2) return 0;
    if(x1 == x2) {
        if(y1 > y2) return 0;
    }
    if(x1 == 0 && y1 == 0) return 0;
    if(x2 == 0 && y2 == 0) return 0;
    if(x1 == x2 && y1 == y2) return 0;
    point p0(0, 0);
    point p1(x1, y1);
    point p2(x2, y2);
    if(c_dp(c_vec(p0, p1), c_vec(p0, p2))  == 0) return 1;
    if(c_dp(c_vec(p0, p1), c_vec(p1, p2))  == 0) return 1;
    if(c_dp(c_vec(p0, p2), c_vec(p1, p2))  == 0) return 1;
    return 0;
}

int main() { 
    int n;
    cin >> n;
    int ans = 0;
    for(int x1 = 0; x1 <= n; x1++) {
        for(int x2 = 0; x2 <= n; x2++) {
            for(int y1 = 0; y1 <= n; y1++) {
                for(int y2 = 0; y2 <= n; y2++) {
                    ans += ok(x1, y1, x2, y2);
                }
            }
        }
    }
    cout << ans; 
}