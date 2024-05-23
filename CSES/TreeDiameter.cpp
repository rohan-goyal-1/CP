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

int n, endpoint = 0, max_dist = -1;
vector<vi> adj;
vector<bool> vis;

void dfs (int v, int dist) {
    if (vis[v]) return;
    vis[v] = true;
    if (dist > max_dist) {
        max_dist = dist;
        endpoint = v;
    }
    for (int i : adj[v]) {
        dfs(i, dist + 1);
    }
}

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    cin >> n; adj.resize(n); vis.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(0, 0);
    int ans = 0;
    vector<bool> visi(n, false);
    queue<pi> q; q.push({endpoint, 0});
    while (!q.empty()) {
        auto top = q.front(); q.pop();
        if (visi[top.first]) continue;
        visi[top.first] = true;
        ans = max(ans, top.second);
        for (int i : adj[top.first]) {
            q.push({i, top.second + 1});
        }
    }
    cout << ans << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

