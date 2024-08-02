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
    int n, k; cin >> n >> k;
    i64 prod = 1;
    vector<int> A(n); for (auto& a : A) { cin >> a; prod *= a; }
    if (2023 % prod != 0) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << 2023 / prod << ' ';
        for (int i = 1; i < k; i++) cout << 1 << " \n"[i == k - 1];
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
