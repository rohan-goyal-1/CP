#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

const int64_t INF = 1e18;

void solve () {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, d; cin >> a >> b >> d; a--, b--;
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, -d);
    }

    vector<int64_t> dist(n, INF);
    bool works = true;
    auto dfs = [&] (auto&& self, int u) -> void {
        for (auto [v, d] : adj[u]) {
            if (dist[v] != INF) {
                if (dist[v] != dist[u] + d) {
                    works = false;
                }
            }
            else {
                dist[v] = dist[u] + d;
                self(self, v);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            dist[i] = 0;
            dfs(dfs, i);
        }
    }

    cout << (works ? "YES" : "NO") << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
