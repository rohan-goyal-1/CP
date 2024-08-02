#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

void _solve () {
    int n, m; cin >> n >> m;
    int x = n + m + 1;
    vector<int> p(x), t(x);
    for (int& i : p) cin >> i;
    for (int& i : t) cin >> i;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
