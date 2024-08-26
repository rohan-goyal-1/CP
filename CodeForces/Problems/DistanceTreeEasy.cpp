#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

const int INF = 1e9;

void solve () {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        vector<bool> vis(n);
        auto dfs = [&] (auto&& self, int u, int d) -> void {
            if (vis[u]) return;
            vis[u] = true;
            dist[i][u] = d;
            for (int j : adj[u]) {
                self(self, j, d + 1);
            }
        };
        dfs(dfs, i, 0);
    }

    vector<vector<int>> diff(n + 1);
	vector<int> ans(n, INF);
	for (int i = 1; i < n; i++) {
        diff.assign(n + 1, {});
		int best = 0;
		multiset<int> m;
		for (int j = 0; j < n; j++) {
			if (dist[0][j] > dist[i][j]) {
				diff[dist[0][j] - dist[i][j] + 1].push_back(j);
				m.insert(dist[i][j]);
			}
            else {
				best = max(best, dist[0][j]);
			}
		}
		for (int x = 1; x <= n; x++) {
			for (int j : diff[x]) {
				best = max(best, dist[0][j]);
				m.erase(m.find(dist[i][j]));
			}
			int mx = (m.empty() ? -INF : *m.rbegin()) + x;
			ans[x - 1] = min(ans[x - 1], max(mx, best));
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i == n - 1];
	}
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
