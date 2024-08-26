#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

struct Edge {
    int c, u;
    bool first;
};

const int MXM = 1e5 + 5;

int n, m;
vector<Edge> adj[MXM];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int f, s; cin >> f >> s; f--, s--;
        adj[f].emplace_back({i, s, false});
        adj[s].emplace_back({i, f, false});
    }

    return 0;
}
