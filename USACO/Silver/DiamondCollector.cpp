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
    set_io("diamond");
#endif

    int n, k; cin >> n >> k;
    vector<int> a(n); for (int& i : a) cin >> i;
    sort(begin(a), end(a));

    vector<int> mxs(n);
    for (int i = 0; i < n; i++) {
        int count = 0;
        while (count + i < n && a[count + i] - a[i] <= k) {
            count++;
        }
        mxs[i] = count;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (j >= mxs[i] + i)
                ans = max(ans, mxs[i] + mxs[j]);
        }
    }
    cout << ans << '\n';

    return 0;
}
