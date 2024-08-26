#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int64_t s, k; cin >> s >> k;
    int64_t ans = s * k;

    if (s % 10 == 0) {
        cout << ans << '\n';
        return;
    }

    unordered_map<int, int> seen; seen.reserve(10);
    vector<int64_t> sums;
    for (int i = 1; i <= k; i++) {
        s += s % 10;
        ans = max(ans, s * (k - i));
        if (seen[s % 10] > 0) {
            int start = seen[s % 10];
            int length = i - start;
            int remaining = k - i;
            for (int j = 0; j < remaining % length; j++) {
                s += s % 10;
                ans = max(ans, s * (k - i - j - 1));
            }

            cout << ans << '\n';
            return;
        }
        seen[s % 10] = i;
        sums.emplace_back(s);
    }

    cout << ans << '\n';
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
