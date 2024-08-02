#define PROB_NAME "sort"

#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    freopen((string(PROB_NAME) + ".in").c_str(), "r", stdin);
    freopen((string(PROB_NAME) + ".out").c_str(), "w", stdout);
#endif // LOCAL

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int y = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans = max(ans, min(i - x, i - y + 1));
    }
    cout << ++ans << '\n';

    return 0;
}
