#include "bits/stdc++.h"

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

using namespace std;
using i64 = int64_t;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

const i64 INF = 1e18;

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), radj(n);
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        edges[i] = {a, b, -c};
        adj[a].emplace_back(b);
        radj[b].emplace_back(a);
    }

    vector<bool> vis(n), rvis(n);
    auto dfs = [&] (auto self, int u, vector<bool> &t, vector<vector<int>> &g) -> void {
        if (t[u]) return;
        t[u] = true;
        for (int v : g[u]) {
            self(self, v, t, g);
        }
    };
    dfs(dfs, 0, vis, adj); dfs(dfs, n - 1, rvis, radj);

    vector<i64> dp(n, INF); dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
                if (vis[v] && rvis[v] && i == n - 1) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    cout << -dp[n - 1] << '\n';

    return 0;
}
