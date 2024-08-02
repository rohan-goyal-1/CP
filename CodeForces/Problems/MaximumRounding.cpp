#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

using namespace std;
using i64 = int64_t;
#define eb emplace_back
#define all(x) begin(x), end(x)
#define f first
#define s second

void _solve () {
    string n; cin >> n;
    n = "0" + n;
    int x = n.length(), last = x;
    for (int i = x - 1; i >= 0; i--) {
        if (n[i] >= '5') n[i - 1]++, last = i;
    }
    int carried = n[0] == '0' ? 1 : 0;
    for (int i = 0; i < x; i++) {
        if (i >= last) n[i] = '0';
    }
    cout << n.substr(carried) << '\n';
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
