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

struct Flight {
    int r, d, s;
};

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int n, m; cin >> n >> m;
    vector<vector<Flight>> adj(n);
    vi a(n);
    for (int i = 0; i < m; i++) {
        int c, r, d, s; cin >> c >> r >> d >> s; --c, --d;
        adj[c].pb({r, d, s});
    }
    for (int i = 0; i < n; i++) cin >> a[i];

    dbg(adj[0].size());
    vi ans(n, -1);
    queue<pi> q; q.push({0, 0});
    vector<bool> vis(n);
    while (!q.empty()) {
        auto [i, t] = q.front(); q.pop();
        ans[i] = t; vis[i] = true;
        t += a[i];
        for (auto [r, d, s] : adj[i]) {
            if (!vis[d] && r >= t) {
                q.push({d, s});
            }
        }
    }

    for (int i : ans) cout << i << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

