#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

const int MXN = 2e5 + 5;
int n, m, s;
vector<int> adj[MXN];
int path[MXN], subtree[MXN];

void solve (int x) {
    for (auto y : adj[x]) {
        if (subtree[y] == -1) {
            subtree[y] = subtree[x];
            path[y] = x;
            solve(y);
        }
        else if (subtree[y] != subtree[x]) {
            cout << "Possible\n";
            stack<int> l1({y}), l2;
            int i = x, j = y;
            while (i != -1) {
                l1.push(i);
                i = path[i];
            }
            while (j != -1) {
                l2.push(j);
                j = path[j];
            }
            cout << l1.size() << '\n';
            while (!l1.empty()) cout << l1.top() + 1 << ' ', l1.pop();
            cout << '\n';
            cout << l2.size() << '\n';
            while (!l2.empty()) cout << l2.top() + 1 << ' ', l2.pop();
            cout << '\n';

            exit(0);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m >> s; s--;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        if (s != v)
            adj[u].emplace_back(v);
    }

    memset(path, -1, sizeof(path));
    memset(subtree, -1, sizeof(subtree));
    for (auto i : adj[s]) {
        path[i] = s;
        subtree[i] = i;
    }
    for (auto i : adj[s])
        solve(i);

    cout << "Impossible\n";

    return 0;
}
