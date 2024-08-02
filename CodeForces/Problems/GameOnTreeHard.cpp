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

int n, t;
vector<int> adj[MXN];
bool works[MXN], ans[MXN];

void dfs (int u, int p) {
    for (int i : adj[u]) {
        if (i != p) {
            dfs(i, u);
            works[u] |= works[i] ^ 1;
        }
    }
}

void recalc (int u, int p, int g) {
    ans[u] = works[u];
    int w = 0, l = 0;
    for (int i : adj[u]) {
        if(i != p) {
            if (works[i]) w++;
            else l++;
        }
    }
    if (g == 1) l++;
    else if (g == 0) w++;
    for (int i : adj[u]) {
        if (i != p) {
            int c = ans[u] ^ 1;
            if (works[i] ^ 1 && l == 1 && w > 0) works[i] = true, c = 0;
            if (adj[u].size() == 1 && (l == 1 || w == 1) && works[i] ^ 1) works[i] = true, c = 1;
            recalc(i, u, c);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    dfs(0, -1);
    recalc(0, -1, -1);

    while (t--) {
        int s; cin >> s; s--;
        cout << (ans[s] ? "Ron\n" : "Hermione\n");
    }

    return 0;
}
