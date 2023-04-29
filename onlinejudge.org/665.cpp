//============================================================================
// Author      : Omar_Hafez
// Created     : 05 September 2022 (Monday)  12:55:07 AM
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono; 
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using indexed_mset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define int long long

const double PI = 3.141592653589793;
const int MOD = 1e9+7; 
const int INF = 1e9;

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
#define pushb(a) push_back(a)
#define pushf(a) push_front(a)
#define popb pop_back()
#define popf pop_front()

// pairs & tuples
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
#define uniq(x) x.resize(unique(all(x)) - x.begin())

// sets
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define ins insert
#define ers erase

#define key find_by_order
#define order order_of_key

// queue
#define qu queue
#define dqu deque
#define pqu priority_queue
template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;

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
#define getline(a) scanf("%[^\n]%*c", a);
#define newl cout<<endl;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define y0 this_fix_bug_with_y0_2022
#define y1 this_fix_bug_with_y1_2022
#define y2 this_fix_bug_with_y2_2022
#define y3 this_fix_bug_with_y3_2022
#define y4 this_fix_bug_with_y4_2022

// some math
#define point complex<ld>
#define degree(x) (x) * 180.0 / PI
#define radian(x) (x) * PI / 180.0
#define sinDegrees(x) sin(radian(x))
#define cosDegrees(x) cos(radian(x))
#define tanDegrees(x) tan(radian(x))
#define asinDegrees(x) dgeree(asin(x))
#define acosDegrees(x) degree(acos(x))
#define atanDegrees(x) degree(atan(x))
#define EPS 1e-8
#define is_same(a, b) (fabs(a-b) <= EPS)

// some complex
#define point complex<ld>
#define c_angle(a) (atan2((a).imag(), (a).real()))
#define c_vec(a,b) (b)-(a)
#define c_dp(a,b) (conj(a)*(b)).real() // a*b cos(T), if zero -> prep
#define c_cp(a,b) (conj(a)*(b)).imag()  // a*b sin(T), if zero -> parllel
#define c_same(p1,p2) (c_dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define c_length(a) (hypot((a).imag(), (a).real()))
#define c_distance(a, b, c) fabs(c_cp(a-b, a-c)/c_length(a-b))
#define c_normalize(a) (a)/c_length(a)
#define c_rotateO(p,ang) ((p)*exp(point(0,ang)))
#define c_rotateA(p,ang,about) (c_rotateO(vec(about,p),ang)+about)
#define c_reflectO(v,m) (conj((v)/(m))*(m))

// bits
#define cnt_1s(b) __builtin_popcountll(b)
#define begin_0s(b) __builtin_clzll(b) 
#define end_0s(b) __builtin_ctzll(b) 
#define ffno(b) find_first_not_ofll(b) 

// permutation 
#define n_perm next_permutation
#define p_perm prev_permutation 
#define vn_perm(x) next_permutation(all(x))
#define vp_perm(x) prev_permutation(all(x))

void calculate();

// fflush(stdout);
// cout << fixed << setprecision(10);

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 

    int t;
    cin >> t;
    while(t--) {
        calculate();
        newl;
        if(t)
            newl;
    }
}


void calculate() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> big, small;
    char ch;
    int p;
    vector<bool> vis(120, 1);
    vector<int> cnt(120);
    for(int i = 0; i < k; i++) {
        cin >> p;
        vector<int> a(p), b(p);
        for(int j = 0; j < p; j++) {
            cin >> a[j];
        }
        for(int j = 0; j < p; j++) {
            cin >> b[j];
        }
        cin >> ch;
        if(ch == '=') {
            for(int j = 0; j < p; j++) {
                vis[a[j]] = 0;
                vis[b[j]] = 0;
            } 
        } else if(ch == '>') {
            big.push_back(a);
            small.push_back(b);
        } else {
            big.push_back(b);
            small.push_back(a);
        }
    }
    int sus = 0;
    for(int i = 1; i <= n; i++) {
        sus += vis[i];
    }
    if(sus == 1) {
        for(int i = 1; i <= n; i++) {
            if(vis[i]) {
                cout << i;
                return;
            }
        }
    }
    for(int i = 0; i < big.size(); i++) {
        int lft = 0, rt = 0;
        for(int j = 0; j < big[i].size(); j++) {
            lft += vis[big[i][j]];
            rt += vis[small[i][j]];
        }
        if(lft == 1 && rt == 0) {
            for(int j = 0; j < big[i].size(); j++) {
                if(vis[big[i][j]]) {
                    cout << big[i][j];
                    return;
                }
            }
        }
        if(rt == 1 && lft == 0) {
            for(int j = 0; j < big[i].size(); j++) {
                if(vis[small[i][j]]) {
                    //
                    cout << small[i][j];
                    return;
                }
            }
        }
        for(int j = 0; j < big[i].size(); j++) {
            cnt[big[i][j]]++;
            cnt[small[i][j]]--;
        }
    }
    if(big.size() < sus*(sus-1)/2) {
        cout << 0;
        return;
    }
    int mn = INT_MAX, mx = INT_MIN;
    int cn = 0, cx = 0;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] < mn) {
            mn = cnt[i];
            cn = 0;
        } else if(cnt[i] == mn) cn++;
        if(cnt[i] > mx) {
            mx = cnt[i];
            cx = 0;
        } else if(cnt[i] == mx) cx++;
    }
    if(cn == 1) {
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == mn) {
                cout << i;
                return;
            } 
        }
    }
    if(cx == 1) {
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == mx) {
                cout << i;
                return;
            } 
        }
    }
    cout << 0;
}
