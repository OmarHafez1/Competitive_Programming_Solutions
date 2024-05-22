#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll
 
#define endl '\n'
#define newl cout<<endl
 
#define EPS .0000001
#define MOD 1e9+7
 
int clc(char ch) {
    if(ch == 'A') return 0;
    if(ch == 'C') return 1;
    if(ch == 'G') return 2;
    return 3;
}
 
signed main() {
    char chs[4] = {'A', 'C', 'G', 'T'};
    string s;
    cin >> s;
    int n = s.size();
    bool a[4] = {0};
    for(int i = 0; i < n; i++) {
        a[clc(s[i])] = 1;
        if(a[0] & a[1] & a[2] & a[3]) {
            cout << s[i];
            memset(a, 0, sizeof(a));
        }
    }  
    for(int i = 0; i < 4; i++) {
        if(!a[i]) {
            cout << chs[i];
            return 0;
        }
    }
}