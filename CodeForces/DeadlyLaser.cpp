#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;
#define sp ' '
#define nl '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl
#pragma GCC optimize("O3,unroll-loops")

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

const int dX[4]{1, 0, -1, 0}, dY[4]{0, 1, 0, -1};

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

const int MXN = 1e3 + 5;
bool vis[MXN][MXN];
int path[MXN][MXN];
int n, m, l1, l2, d;

int dist (int a, int b, int c, int D) {
    return abs(a - c) + abs(b - D);
}

bool v (int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && !vis[i][j] && dist(i, j, l1, l2) > d;
}

void solve () {
    cin >> n >> m >> l1 >> l2 >> d;
    l1--, l2--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { vis[i][j] = false; path[i][j] = -1; }
    }

    int ans = -1;
    queue<tuple<int, int, int>> q; q.push({0, 0, 0});
    while (!q.empty()) {
        auto [a, b, count] = q.front(); q.pop();
        if (vis[a][b]) continue;
        vis[a][b] = true;
        if (a == n - 1 && b == m - 1) { ans = count; break; }
        for (int i = 0; i < 4; i++) {
            int nX = a + dX[i], nY = b + dY[i];
            if (v(nX, nY))
                q.push({nX, nY, count + 1});
        }
    }
    cout << ans << nl;
}

void reset () {

}

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int t;
    cin >> t;
    while (t--) {
        reset();
        solve();
    }

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}
