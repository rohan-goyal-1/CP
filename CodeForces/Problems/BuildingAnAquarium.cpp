#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

using namespace std;
using i64 = int64_t;
#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

void _solve () {
    int n, x; cin >> n >> x;
    vector<int> a(n); for (int& i : a) cin >> i;

    auto works = [=] (int h) -> bool {
        i64 sum = 0;
        for (int i : a) {
            sum += max(h - i, 0);
        }
        return sum <= x;
    };

    i64 ans = 0;
    i64 l = 1, r = x + *max_element(all(a));
    while (l <= r) {
        i64 mid = (l + r) / 2;
        if (works(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
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
