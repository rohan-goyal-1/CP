#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

template <typename T>
T ceil_div (T a, T b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

void solve () {
    int n; cin >> n;
    int64_t w; cin >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    int64_t x = ceil_div<int64_t>(w, 2);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].first >= x && a[i].first <= w) {
            cout << "1\n" << a[i].second + 1 << '\n';
            return;
        }
    }

    int64_t s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i].first;
        if (s > w) {
            cout << "-1\n";
            return;
        }
        if (s >= x) {
            cout << i + 1 << '\n';
            for (int j = 0; j <= i; j++) cout << a[j].second + 1 << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "-1\n";
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
