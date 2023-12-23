//============================================================================
// Author      : Omar_Hafez
// Created     : 07 July 2023 (Friday)  9:48:44 PM
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
#define newl cout<<endl;

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
    }
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;

bool ok(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void calculate() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, INF));
    char ch;
    queue<tuple<int, int, int>> fires;
    int x1, y1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ch;
            if(ch == '#') a[i][j] = -1;
            else if(ch == 'F') {
                fires.push({i, j, 0});
                a[i][j] = -2; 
            }
            else if(ch == 'J') {
                x1 = i;
                y1 = j;
            }
        }
    }
    if(x1 == 0 || x1 == n-1 || y1 == 0 || y1 == m-1) {
        cout << 1;
        return;
    }
    queue<tuple<int, int, int>> q;
    vector<vector<int>> dp(n, vector<int>(m, INF));
    dp[x1][y1] = 0;
    a[x1][y1] = 0;
    int ans = INF;
    q.push({x1, y1, 0});
    int step, deg;
    while(!q.empty()) {
        step = get<2>(q.front());
        while(!fires.empty() && get<2>(fires.front()) == step) {
            x1 = get<0>(fires.front());
            y1 = get<1>(fires.front());
            deg = get<2>(fires.front());
            fires.pop();
            for(int i = 0; i < 4; i++) {
                int x2 = x1+dx[i];
                int y2 = y1+dy[i];
                if(ok(x2, y2) && a[x2][y2] >= 0) {
                    a[x2][y2] = -2;
                    fires.push({x2, y2, step+1});
                }
            }
        }
        x1 = get<0>(q.front());
        y1 = get<1>(q.front());
        deg = get<2>(q.front());
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x2 = x1+dx[i];
            int y2 = y1+dy[i];
            if(ok(x2, y2) && a[x2][y2] >= 0) {
                if(dp[x1][y1]+1 < dp[x2][y2]) {
                    dp[x2][y2] = dp[x1][y1]+1;
                    if(x2 == 0 || x2 == n-1 || y2 == 0 || y2 == m-1) {
                        ans = min(ans, dp[x2][y2]);
                    }
                    q.push({x2, y2, deg+1});
                }
            }
        }
    }
    if(ans == INF) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << ans+1;
}
