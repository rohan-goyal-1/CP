#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> dist(n), dep(n), heavy(n, -1);
    auto dfs1 = [&] (auto&& self, int u, int p) -> void {
        dep[u] = (p == -1 ? 0 : dep[p] + 1);
        dist[u] = 1;
        for (int i : adj[u]) if (i != p) {
            self(self, i, u);
            dist[u] = max(dist[u], dist[i] + 1);
            if (heavy[u] == -1 || dist[i] > dist[heavy[u]]) heavy[u] = i;
        }
    };
    dfs1(dfs1, 0, -1);

    vector<int> st(n);
    auto dfs2 = [&] (auto&& self, int s, int u, int p) -> void {
        st[u] = s;
        for (int i : adj[u]) if (i != p && i != heavy[u]) {
            self(self, i, i, u);
        }
        if (heavy[u] != -1) self(self, s, heavy[u], u);
    };
    dfs2(dfs2, 0, 0, -1);

    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        if (i > 0 && adj[i].size() == 1) {
            ms.insert(dep[i] - dep[st[i]] + (st[i] != 0));
        }
    }

    int ans = n - 1;
    for (int i = 1; i <= n - 1; i++) {
        if (ms.size() > 0) {
            ans -= *ms.rbegin();
            ms.erase(ms.find(*ms.rbegin()));
        }
        if (i != 1 && ms.size() > 0) {
            ans -= *ms.rbegin();
            ms.erase(ms.find(*ms.rbegin()));
        }
        cout << ans << " \n"[i == n - 1];
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
