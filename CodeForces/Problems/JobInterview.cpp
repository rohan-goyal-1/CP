#include "bits/stdc++.h"

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

using namespace std;
using i64 = int64_t;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve () {
    int n, m; cin >> n >> m;
    int k = n + m + 1;
    vector<int> p(k); for (int& i : p) cin >> i;
    vector<int> t(k); for (int& i : t) cin >> i;
    vector<int> cnt(k + 1); vector<i64> sum(k + 1), sfx_p(k + 1), sfx_t(k + 1);
    for (int i = 0; i < k; i++) {
        cnt[i + 1] = cnt[i] + (p[i] > t[i]);
        sum[i + 1] = sum[i] + max(p[i], t[i]);
        int j = k - 1 - i;
        sfx_p[j] = sfx_p[j + 1] + p[j];
        sfx_t[j] = sfx_t[j + 1] + t[j];
    }

    for (int i = 0; i < k; i++) {
        auto works = [&] (int skill) -> bool {
            int x = cnt[skill] - (i < skill && p[i] > t[i]);
            int y = skill - cnt[skill] - (i < skill && t[i] > p[i]);
            return x <= n && y <= m;
        };

        int l = 0, r = k;
        int x = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (works(mid)) {
                l = mid + 1;
                x = mid;
            }
            else {
                r = mid - 1;
            }
        }

        i64 ans = sum[x];
        if (i < x) {
            ans -= max(p[i], t[i]);
            if ((cnt[x] - (p[i] > t[i])) == n) ans += sfx_t[x];
            else ans += sfx_p[x];
        }
        else {
            if (cnt[x] == n) ans += sfx_t[x] - t[i];
            else ans += sfx_p[x] - p[i];
        }
        cout << ans << " \n"[i == k - 1];
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
