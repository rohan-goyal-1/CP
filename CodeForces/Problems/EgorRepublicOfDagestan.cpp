#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

const int INF = 1e9;
#define dist(x) (max(dp[x][0], dp[x][1]))

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        adj[b].emplace_back(a, c);
    }

    vector<array<int, 2>> dp(n, {INF, INF});
    dp[n - 1][0] = 0, dp[n - 1][1] = 0;
    queue<pair<int, int>> q({{n - 1, 0}});
    while (!q.empty()) {
        auto [u, x] = q.front(); q.pop();
        if (x > dist(u)) continue;
        for (auto [v, t] : adj[u]) {
            int d = dist(u) + 1;
            if (d < dp[v][t]) {
                dp[v][t] = d;
                if (dp[v][t] >= dp[v][!t])
                    q.push({v, x + 1});
            }
        }
    }

    cout << (dist(0) >= INF ? -1 : dist(0)) << '\n';
    for (int i = 0; i < n; i++) {
        cout << (dp[i][1] >= dp[i][0]);
    }
    cout << '\n';

    return 0;
}
