#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

const int MXN = 2e5 + 5;

int n; int64_t ans = 0;
int v[MXN], adj[MXN];
bool vis[MXN];

void dfs (int u) {
    if (vis[u]) return;
    vis[u] = true;
    dfs(adj[u]);
}

int cc (int u) {
    int a = adj[u], b = adj[a];
    while (a != b) {
        if (vis[b]) {
            dfs(u);
            return 0;
        }
        a = adj[a], b = adj[adj[b]];
    }

    int ret = v[a];
    dbg(a);
    vis[a] = true;
    a = adj[a];
    while (a != b) {
        ret = min(ret, v[a]);
        vis[a] = true;
        a = adj[a];
    }
    dfs(u);

    return ret;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> adj[i] >> v[i]; adj[i]--;
    }

    for (int i = 0; i < n; i++)
        ans += v[i];
    for (int i = 0; i < n; i++) {
        if (!vis[i]) ans -= cc(i);
    }

    cout << ans << '\n';

    return 0;
}
