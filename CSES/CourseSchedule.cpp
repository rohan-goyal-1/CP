#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const int MXN = 1e5 + 5;
int n, m;
int in[MXN];
vector<int> adj[MXN];
vector<int> ans;
bool vis[MXN];

void dfs (int u) {
    ans.push_back(u);
    for (int i : adj[u]) {
        in[i]--;
        if (!in[i]) dfs(i);
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        in[b]++;
    }

    vector<int> q;
    for (int i = 0; i < n; i++) {
        if (!in[i]) q.push_back(i);
    }
    for (int i : q) dfs(i);

    if ((int) ans.size() != n) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << ++ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}
