#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

#define ld long double

#define EPS .0000001
#define PI 3.14159265358979323846

struct Point {
    ld x = 0, y = 0, z = 0, min_risk = 1;
    bool visited = 0;
    Point(){}
    Point(ld x_val, ld y_val, ld z_val) : x(x_val), y(y_val), z(z_val), min_risk(1), visited(0) {}
    void set(ld x_val, ld y_val, ld z_val) {
        x = x_val;
        y = y_val;
        z = z_val;
        min_risk = 1;
        visited = 0;
    }
};

ld calcRisk(Point p1, Point p2, int radius) {
    int dotProduct = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
    ld angle = acos(dotProduct * 1.0 / (radius * radius));
    return angle*angle/M_PI/M_PI;
}

int north = 0, south = 0;
int sz = 0;
Point points[70000];

void add(vector<int> p) {
    do {
        points[sz++].set(p[0], p[1], p[2]);
        if(p[0] == 0 && p[1] == 0) north = sz-1;
        if(p[2]) {
            points[sz++].set(p[0], p[1], p[2]*-1);
            if(p[0] == 0 && p[1] == 0) south = sz-1;
        }
    } while(next_permutation(p.begin(), p.end()));
}

void generatePoints(int r) {
    sz = 0;
    for(int a = 0; a*a*3 <= r*r; a++) {
        for(int b = a; b*b*2+a*a <= r*r; b++) {
            int c = sqrt(r*r-a*a-b*b)+EPS;
            if(a*a+b*b+c*c == r*r) {
                add({a, b, c});
            }
        }
    }
}

ld M(int r) {
    int next = north;
    points[north].min_risk = 0;
    points[sz].min_risk = 1;
    points[sz].visited = 0;
    while(next != south) {
        int current = next;
        points[next].visited = 1;
        next = sz;
        for(int i = 0; i < sz; i++) {
            if(points[i].visited) continue;
            points[i].min_risk = min(points[i].min_risk, calcRisk(points[current], points[i], r)+points[current].min_risk);
            if(points[i].min_risk < points[next].min_risk) next = i;
        }
    } 
    return points[south].min_risk;
}

signed main() {
    cout << fixed << setprecision(10);
    ld ans = 0;
    int from, to;
    cin >> from >> to;
    for(int n = from; n <= to; n++) {
        int r = (1 << n)-1;
        generatePoints(r);
        ans += M(r);
    }
    cout << ans << endl;
}
    
