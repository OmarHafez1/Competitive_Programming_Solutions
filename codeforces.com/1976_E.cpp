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
#define int ll
#define ld long double
#define EPS .0000001
#define MOD 998244353
#define PI 3.14159265358979323846

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define rsor(x) sort(all(x), greater<>())

#define uset unordered_set
#define mset multiset
#define umset unordered_multiset

template <typename T>
using pdqu = priority_queue<T, vector<T>, greater<T>>;

struct node {
    int val;
     node(int val) : val(val) {}
    node* prev = NULL;
    node* next = NULL;
};

void push(node* f, node* s) {
    if(s->prev) {
        (s->prev)->next = f;
        f->prev = s->prev;
        s->prev = f;
        f->next = s;
    } else if(f->next) {
        (f->next)->prev = s;
        s->next = f->next;
        f->next = s;
        s->prev = f;
    } else {
        f->next = s;
        s->prev = f;
    }
}

signed main() {
    int n, q;
    cin >> n >> q;
    node* nodes[n+1];
    for(int i = 0; i <= n; i++) {
        nodes[i] = NULL;
    }
    int l[q], r[q];
    int mx = 0;
    for(int i = 0; i < q; i++) {
        cin >> l[i];
        mx = max(mx, l[i]);
    }
    for(int i = 0; i < q; i++) {
        cin >> r[i];
        mx = max(mx, r[i]);
    }
    if(mx < n) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < q; i++) {
        if(!nodes[l[i]]) nodes[l[i]] = new node(l[i]);
        if(!nodes[r[i]]) nodes[r[i]] = new node(r[i]);
        push(nodes[l[i]], nodes[r[i]]);
    }
    node* head = nodes[l[0]];
    while(head->prev) {
        head = head->prev;
    }
    vector<int> a;
    while(head) {
        a.push_back(head->val);
        head = head->next;
    }
    int ss[n+10];
    memset(ss, 0, sizeof(ss));
    for(int i = 0; i < q; i++) {
        ss[max(a[i], a[i+1])]++;
    }
    ss[a.back()]++;
    ss[a[0]]++;
    int ans = 1;
    int add = 0;
    for(int i = n; i; i--) {
        if(nodes[i]) {
           add += ss[i];
           continue; 
        }
        ans *= add;
        ans %= MOD;
        add++;
    }
    cout << ans;
}   

