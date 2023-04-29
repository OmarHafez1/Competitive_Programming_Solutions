//============================================================================
// Author      : Omar_Hafez
// Created     : 28 September 2022 (Wednesday)  7:56:37 PM
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

#define ull unsigned long long

vector<vector<ull>> cut(vector<ull> &nums) {
    vector<vector<ull>> res(5);
     res[0] = {nums[0], nums[1], nums[2]};
    res[1] = {nums[3], nums[2], nums[4]};
    res[2] = {nums[5], nums[4], nums[6]};
    res[3] = {nums[7], nums[6], nums[8]};
    res[4] = {nums[9], nums[8], nums[1]};
    return res;
}

bool check(vector<vector<ull>> &ring) {
    ull tmp_count = 0;
    for(auto x : ring) {
        for(auto y : x) {
            if(y == 10) tmp_count++;
        }
    }
    if(tmp_count > 1) return 0;
    ull sum = ring[0][0]+ring[0][1]+ring[0][2];
    for(auto x : ring){
        if((x[0] + x[1] + x[2]) != sum) return 0;
    }
    return 1;
}

ull connect(vector<vector<ull>> &ring) {
    ull mn = ULLONG_MAX;
    int ind;
    int i = 0;
    vector<ull> tmp;
    for(auto x : ring) {
        ull res = 0;
        for(auto y : x) {
            if(y == 10) res *= 10;
            res *= 10;
            res += y;
        }
        if(res < mn) {
            mn = res;
            ind = i;
        }
        tmp.push_back(res);
        i++;
    }
    ull ans = mn;
    for(i = ind+1; i < tmp.size(); i++) {
        ans *= pow(10, to_string(tmp[i]).size());
        ans += tmp[i];
    }
    for(i = 0; i < ind; i++) {
        ans *= pow(10, to_string(tmp[i]).size());
        ans += tmp[i];
    }
    return ans;
}

int main() { 
    vector<ull> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ull ans = 0;
    do {
        vector<vector<ull>> ring = cut(nums);
        if(check(ring)) {
            ans = max(ans, connect(ring));
        }
    } while(next_permutation(nums.begin(), nums.end()));
    cout << ans;
}