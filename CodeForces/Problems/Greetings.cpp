#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> p(n); for (auto& [a, b] : p) cin >> b >> a;
    sort(p.begin(), p.end());

    indexed_set s;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s.size() - s.order_of_key(p[i].second);
        s.insert(p[i].second);
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
