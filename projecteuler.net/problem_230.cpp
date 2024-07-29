#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

int fab[81];
string a = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
string b = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";

int calc(int n, int ind) {
    if(ind == 0) return (a[n-1]-'0');
    if(ind == 1) return (b[n-1]-'0');
    if(n > fab[ind]) return calc(n, ind-1);
    if(n > fab[ind-2]) return calc(n-fab[ind-2], ind-1);
    return calc(n, ind-2);  
}

signed main() {
    fab[0] = 100;
    fab[1] = 100;
    for(int i = 2; i <= 80; i++) {
        fab[i] = fab[i-1]+fab[i-2];
    }
    int ans = 0;
    for(int n = 0; n <= 17; n++) {
        ans += calc((127+19*n)*(int)pow(7, n), 80)*(int)pow(10, n);
    }
    cout << ans;
}
