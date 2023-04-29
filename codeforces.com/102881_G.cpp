//======================================================
// Author      : Omar_Hafez
// Created     : 28 April 2023 (Friday)  11:09:33 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define endl '\n'

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    freopen("collectingofficer.in", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    
    int q;
    cin >> q;
    ull l, r;
    ull gd = 0;
    for(int i = 0; i < q; i++) {
        cin >> l >> r;
        if(gd == 0) gd = l;
        while(l <= r && gd > 1) {
            gd = __gcd(gd, l);
            l++;
        }
        cout << gd << endl;
    }
}
     
     