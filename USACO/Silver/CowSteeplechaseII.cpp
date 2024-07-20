#define PROB_NAME "cowjump"

#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const int MXN = 2e5 + 5;
struct Point {
    int x, y;
    int idx;
    bool operator < (Point other) {
        return x == other.x ? y < other.y : x < other.x;
    }
};
struct Segment {
    Point a, b;
    int idx;
    bool operator < (Segment other) {
        return a < other.a;
    }
};

bool intersect (Segment s1, Segment s2) {
    // TODO: implement

    return true;
}

int n;
Segment s[MXN];
int ints[MXN];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    freopen((string(PROB_NAME) + ".in").c_str(), "r", stdin);
    freopen((string(PROB_NAME) + ".out").c_str(), "w", stdout);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        s[i] = {{a, b}, {c, d}, i};
    }
    sort(s, s + n);
    // sort by x
    // Active set: last x point, pop all that are irrelevant -> check for isection:
    //     - if isection:

    set<Point> s;
    for (int i = 0; i < n; i++) {

    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (ints[i] > ints[ans])
            ans = i;
    }
    cout << ++ans << '\n';

    return 0;
}
