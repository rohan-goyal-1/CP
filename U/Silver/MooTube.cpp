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

int n, q, ret = 0;
vector<vpl> adj;
vector<bool> vis;

void dfs (int node, int k) {
    if (vis[node]) return;
    vis[node] = true;
    for (auto& [a, b] : adj[node]) {
        if (b >= k && !vis[a]) {
            ret++;
            dfs(a, k);
        }
    }
}

int main () {
#ifndef LOCAL
    setIO("mootube");
#else
    fastIO;
#endif

    cin >> n >> q;
    adj.resize(n), vis.resize(n);
    while (n-- > 1) {
        int a, b, r; cin >> a >> b >> r;
        adj[--a].pb({--b, r});
        adj[b].pb({a, r});
    }
    n = adj.size();

    while (q--) {
        int k, v; cin >> k >> v; v--;
        dfs(v, k);
        cout << ret << nl;
        for (int i = 0; i < n; i++) vis[i] = false;
        ret = 0;
    }

    return 0;
}
