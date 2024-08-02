#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

const int MXN = 2e5 + 5;
vector<int> adj[MXN];
int a[MXN], dp[MXN];
int n;

void dfs (int u) {
    if (adj[u].size() == 0) dp[u] = a[u];
    else {
        int ret = 1e9;
        for (int i : adj[u]) dfs(i), ret = min(ret, dp[i]);
        if (u == 0) dp[u] = a[u] + ret;
        else dp[u] = min(ret, (a[u] + ret) / 2);
    }
}

void solve () {
    cin >> n;
    for (int i = 0; i < n; i++) { adj[i].clear(); cin >> a[i]; }
    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        adj[u].emplace_back(i);
    }
    dfs(0);
    cout << dp[0] << '\n';
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
