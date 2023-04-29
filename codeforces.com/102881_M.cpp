//======================================================
// Author      : Omar_Hafez
// Created     : 28 April 2023 (Friday)  11:09:33 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    freopen("lis.in", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    string s;
    cin >> s;
    int n = s.size()-1;
    ull ans = n*9;
    ans += (s[0]-'1');
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != '9') {
            cout << ans;
            return 0;
        }
    }
    cout << ans+1;
}
     
     