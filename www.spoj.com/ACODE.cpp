/* 
**
**   author:  Omar_Hafez
**   created: 17/01/2021  04:42:18 AM
**
*/
 
/*#include <iostream> 
#include <iomanip>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <chrono>
#include <cmath>
#include <cassert>
#include <complex>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <unistd.h>
#include <queue>
#include <list>
#include <random>
#include <bitset>
#include <fstream>
#include <limits>*/
 
#include <bits/stdc++.h>
using namespace std;
using namespace chrono; 
 
const double PI = 3.141592653589793;
 
//
using ll = long long;
using ld = long double;
using db = double; 
using ui = unsigned int;
using ull = unsigned long long;
 
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using pdb = pair<db,db>;
 
using vi = vector<int>;
using vl = vector<long>;
using vb = vector<bool>;
using vll = vector<ll>;
using vdb = vector<db>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpll = vector<pll>; 
 
// pairs
#define mp make_pair
#define f first
#define s second
 
// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
// loops
#define f0r(i,a) for (int i = 0; i < (a); ++i)
#define foor(i,a,b) for (int i = (a); i < (b); ++i)
#define r0f(i,a) for (int i = (a)-1; i >= 0; --i)
#define rof(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define fe(a,x) for (auto& a: x)
 
// some hacks
#define endl '\n'
 
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
 
// some math
#define sinDegrees(x) sin((x) * PI / 180.0)
#define cosDegrees(x) cos((x) * PI / 180.0)
#define tanDegrees(x) tan((x) * PI / 180.0)
#define asinDegrees(x) asin(x)* 180.0 / PI
#define acosDegrees(x) acos(x)* 180.0 / PI
#define atanDegrees(x) atan(x)* 180.0 / PI
 
// bits
#define cnt_1s(b) __builtin_popcount(b)
#define begin_0s(b) __builtin_clz(b) 
#define end_0s(b) __builtin_ctz(b) 
#define ffno(b) find_first_not_of(b) 
 
map<string, ull> dp;
ull solve(string str) {
    if(dp[str]) return dp[str];
    ull res = 0;
    if(str.length() < 2) return 0;
    if(str[1] != '0')
        res += solve(str.substr(1));
    if(str[2] != '0')
        if(((str[0]-'0')*10+(str[1]-'0')) < 27) {
            if(str[1] == '0')
                res--;
            res += solve(str.substr(2))+1;
        }
    dp[str] = res;
    return res;
} 
 
int main() 
{ 
   ios_base::sync_with_stdio(false); cin.tie(NULL); 
   /*
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout); 
   */ 
 
   string n;
   while(cin >> n) {
      if(n == "0") return 0;
      cout << solve(n)+1 << endl;
   }
   
}