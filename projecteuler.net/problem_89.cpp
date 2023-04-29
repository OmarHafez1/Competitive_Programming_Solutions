//============================================================================
// Author      : Omar_Hafez
// Created     : 24 November 2022 (Thursday)  5:29:34 PM
//============================================================================

 /*   
                ________
               /        \
              / /      \ \
     ________/ /        \ \________
    /        \            /        \ 
   / /      \ \  ______  / /      \ \
  / /        \ \________/ /        \ \ 
  \            /        \            /
   \  ______  / /      \ \  ______  /    
    \________/ /        \ \________/
    /        \            /        \
   / /      \ \  ______  / /      \ \   
  / /        \ \________/ /        \ \
  \            /        \            /    
   \  ______  / /      \ \  ______  /
    \________/ /        \ \________/
             \            /     
              \  ______  / 
               \________/ 

*/

#include <bits/stdc++.h>
using namespace std;

map<string, int> mpstr;
map<int, string> mpint;
vector<int> nums;

int calc(string s) {
    int ret = 0;
    int sz = s.size();
    for(int i = 0; i < sz; i++) {
        string tmp;
        tmp += s[i];
        if(i+1 < sz) {
            tmp += s[i+1];
            if(mpstr[tmp]) {
                ret += mpstr[tmp];
                i++;
                continue;
            } 
            tmp.pop_back();
        } 
        ret += mpstr[tmp];
    }
    return ret;
}

string roman(int n) {
    string ret;
    for(auto x : nums) {
        while(n >= x) {
            n -= x;
            ret += mpint[x];
        }
    }
    return ret;
}

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    string s;

    mpstr["I"] = 1;
    mpstr["V"] = 5;
    mpstr["X"] = 10;
    mpstr["L"] = 50;
    mpstr["C"] = 100;
    mpstr["D"] = 500;
    mpstr["M"] = 1000;
    mpstr["IV"] = 4;
    mpstr["IX"] = 9;
    mpstr["XL"] = 40;
    mpstr["XC"] = 90;
    mpstr["CD"] = 400;
    mpstr["CM"] = 900;

    for(auto x : mpstr) {
        mpint[x.second] = x.first;
        nums.push_back(x.second);
    }
    sort(nums.begin(), nums.end(), greater<>());

    int ans = 0;
    while(cin >> s) {
        if(s == "END") break;
        ans += s.size()-roman(calc(s)).size();
    }
    cout << ans;
    
}

/*
  ▐ ▌  ▐ ▌
 ▐▌ ▐▌▐▌ ▐▌
 █▄▀▄██▄▀▄█
  ▄  ██▌ ▄
▄▀ █▀██▀█ ▀▄
▐▌▐▌ ▐▌ ▐▌▐▌
 ▐ █    █ ▌
    ▌  ▐
*/
