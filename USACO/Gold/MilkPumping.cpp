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
#define set_io(x)                                       \
    freopen((string(x) + ".in").c_str(), "r", stdin);   \
    freopen((string(x) + ".out").c_str(), "w", stdout);

const int EPS = 1e6, INF = 1e9;

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
    set_io("pump");
#endif

    using A = array<int, 3>;

    int n, m; cin >> n >> m;
    vector<vector<A>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--;
        adj[a].emplace_back(A{b, c, d});
        adj[b].emplace_back(A{a, c, d});
    }

    vector<int> dp(n, 0);
    auto cmp = [&] (A a, A b) -> bool { return a[0] > b[0]; };
    priority_queue<A, vector<A>, decltype(cmp)> pq(cmp);
    pq.push({0, INF, 0});
    while (!pq.empty()) {
        auto [x, f, u] = pq.top(); pq.pop();
        for (auto [v, c, fn] : adj[u]) {
            int t = min(f, fn);
            int y = (t * EPS) / (x + c);
            if (y > dp[v]) {
                dp[v] = y;
                pq.push({x + c, t, v});
            }
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}
