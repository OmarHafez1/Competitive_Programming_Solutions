#include <bits/stdc++.h>
using namespace std;

int calc(int p, int len) {
    return pow(2, p-(int)(log10(2)*p-len+1)*log2(10));
}

int p(int x, int r) {
    int ind = 0, cnt = 0;
    while(cnt != r) {
        ind++;
        if(calc(ind, floor(log10(x))+1) == x) cnt++;
    }
    return ind;
}

int main() {
    // 2^p / 10 ^ (log10(2)*p-1)
    // p - (log10(2)*p-1)*log(10)

    int x, r;
    cin >> x >> r;
    cout << p(x, r);

}   

