#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
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
#define endl '\n'
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
#define max(n, m) ((n > m) ? n : m)
#define min(n, m) ((n < m) ? n : m)

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

int n, color1 = 0, color0 = 0, sum1 = 0, sum0 = 0;
vi clocks;
vector<vi> adj;
vector<bool> vis;

void dfs (int c, int color) {
    if (vis[c]) return;
    if (color == 1) { color1++; sum1 += clocks[c]; }
    else { color0++; sum0 += clocks[c]; }
    vis[c] = true;

    for (auto node : adj[c]) {
        dfs(node, !color);
    }
}

int main () {
#ifndef LOCAL
    setIO("clocktree");
#else
    fastIO;
#endif

    cin >> n; clocks.resize(n), adj.resize(n), vis.resize(n);
    for (int& c : clocks) cin >> c;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(0, 0);
    if (sum1 % 12 == sum0 % 12) cout << n << nl;
    else if ((sum1 + 1) % 12 == sum0 % 12) cout << color0 << nl;
    else if ((sum0 + 1) % 12 == sum1 % 12) cout << color1 << nl;
    else cout << 0 << nl;

    return 0;
}
