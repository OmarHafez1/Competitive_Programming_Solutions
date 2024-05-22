#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define int ull

signed main() {
    for(int i = 1000001; ; i+=2) {
        if(i%5 == 0) continue;
        int Rkm = 1;
        int ln = 2;
        while(Rkm) {
            Rkm = Rkm*10+1;
            Rkm%=i;
            ln++;
        }
        if(ln > 1000000) {
            cout << (ull)i;
            return 0;
        }
    }
    cout << "NOT FOUND";
}
