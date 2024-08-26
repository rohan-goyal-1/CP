#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n, s, m; cin >> n >> s >> m;
    vector<pair<int, int>> t({{0, 0}});
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        t.emplace_back(a, b);
    }
    t.emplace_back(m, m);
    sort(t.begin(), t.end());
    for (int i = 0; i < (int) t.size() - 1; i++) {
        if (t[i + 1].first - t[i].second >= s) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
