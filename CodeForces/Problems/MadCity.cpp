#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

using namespace std;
using i64 = int64_t;
#define eb emplace_back
#define all(x) begin(x), end(x)
#define f first
#define s second

const int MXN = 2e5 + 5;

int n, a, b;
vector<int> adj[MXN];
bool vis[MXN];

int ve;
int md, vd;

bool dfs1 (int u, int p) {
    vis[u] = true;
    for (int i : adj[u]) {
        if (i != p) {
            if (vis[i]) {
                ve = i;
                return true;
            }
            if (dfs1(i, u))
                return true;
        }
    }
    return false;
}

int dfs2 (int u) {
    if (u == ve) return 0;
    vis[u] = true;
    int ret = n;
    for (int i : adj[u]) {
        if (!vis[i]) {
            int t = dfs2(i) + 1;
            ret = min(ret, t);
        }
    }
    return ret;
}

void _solve () {
    memset(vis, false, n * sizeof(bool));
    cin >> n >> a >> b; a--, b--;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs1(b, -1);
    dbg(ve);
    memset(vis, false, n * sizeof(bool));
    md = dfs2(a);
    memset(vis, false, n * sizeof(bool));
    vd = dfs2(b);

    cout << (vd < md ? "YES\n" : "NO\n");
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
// Find valeriu's entrance node to the cycle
// Compute marcel's/valeriu's distance to the node
// If valeriu's distance < marcel's distance, he wins; otherwise, marcel wins
