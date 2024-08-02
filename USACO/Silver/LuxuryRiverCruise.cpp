#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

using namespace std;
using i64 = int64_t;
#define eb emplace_back
#define all(x) begin(x), end(x)
#define set_io(x)                                      \
    freopen((string(x) + ".in").c_str(), "r", stdin);  \
    freopen((string(x) + ".out").c_str(), "w", stdout);

const int MXN = 1005, MXM = 505;

int n, m, k;
int s[MXM];
array<int, 2> r[MXN];
int adj[MXN];
bool vis[MXN];

int next (int x) {
    int ret = x;
    for (int i = 0; i < m; i++) {
        ret = r[ret][s[i]];
    }

    return ret;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    set_io("cruise");
#endif

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; a--, b--;
        r[i] = {a, b};
    }
    for (int i = 0; i < m; i++) {
        char a; cin >> a;
        s[i] = a == 'L' ? 0 : 1;
    }

    int cur = 0;
    while (!vis[cur]) {
        vis[cur] = true;
        int t = next(cur);
        adj[cur] = t;
        cur = t;
    }

    cur = 0;
    while (k--) {
        cur = adj[cur];
    }
    cout << ++cur << '\n';

    return 0;
}
