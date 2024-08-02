#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const int MAXN = 3e5 + 5, K = 19;
const int64_t INF = 8e18;
int64_t a[MAXN], dp[MAXN][K];
vector<int> adj[MAXN];
int n;

void dfs (int u, int p) {
    for (int i = 0; i < K; i++) {
        dp[u][i] = a[u] * (i + 1);
    }
    for (int c : adj[u]) if (c != p) {
        dfs(c, u);
        for (int i = 0; i < K; i++) {
            int64_t x = INF;
            for (int j = 0; j < K; j++) {
                if (i != j) {
                    x = min(x, dp[c][j]);
                }
            }
            dp[u][i] += x;
        }
    }
}

void _solve () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);

    cout << (*min_element(begin(dp[0]), end(dp[0]))) << '\n';
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
