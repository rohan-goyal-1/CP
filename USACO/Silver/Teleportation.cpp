#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define set_io(x)                                       \
    freopen((string(x) + ".in").c_str(), "r", stdin);   \
    freopen((string(x) + ".out").c_str(), "w", stdout);

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    set_io("teleport");
#endif

    int n; cin >> n;
    vector<pair<int, int>> m(n); for (auto& [a, b] : m) cin >> a >> b;

    return 0;
}
