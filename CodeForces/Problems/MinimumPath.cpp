#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define node tuple<int64_t, int, int, int>
const int MXN = 2e5 + 5;
const int64_t INF = 1e18;

int n, m;
vector<pair<int, int>> adj[MXN];
int64_t ans[MXN][2][2];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    fill(&ans[0][0][0], &ans[0][0][0] + n * 2 * 2, INF);

    auto cmp = [&] (node a, node b) -> bool { return get<0>(a) > get<0>(b); };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp); pq.push({0, 0, 0, 0});
    ans[0][0][0] = 0;
    while (!pq.empty()) {
        auto [d, a, s, u] = pq.top(); pq.pop();
        if (d > ans[u][a][s]) continue;
        for (auto [v, w] : adj[u]) {
            for (int i = a; i < 2; i++) {
                for (int j = s; j < 2; j++) {
                    int64_t nd = d + w;
                    if (i != a) nd -= w;
                    if (s != j) nd += w;
                    if (nd < ans[v][i][j]) {
                        ans[v][i][j] = nd;
                        pq.push({nd, i, j, v});
                    }
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << ans[i][1][1] << " \n"[i == n - 1];
    }

    return 0;
}
