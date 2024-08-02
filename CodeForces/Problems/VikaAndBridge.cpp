#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void _solve () {
    int k, n; cin >> k >> n;
    vector<int> p(k); for (int& i : p) cin >> i, i--;
    vector<int> last(n, -1);
    vector<vector<int>> dist(n);
    for (int i = 0; i < k; i++) {
        dist[p[i]].push_back(i - last[p[i]] - 1);
        last[p[i]] = i;
    }
    int ans = k;
    for (int i = 0; i < n; i++) {
        dist[i].push_back(k - 1 - last[i]);
        sort(rall(dist[i]));
        ans = min(ans, max(dist[i][0] / 2, dist[i].size() > 1 ? dist[i][1] : -1));
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;

}
