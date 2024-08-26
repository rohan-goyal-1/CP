#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define set_io(x)                                       \
    freopen((string(x) + ".in").c_str(), "r", stdin);   \
    freopen((string(x) + ".out").c_str(), "w", stdout);

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
    set_io("msched");
#endif

    int n, m; cin >> n >> m;
    vector<int> t(n); for (int& i : t) cin >> i;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].emplace_back(b);
    }

    vector<int64_t> dp(n, -1);
    auto solve = [&] (auto&& self, int u) -> int64_t {
        if (dp[u] != -1) return dp[u];
        int64_t ret = t[u], x = 0;
        for (int i : adj[u]) {
            x = max(x, self(self, i));
        }

        return dp[u] = ret + x;
    };

    int64_t ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, solve(solve, i));
    }
    cout << ans << '\n';

    return 0;
}
