#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

const int MXN = 1e5 + 5;

int n;
vector<int> adj[MXN];
int p[MXN], lc[MXN], ans[MXN];
int freq[MXN];

void dfs1 (int u, int pa) {
    if (adj[u].size() <= 1 && adj[u][0] == pa) {
        lc[u] = 1;
    }
    else {
        for (int i : adj[u]) if (i != pa) {
            dfs1(i, u);
            lc[u] += lc[i];
        }
    }
}

void dfs2 (int u, int pa) {
    int t = 0;
    for (int i : adj[u]) if (i != pa) {
        dfs2(i, u);
        t += ans[i];
    }
    ans[u] = min(t + freq[u], lc[u]);
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    dfs1(0, -1);
    dbg(lc, 0, n - 1);
    for (int i = 0; i < lc[0]; i++) freq[p[i]]++;
    dfs2(0, -1);
    dbg(ans, 0, n - 1);

    cout << ans[0] << '\n';

    return 0;
}
