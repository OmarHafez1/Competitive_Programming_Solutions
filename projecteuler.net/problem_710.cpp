#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000

signed main() {
    int even = 1, odd = 0;
    int lstE1 = 0, lstE2 = 1, tmp;
    int lstO1 = 0, lstO2 = 0;
    int pw = 1;
    for(int i = 4; ; i+=2) {
        tmp = even - lstE1 + pw;
        tmp = (tmp+MOD)%MOD;
        if(tmp == 0) {
            cout << i << endl;
            return 0;
        }
        lstE1 = lstE2;
        lstE2 = tmp;
        even += tmp;
        even %= MOD;
        tmp = odd - lstO1 + pw;
        tmp = (tmp+MOD)%MOD;
        if(tmp == 0) {
            cout << i+1 << endl;
            return 0;
        }
        lstO1 = lstO2;
        lstO2 = tmp;
        odd += tmp;
        odd %= MOD;
        pw *= 2;
        pw %= MOD;
    }
 }
