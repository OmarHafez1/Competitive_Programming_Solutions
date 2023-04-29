/* 
**
**   author:  Omar_Hafez
**   created: 16/01/2021  04:06:07 AM
**
*/
 
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
 
map<int, ull> dp;
ull solve(int n) {
    if(!n) return 0;
    if(dp[n]) return dp[n];
    ull m = solve(n/2) + solve(n/3) + solve(n/4);
    if(m < n)
       dp[n] = n; 
    else 
       dp[n] = m;
    return dp[n];
} 
 
int main() 
{ 
   ios_base::sync_with_stdio(false); cin.tie(NULL); 
   /*
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout); 
   */ 
 
   int n;
   while(cin >> n) {
      cout << solve(n) << endl;
   }
   
}
    