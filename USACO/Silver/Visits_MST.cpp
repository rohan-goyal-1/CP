#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

struct DSU {
    vector<int64_t> e;
    DSU (int64_t n) { e = vector<int64_t>(n, -1); }
    int64_t get (int64_t x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set (int64_t a, int64_t b) { return get(a) == get(b); }
    int64_t size (int64_t x) { return -e[get(x)]; }
    bool unite (int64_t a, int64_t b) {
        a = get(a), b = get(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

const int MXN = 2e5 + 5;

int n; int64_t ans = 0;
array<int, 3> adj[MXN];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, v; cin >> a >> v; a--;
        adj[i] = {v, a, i};
    }
    sort(adj, adj + n, [] (auto a, auto b) -> bool { return a[0] > b[0]; });

    DSU d((int64_t) n);
    for (auto [v, a, i] : adj) {
        if (d.get(a) != d.get(i)) {
            d.unite(a, i);
            ans += v;
        }
    }

    cout << ans << '\n';

    return 0;
}
