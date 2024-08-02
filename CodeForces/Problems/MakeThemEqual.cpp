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

const int MXN = 1005;
int dp[MXN];

void _solve () {
    int n, k; cin >> n >> k;
    vector<int> b(n), c(n);
    int sum = 0;
    for (int& i : b) cin >> i, sum += i;
    for (int& i : c) cin >> i;

    k = min(k, sum);
    vector<int> x(k + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = k - dp[b[i]]; j >= 0; j--) {
            x[j + dp[b[i]]] = max(x[j + dp[b[i]]], x[j] + c[i]);
        }
    }
    cout << (*max_element(all(x))) << '\n';
}

void gen () {
    fill(dp, dp + MXN, MXN);
    dp[1] = 0;
    for (int i = 1; i < MXN; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j < MXN) dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    gen();

    int t; cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
