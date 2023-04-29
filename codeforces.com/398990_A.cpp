//======================================================
// Author      : Omar_Hafez
// Created     : 15 September 2022 (Thursday)  5:02:42 AM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> ans;
int k;
char ch1, ch2;
void calc(char m, vector<char> res) {
    if(res.size() == k) {
        ans.push_back(res);
        return;
    }
    for(char i = m; i <= ch2; i++) {
        res.push_back(i);
        calc(i+1, res);
        res.pop_back();
    }   
}
signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    cin >> k >> ch1 >> ch2;
    vector<char> res;
    calc(ch1, res);
    cout << ans.size() << endl;
    for(auto &x : ans) {
        for(auto &y : x) {
            cout << y;
        }
        cout << '\n';
    }
}