//============================================================================
// Author      : Omar_Hafez
// Created     : 12 April 2023 (Wednesday)  12:53:39 PM
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

using ui = unsigned int;
#define int ui
vector<int> sb(int n) {
    vector<int> res(4);
    int ind = 0;
    while(n) {
        res[ind++] = n%10;
        n/=10;
    }
    return res;
}

vector<int> sb3(int n) {
    vector<int> res(4);
    res[0] = n%10;
    n/=10;
    res[3] = n%10;
    return res;
}

signed main() { 

    int ans = 0;
    vector<vector<int>> b(4, vector<int>(4));

    for(int f1 = 0; f1 <= 9999; f1++) {
        b[0] = sb(f1);
        int s = b[0][0]+b[0][1]+b[0][2]+b[0][3];
        for(int f2 = 0; f2 <= 999; f2++) {
            b[1] = sb(f2);
            b[1][3] = s-(b[1][0]+b[1][1]+b[1][2]);
            if(b[1][3] > 9) continue;
            for(int f3 = 0; f3 <= 99; f3++) {
                b[2] = sb3(f3);

                b[3][0] = s-(b[0][0]+b[1][0]+b[2][0]);
                if(b[3][0] > 9) continue;
    
                b[3][3] = s-(b[0][3]+b[1][3]+b[2][3]);
                if(b[3][3] > 9) continue;

                b[2][1] = s-(b[0][3]+b[1][2]+b[3][0]);
                if(b[2][1] > 9) continue;

                b[2][2] = s-(b[0][0]+b[1][1]+b[3][3]);
                if(b[2][2] > 9) continue;

                b[3][1] = s-(b[0][1]+b[1][1]+b[2][1]);
                if(b[3][1] > 9) continue;

                b[3][2] = s-(b[0][2]+b[1][2]+b[2][2]);
                if(b[3][2] > 9) continue;

                if(b[3][0]+b[3][1]+b[3][2]+b[3][3] == s)
                    ans++;
            } 
        }
    }

    cout << ans;


}
