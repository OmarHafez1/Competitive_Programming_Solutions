/* 
**
**   author:  Omar_Hafez
**   created: 18 February 2022 (Friday)  6:11:45 PM
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
#define pushb(a) push_back(a)
#define pushf(a) push_front(a)
#define popb pop_back()
#define popf pop_front()

// pairs & tuples
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

#define iset_int indexed_set_int
#define iset_ui indexed_set_ui
#define iset_ll indexed_set_ll
#define iset_ull indexed_set_ull
#define iset_db indexed_set_db
#define iset_ld indexed_set_ld
#define iset_float indexed_set_float
#define iset_string indexed_set_string

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
#define getline(a) scanf("%[^\n]%*c", a);
#define newl cout<<endl;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define y1 this_fix_bug_with_this_name_2022

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


bool Royal_FLush(vec<pair<int, char>> &h1) {
  for(int i = 1; i < 5; i++) {
    if(h1[i].second != h1[i-1].second) return 0;
  }
  for(int i = 4; i >= 0; i--) {
    if(h1[i].first != i+9) return 0;
  }
  return 1;
}

bool Straight_Flush(vec<pair<int, char>> &h1) {
  for(int i = 1; i < 5; i++) {
    if(h1[i].second != h1[i-1].second) return 0;
  }
  for(int i = 1; i < 5; i++) {
    if(h1[i].first != h1[i-1].first-1) return 0;
  }
  return 1;
}

vi tmp(14);
bool Four_Of_A_Kind(vec<pair<int, char>> &h1) {
  for(int i = 0; i < 5; i++) {
    tmp[h1[i].first]++;
  }
  for(int i = 1; i <= 13; i++) if(tmp[i] == 4) return 1;
  return 0;
}

bool Full_House(vec<pair<int, char>> &h1) {
  bool ok3 = 0, ok2 = 0;
  for(int i = 1; i <= 13; i++) {
    if(tmp[i] == 3) ok3 = 1;
    else if(tmp[i] == 2) ok2 = 1;
  }
  return ok2&ok3;
}

bool Flush(vec<pair<int, char>> &h1) {
  for(int i = 1; i < 5; i++) {
    if(h1[i].second != h1[i-1].second) return 0;
  }
  return 1;
}

bool Straight(vec<pair<int, char>> &h1) {
  for(int i = 1; i < 5; i++) {
    if(h1[i].first != h1[i-1].first-1) return 0;
  }
  return 1;
}

bool Three_Of_A_Kind(vec<pair<int, char>> &h1) {
  for(int i = 1; i <= 13; i++) {
    if(tmp[i] == 3) return 1;
  } 
  return 0;
}

bool Two_Pair(vec<pair<int, char>> &h1) {
  int cnt = 0;
  for(int i = 1; i <= 13; i++) {
    if(tmp[i] == 2) cnt++;
  }
  return cnt == 2;
}

int where = 0;
bool One_Pair(vec<pair<int, char>> &h1) {
  int cnt = 0;
  for(int i = 1; i <= 13; i++) {
    if(tmp[i] == 2) {
      cnt++;
      where = i;
    }
  }
  return cnt == 1;
}

void check(vec<pair<int, char>> &hand, ll &player) {
  for(int i = 1; i <= 13; i++) {
    tmp[i] = 0;
  }
  where = 0;
  if(Royal_FLush(hand)) {
    player = 10*1e8;
  } else if(Straight_Flush(hand)) {
    player = 9*1e8;
    for(int i = 0; i < 5; i++) {
      player += hand[i].first * pow(10, 5-i);
    }
  } else if(Four_Of_A_Kind(hand)) {
    player = 8*1e8;
    for(int i = 1; i <= 13; i++) {
      if(tmp[i] == 4) {
        player += i * 10000;
      } else {
        player += i * 100;
      }
    }
  } else if(Full_House(hand)) {
    player = 7*1e8;
    for(int i = 1; i <= 13; i++) {
      if(tmp[i] == 3) {
        player += i*1000;
      } else if(tmp[i] == 2) {
        player += i*100;
      }
    }
  } else if(Flush(hand)) {
    player = 6*1e8;
    for(int i = 0; i < 5; i++) {
      player += hand[i].first * pow(10, 5-i);
    }
  } else if(Straight(hand)) {
    player = 5*1e8;
    for(int i = 0; i < 5; i++) {
      player += hand[i].first * pow(10, 5-i);
    }
  } else if(Three_Of_A_Kind(hand)) {
    player = 4*1e8;
    int no = 0;
    for(int i = 1; i <= 13; i++) {
      if(tmp[i] == 3) {
        player += i * pow(10, 6);
        no = i;
      } 
    }
    int pp = 4;
    for(int i = 0; i < 5; i++) {
      if(hand[i].first == no) continue;
      player += hand[i].first * pow(10, pp);
      pp--;
    }
  } else if(Two_Pair(hand)) {
    player = 3*1e8;
    int pp = 4;
    for(int i = 13; i >= 1; i--) {
      if(tmp[i] == 2) {
        player += i * pow(10, pp);
        pp--;
      } else if(tmp[i] == 1) {
        player += i * 10;
      }
    } 
  } else if(One_Pair(hand)) {
    player = 2*1e8;
    player += where *= 1000000;
    for(int i = 0; i < 5; i++) {
      if(hand[i].first == where) continue;
      player += hand[i].first * pow(10, 5-i);
    }
  } else {
    player = 1e8;
    for(int i = 0; i < 5; i++) {
      player += hand[i].first * pow(10, 5-i);
    }
  }
}

int main() { 
  ios_base::sync_with_stdio(false); cin.tie(NULL); 
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout); 
  
  int ans = 0;
  int t;
  cin >> t;
  for(int kkk = 0; kkk < t; kkk++) {
    vec<pair<int, char>> h1, h2;
    string str;
    for(int i = 0; i < 5; i++) {
      cin >> str;
      int val;
      if(str[0] == 'A') val = 13;
      else if(str[0] == 'K') val = 12;
      else if(str[0] == 'Q') val = 11;
      else if(str[0] == 'J') val = 10;
      else if(str[0] == 'T') val = 9;
      else val = str[0]-'1';
      h1.push_back({val, str[1]});
    }
    for(int i = 0; i < 5; i++) {
      cin >> str;
      int val;
      if(str[0] == 'A') val = 13;
      else if(str[0] == 'K') val = 12;
      else if(str[0] == 'Q') val = 11;
      else if(str[0] == 'J') val = 10;
      else if(str[0] == 'T') val = 9;
      else val = str[0]-'1';
      h2.push_back({val, str[1]});
    }
    rsor(h1); rsor(h2);
    ll player1, player2;
    check(h1, player1); 
    check(h2, player2); 
    if(player1 > player2) {
      ans++;
    }
  }
  cout << ans;
}
   
   