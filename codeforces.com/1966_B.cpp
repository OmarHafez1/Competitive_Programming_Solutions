#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define int ll

#define endl '\n'

#define EPS .0000001
#define MOD 1e9+7

void calculate();

signed main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        calculate();
        cout << endl;
    }
}

void calculate() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    char ch;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ch;
            a[i][j] = (ch == 'B');
        }
    }
    if(a[0][0] == a[n-1][m-1] || a[0][m-1] == a[n-1][0]) {
        cout << "YES";
        return;
    }
    if(n == 1 || m == 1) {
        cout << "NO";
        return;
    }
    for(int i = 0; i < m-1; i++) {
        if(a[0][i] != a[0][m-1]) {
            for(int j = 1; j < n; j++) {
                if(a[j][m-1] == a[0][i]) {
                    cout << "YES";
                    return;
                }
            }
        }
    }
    for(int i = 1; i < m; i++) {
        if(a[0][i] != a[0][0]) {
            for(int j = 1; j < n; j++) {
                if(a[j][0] == a[0][i]) {
                    cout << "YES";
                    return;
                }
            }
        }
    }

    for(int i = 0; i < m-1; i++) {
        if(a[n-1][i] != a[n-1][m-1]) {
            for(int j = 0; j < n-1; j++) {
                if(a[j][m-1] == a[n-1][i]) {
                    cout << "YES";
                    return;
                }
            }
        }
    }

    for(int i = 1; i < m; i++) {
        if(a[n-1][i] != a[n-1][0]) {
            for(int j = 0; j < n-1; j++) {
                if(a[j][0] == a[n-1][i]) {
                    cout << "YES";
                    return;
                }
            }
        }
    }
    cout << "NO";
}
/*4 4
W W B W
B B W B
W W B B
B B B B*/