#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

typedef pair<int, int> pi;

const int MXN = 1005;
const int64_t INF = INT64_MAX;

vector<pi> adj[MXN];
int s[MXN];
int64_t dist[MXN][MXN];

void _solve () {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++) cin >> s[i];

    priority_queue<pair<int64_t, pi>, vector<pair<int64_t, pi>>, greater<pair<int64_t, pi>>> pq; pq.push({0, {0, 0}});
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int x = top.second.first, b = top.second.second;
        if (dist[x][b] < dist[x][x]) {
            dist[x][x] = dist[x][b];
            pq.push({dist[x][x], {x, x}});
        }
        for (auto u : adj[x]) {
            int v = u.first, w = u.second;
            if (dist[v][b] > dist[x][b] + (int64_t) w * s[b]) {
                dist[v][b] = dist[x][b] + (int64_t) w * s[b];
                pq.push({dist[v][b], {v, b}});
            }
        }
    }

    int64_t ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dist[n - 1][i]);
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
