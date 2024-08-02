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
    int n; cin >> n;
    vector<int> a(n); for (int& i : a) cin >> i;
    vector<int> l(n); for (int& i : l) cin >> i;
    vector<int> u;
    for (int i = 0; i < n; i++) {
        if (!l[i]) u.emplace_back(i);
    }
    sort(all(u), [&] (int x, int y) -> bool { return a[x] > a[y]; });
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (l[i]) cout << a[i] << " \n"[i == n - 1];
        else {
            cout << a[u[c++]] << " \n"[i == n - 1];
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
