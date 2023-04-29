//======================================================
// Author      : Omar_Hafez
// Created     : 13 December 2022 (Tuesday)  3:17:46 PM
//======================================================
 

#include <bits/stdc++.h>
using namespace std;

vector<int> to = {0, 1, 2, 3, 4, 5};
vector<vector<vector<int>>> fnt(6, vector<vector<int>>(100));
vector<vector<vector<int>>> ed(6, vector<vector<int>>(100));
vector<int> all[6];

vector<int> ans;

int found = -1;

void dfs(int i, int val, int len) {
    if(found != -1) return;
    if(len == 6) {
        if(ans[5]%100 == ans[0]/100) {
            int sum = 0;
            for(auto x : ans) {
                sum += x;
            }
            found = sum;
            return;
        }
    }
    if(i >= 6) return;
    for(auto x : fnt[to[i]][val%100]) {
        ans.push_back(x);
        dfs(i+1, x, len+1);
        ans.pop_back();
    }
}


int main() { 
    for(int n = 1; ; n++) {
        int tmp = n*(n+1)/2;
        if(tmp > 9999) break;
        if(tmp < 1000) continue;
        all[0].push_back(tmp);
    } 

    for(int n = 1; ; n++) {
        int tmp = n*n;
        if(tmp > 9999) break;
        if(tmp < 1000) continue;
        all[1].push_back(tmp);
    }

    for(int n = 1; ; n++) {
        int tmp = n*(3*n-1)/2;
        if(tmp > 9999) break;
        if(tmp < 1000) continue;
        all[2].push_back(tmp);
    }

    for(int n = 1; ; n++) {
        int tmp = n*(2*n-1);
        if(tmp > 9999) break;
        if(tmp < 1000) continue;
        all[3].push_back(tmp);
    }

    for(int n = 1; ; n++) {
        int tmp = n*(5*n-3)/2;
        if(tmp > 9999) break;
        if(tmp < 1000) continue;
        all[4].push_back(tmp);
    }

    for(int n = 1; ; n++) {
        int tmp = n*(3*n-2);
        if(tmp > 9999) break;
        if(tmp < 1000) continue;
        all[5].push_back(tmp);
    }


    for(int i = 0; i < 6; i++) {
        for(auto x : all[i]) {
            fnt[i][x/100].push_back(x);
            ed[i][x%100].push_back(x);
        }
    }

    do {
        for(auto x : all[to[0]]) {
            ans.push_back(x);
            dfs(1, x, 1);
            ans.clear();
            if(found != -1) {
                cout << found;
                return 0;
            }
        }
    } while(next_permutation(to.begin(), to.end()));

}
     
     