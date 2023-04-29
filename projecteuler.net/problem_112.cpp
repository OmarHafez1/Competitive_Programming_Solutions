//======================================================
// Author      : Omar_Hafez
// Created     : 28 September 2022 (Wednesday)  6:26:32 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    string s = to_string(n);
    bool low = 1, high = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] > s[i-1]) {
            low = 0;
        }
        if(s[i] < s[i-1]) {
            high = 0;
        }
        if(!low && !high) return 1;
    }
    return 0;
}

int main() { 
    int p = 99;
    int n = 100;
    int cnt = 0;
    while(cnt*100 != p*n) {
        n++;
        if(check(n)) cnt++;
    }
    cout << n;
}

     
     