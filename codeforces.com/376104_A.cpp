#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATED
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <bitset>
#include <math.h>
#include <iomanip>

using namespace std;

#define EPS 1e-9
#define PI 3.1415926535897932384626433832795028841971
#define INF 2000000000
#define OO 0x7fffffff
#define OOO 1.7e308
#define ll long long
#define ull unsigned long long
#define lp(i,n) for(int i=0;i<n;i++)
#define rep(i,j,n) for(int i=j;i<n;i++)
#define clr(memo, j) memset(memo, j, sizeof memo)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define All(a) a.begin(), a.end()
#define even(x) x%2==0
#define odd(x) x%2!=0
#define rd(x) scanf("%d", &x)
#define pt(x) printf("%d", x)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;

bool comp(ull x, ull y) { return x > y; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

/*
class UnionFind {
private: vi p, rank;
public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      }
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};


class SegmentTree {
private:
  vector<pair<ll, ll> > st;
  vll a;
  int n;
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R) st[p] = make_pair(a[L], a[L]);
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      pair<ll, ll> p1 = st[left(p)], p2 = st[right(p)];
      if (R - L == 1) st[p] = make_pair(p1.first, p2.first);
      else {
        pair<ll, pair<ll, ll> > minuses[] = { make_pair(abs(p1.first - p1.second), make_pair(p1.first, p1.second)), make_pair(abs(p1.first - p2.first), make_pair(p1.first, p2.first)), make_pair(abs(p1.first - p2.second), make_pair(p1.first, p2.second)), make_pair(abs(p1.second - p2.first), make_pair(p1.second, p2.first)), make_pair(abs(p1.second - p2.second), make_pair(p1.second, p2.second)), make_pair(abs(p2.first - p2.second), make_pair(p2.first, p2.second)) };
        sort(minuses, minuses + 6);
        st[p] = minuses[0].second;
      }
    }
  }

  pair<ll, ll> rmq(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return make_pair(-1LL, -1LL);
    if (L >= i && R <= j) {
      if (R == L) return make_pair(a[R], -1LL);
      return st[p];
    }

    pair<ll, ll> p1 = rmq(left(p), L, (L + R) / 2, i, j);
    pair<ll, ll> p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1.first == -1) return p2;
    if (p2.first == -1) return p1;
    if (R - L == 1) return make_pair(a[L], a[R]);
    else {
      pair<ll, pair<ll, ll> > minuses[6];
      if (p1.second != -1) {
        minuses[0] = make_pair(abs(p1.first - p1.second), make_pair(p1.first, p1.second));
        minuses[1] = make_pair(abs(p1.second - p2.first), make_pair(p1.second, p2.first));
        if (p2.second != -1) minuses[2] = make_pair(abs(p1.second - p2.second), make_pair(p1.second, p2.second));
        else minuses[2] = make_pair(1000000009LL, make_pair(p1.second, p2.second));
      }
      else {
        minuses[0] = make_pair(1000000009LL, make_pair(p1.first, p1.second));
        minuses[1] = make_pair(1000000009LL, make_pair(p1.second, p2.first));
        if (p2.second != -1) minuses[2] = make_pair(1000000009LL, make_pair(p1.second, p2.second));
        else minuses[2] = make_pair(1000000009LL, make_pair(p1.second, p2.second));
      }

      minuses[3] = make_pair(abs(p1.first - p2.first), make_pair(p1.first, p2.first));

      if (p2.second != -1) {
        minuses[4] = make_pair(abs(p1.first - p2.second), make_pair(p1.first, p2.second));
        minuses[5] = make_pair(abs(p2.first - p2.second), make_pair(p2.first, p2.second));
      }
      else {
        minuses[4] = make_pair(LLONG_MAX, make_pair(p1.first, p2.second));
        minuses[5] = make_pair(LLONG_MAX, make_pair(p2.first, p2.second));
      }

      sort(minuses, minuses + 6);
      return minuses[0].second;
    }
  }

public:
  SegmentTree(const vll &_a) {
    a = _a;
    n = a.size();
    st.assign(4 * n, make_pair(INF, INF));
    build(1, 0, n - 1);
  }

  pair<ll, ll> rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

class FenwickTree {
private: vi ft;
public:
  FenwickTree(int n) {
    ft.assign(n + 1, 0);
  }

  int LSOne(int S) { return (S & (-S)); }

  int rsq(int b) {
    int sum = 0;
    for (; b > 0; b -= LSOne(b)) sum += ft[b];
    return sum;
  }

  int rsq(int a, int b) {
    return rsq(b) - ((a == 1) ? 0 : rsq(a - 1));
  }

  int get(int i) { return ft[i]; }

  void adjust(int k, int v) {
    for (; k < ft.size(); k += LSOne(k)) ft[k] += v;
  }
};

*/

ll gcd(ll a, ll b) {
  return b ? gcd(b, a%b) : a;
}


ll mod = 1000000000 + 7;


void solveA() {
  int n;
  int x;
  cin >> n >> x;

  bool first = false, second = false, third = false;
  int div = n / 3;
  int rem = n % 3;

  int pos;
  if (even(div)) {
    if (rem == 0) pos = 0;
    else if (rem == 2) pos = 2;
    else pos = 1;
  }
  else {
    if (rem == 0) pos = 2;
    else if (rem == 2) pos = 0;
    else pos = 1;
  }

  if (pos == x) first = true;

  if (n <= 2) {
    if (n == 1 && x == 0) second = true;
    else if (n == 2 && x == 0) second = true;
  }
  else {
    int tmp = n - 2;
    div = tmp / 3;
    rem = tmp % 3;
    if (even(div)) {
      if (rem == 0) pos = 0;
      else if (rem == 2) pos = 2;
      else pos = 1;
    }
    else {
      if (rem == 0) pos = 2;
      else if (rem == 2) pos = 0;
      else pos = 1;
    }

    if (pos == x) second = true;
  }

  if (first) cout << "0" << endl;
  else if (second) cout << "1" << endl;
  else cout << "2" << endl;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  //freopen("C:\\Users\\Wajdy\\Desktop\\debugIn.txt", "r", stdin);
  //freopen("C:\\Users\\Wajdy\\Desktop\\debugOut.txt", "w", stdout);

  //ios::sync_with_stdio(false);
  
  solveA();

  return 0;
}