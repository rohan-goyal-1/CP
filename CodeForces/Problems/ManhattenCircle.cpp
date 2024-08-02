#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) begin(x), end(x)
#pragma GCC optimize("O3,unroll-loops")

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100 
#endif

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server

// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

#define point pair<int, int>
#define x first
#define y second

pair<point, point> find_largest (vector<string> grid) {
    point a = {0, 0}, b = {0, -1};
    int n = grid[0].length(), m = grid.size();

    for (int i = 0; i < m; i++) {
        int x = -1, y = -1;
        for (int j = 0; j < n; j++) {
            if (x == -1 && grid[i][j] == '#') x = j, y = j;
            else if (grid[i][j] == '#') y = j;
        }
        if (y == -1 && x == -1) continue;
        if (y - x > b.y - a.y) {
            a = {i, x}; b = {i, y};
        }
        dbgm(y, x);
    }

    return {a, b};
}

void solve () {
    int a, b; cin >> b >> a;
    vector<string> grid(b);
    for (int i = 0; i < b; i++) cin >> grid[i];

    auto [m, n] = find_largest(grid);

    assert(m.x == n.x);

    point ans{m.x, (m.y+n.y)/2};

    cout << ans.x + 1 << ' ' << ans.y + 1 << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
