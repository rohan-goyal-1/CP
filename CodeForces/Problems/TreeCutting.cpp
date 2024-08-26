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

void solve () {
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int comps;
    auto dfs = [&] (auto&& self, int x, int u, int p) -> int {
        int size = 1;
        for (int i : adj[u]) if (i != p) {
            size += self(self, x, i, u);
        }
        if (size >= x) {
            comps++;
            return 0;
        }
        return size;
    };

    auto works = [&] (int x) -> bool {
        comps = 0;
        dfs(dfs, x, 0, -1);
        return comps > k;
    };

    int l = 1, r = n;
    int ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (works(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
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
