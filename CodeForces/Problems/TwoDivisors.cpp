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
    i64 a, b; cin >> a >> b;
    if (b % a) {
        cout << b * a / gcd(b, a) << '\n';
    }
    else {
        cout << b * b / a << '\n';
    }
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
