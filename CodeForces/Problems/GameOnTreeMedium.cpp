#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

using namespace std;
using i64 = int64_t;
#define eb emplace_back
#define all(x) begin(x), end(x)
#define f first
#define s second

const int MXN = 2e5 + 5;

int n, t, s;
vector<int> adj[MXN];
bool ans[MXN];

void dfs (int u, int p) {
    for (int i : adj[u]) {
        if (i != p) {
            dfs(i, u);
            ans[u] |= ans[i] ^ 1;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> t;
    assert(t == 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    cin >> s; s--;

    dfs(s, -1);

    cout << (ans[s] ? "Ron\n" : "Hermione\n");

    return 0;
}
