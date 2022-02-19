/* 
**
**   author:  Omar_Hafez
**   created: 18/09/2021  02:07:50 PM
**
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono; 
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set_int;
typedef tree<unsigned int,null_type,less<unsigned int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set_ui;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set_ll;
typedef tree<unsigned long long,null_type,less<unsigned long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set_ull;
typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> indexed_set_db;
typedef tree<long double,null_type,less<long double>,rb_tree_tag,tree_order_statistics_node_update> indexed_set_ld;
typedef tree<string,null_type,less<string>,rb_tree_tag,tree_order_statistics_node_update> indexed_set_string;

const double PI = 3.141592653589793;
const int MOD = 1e9+7; 

//
using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using db = double; 

using pi = pair<int,int>;
using pll = pair<ll,ll>;
using pull = pair<ull, ull>;
using pdb = pair<db,db>;

using vi = vector<int>;
using vl = vector<long>;
using vb = vector<bool>;
using vll = vector<ll>;
using vull = vector<ull>;
using vld = vector<ld>;
using vdb = vector<db>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpll = vector<pll>; 
using vpull = vector<pull>;
using vpdp = vector<pdb>;

#define vec vector
#define lb lower_bound
#define ub upper_bound
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define popb pop_back()
#define popf pop_front()
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define len length()

// pairs & tuples
#define mp make_pair
#define mt make_tuple
#define fir first
#define sec second
#define tsize(t) tuple_size<decltype(t)>::value
#define tcat tuple_cat

// vectors
#define all(x) begin(x), end(x)
#define alll(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()  //C++17 
#define sor(x) sort(all(x)) 
#define sorr(x) sort(alll(x)) 
#define rsor(x) sort(all(x), greater<>()) 
#define rsorr(x) sort(alll(x), greater<>()) 
#define rsz(a, b) resize(distance(a, b))
#define eb emplace_back
#define shuffle(v) random_shuffle(all(v))
#define vmax(x) max_element(all(x))
#define vcnt(x, i) count(all(x), i)

// sets
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define ins insert
#define ers erase

#define iset_int indexed_set_int
#define iset_ui indexed_set_ui
#define iset_ll indexed_set_ll
#define iset_ull indexed_set_ull
#define iset_db indexed_set_db
#define iset_ld indexed_set_ld
#define iset_float indexed_set_float
#define iset_string indexed_set_string
#define key find_by_order
#define order order_of_key

// queue
#define qu queue
#define dqu deque
#define pqu priority_queue
#define pdqu(a) priority_queue<a,vector<a>,greater<a>>

// maps
#define umap unordered_map

// loops
#define f0r(i,a) for(int i = 0; i < (a); ++i)
#define f1r(i,a) for(int i = 1; i < (a); ++i)
#define foor(i,a,b) for(int i = (a); i < (b); ++i)
#define r0f(i,a) for(int i = (a)-1; i >= 0; --i)
#define rof(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define fe(a,x) for(auto& a: x)

// some hacks
#define endl '\n'
#define getline(a) getline(cin, a) 
#define newl cout<<endl;

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

// permutation 
#define n_perm next_permutation
#define p_perm prev_permutation 
#define vn_perm(x) next_permutation(all(x))
#define vp_perm(x) prev_permutation(all(x))

// fflush(stdout);
// cout << fixed << setprecision(10);

int main() { 
  ios_base::sync_with_stdio(false); cin.tie(NULL); 
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout); 

  string a[3];
  string t;
  cin >> a[0] >> a[1] >> a[2] >> t;
  string str = ""; 
  fe(ch, t) {
    str += a[(ch-'0')-1];
  }
  cout << str;
}
   