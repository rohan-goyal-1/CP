#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

void _solve () {
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        if (x == '1')
            a.emplace_back(i);
    }
    if (a.size() & 1 || (a.size() == 2 && a.front() + 1 == a.back())) cout << "NO\n";
    else cout << "YES\n";
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
