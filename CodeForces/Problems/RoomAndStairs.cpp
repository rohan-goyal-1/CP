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

const int MXN = 1005;
vi adj[MXN * 2];
bool vis[MXN * 2];

int dfs (int v) {
    if (vis[v]) return 0;
    vis[v] = true;
    int m = -1;
    for (int i : adj[v]) m = max(m, dfs(i));
    return 1 + m;
}

void solve () {
    int n; cin >> n;
    for (int i = 0; i < n * 2; i++) {
        adj[i].clear();
        vis[i] = false;
    }
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            adj[i].pb(i + n);
            adj[i + n].pb(i);
        }
        if (i > 0) { 
            adj[i + n].pb(i + n - 1);
            adj[i].pb(i - 1);
        }
        if (i < n - 1) {
            adj[i + n].pb(i + n + 1);
            adj[i].pb(i + 1);
        }
    }
    // dbg(adj);

    int ans = -1;
    for (int i = 0; i < n * 2; i++) {
        if (!vis[i]) {
            ans = max(ans, dfs(i));
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
