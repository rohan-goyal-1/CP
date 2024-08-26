#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    int64_t mx_bound = INT32_MAX;
    vector<int64_t> a(n); for (int64_t& i : a) cin >> i, mx_bound = min(mx_bound, i / 4);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    if (a.size() <= 3) {
        cout << mx_bound * (mx_bound + 1) / 2 << '\n';
        return 0;
    }

    set<int64_t> divs;
    for (int64_t i = 0; i < 4; i++) {
        for (int64_t j = 0; j < i; j++) {
            int64_t diff = a[i] - a[j];
            for (long x = 1; x <= int64_t(sqrt(diff)); x++) {
                if (diff % x == 0) {
                    divs.insert(x);
                    divs.insert(diff / x);
                }
            }
        }
    }

    int64_t ans = 0;
    for (int64_t d : divs) if (d <= mx_bound) {
        set<int64_t> done;
        for (int64_t m : a) {
            done.insert(m % d);
        }
        if (done.size() <= 3) ans += d;
    }

    cout << ans << '\n';

    return 0;
}
