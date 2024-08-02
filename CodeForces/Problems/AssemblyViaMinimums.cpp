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
    int n; cin >> n;
    vector<int> b(n * (n - 1) / 2); for (int& i : b) cin >> i;

    sort(all(b));
    cout << "1000000000 ";
    int m = n * (n - 1) / 2;
    for (int i = 0; i < m; i += n) {
        cout << b[i] << ' ';
        n--;
    }
    cout << '\n';
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
