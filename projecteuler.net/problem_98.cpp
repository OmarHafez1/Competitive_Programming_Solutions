#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ll long long
#define int ll

#define EPS .0000001
#define MOD 1e9+7
#define PI 3.14159265358979323846

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<string> conv(string s) {
    auto tmp = split(s, ",");
    for(auto &str : tmp) {
        str = split(str, "\"")[1];
    }
    return tmp;
}

bool ope(string a, string b) {
    return (a.size() < b.size());
}

vector<int> powers[15];

bool isAnagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

bool isPS(int n) {
    int x = sqrt(n)+EPS;
    return x*x == n;
}

int go(string a, string b) {
    int res = 0;
    for(auto &p : powers[a.size()]) {
        map<int, int> mp;
        set<int> st;
        bool cont = 1;
        string tmp = to_string(p);
        for(int i = 0; i < tmp.size(); i++) {
            if(mp.count(a[i])) {
                if(mp[a[i]] != (tmp[i]-'0')) {
                    cont = 0;
                    break;
                }
            } else {
                if(st.find(tmp[i]-'0') != st.end()) {
                    cont = 0;
                    break;
                }
                st.insert(tmp[i]-'0');
                mp[a[i]] = (tmp[i]-'0');
            }
        }
        if(!cont) continue;
        int p2 = 0;
        for(auto &ch : b) {
            if(p2 == 0) {
                if(mp[ch] == 0) {
                    cont = 0;
                    break;
                }
            }
            p2 = p2*10+mp[ch];
        }
        if(!cont) continue;
        if(isPS(p2)) {
            res = max(res, p);
            res = max(res, p2);
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i*i < 1e15; i++) {
        powers[(int)log10(i*i)+1].push_back(i*i);
    }
    freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    auto str = conv(s);
    sort(str.begin(), str.end(), [](string &a, string &b) {
        return a.size() < b.size();
    });
    int n = str.size();
    vector<int> angs[n+5];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n && str[j].size() == str[i].size(); j++) {
            if(isAnagram(str[i], str[j])) {
                ans = max(ans, go(str[i], str[j]));
            }
        }
    }
    cout << ans;
}   

