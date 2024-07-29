#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define endl '\n'

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define EPS .0000001
#define MOD 1e9+7
#define PI 3.14159265358979323846

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define rsor(x) sort(all(x), greater<>())

#define uset unordered_set
#define mset multiset
#define umset unordered_multiset

template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;

void calculate();

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
    }
}

int a[33];
void go(int n) {
	for(int i = 0; i < 32; i++) {
		if(n & (1 << i)) {
			a[i] = 1;
		}
	}
}

void calculate() {
    int n;
    memset(a, 0, sizeof(a));
    cin >> n;
   	go(n);
   	int carry = 0;
   	for(int i = 0; i < 31; i++) {
   		if(carry && a[i] > 0) {
   			a[i] = 0;
   			continue;
   		} 
   		if(carry) {
   			a[i] = 1;
   			carry--;
   			i = 0;
   			continue;
   		}
   		if(a[i] != 0 && a[i+1] != 0) {
   			a[i] = -1; a[i+1] = 0;
   			carry++;
   			i++;
   		}
   	}
   	int r = 31;
   	while(r--) {
   		if(a[r] != 0) break;
   	}
   	cout << r+1 << endl;
   	for(int i = 0; i < r+1; i++) {
   		cout << a[i] << " ";
   	}
   	cout << endl;
}

/* 

	27

 1  2  4  8  16  32
 1  1     1  1
 -1 0  1  1  1
 -1 0 -1  0  0   1
*/