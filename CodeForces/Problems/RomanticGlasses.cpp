#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n; cin >> n;
    vector<int> a(n); for (int& i : a) cin >> i;
    vector<int64_t> op(n + 1), ep(n + 1);
    for (int i = 1; i <= n; i++) {
        op[i] = op[i - 1], ep[i] = ep[i - 1];
        if (i & 1) op[i] += a[i - 1];
        else ep[i] += a[i - 1];
    }

    map<int64_t, bool> m;
    bool found = false;
    m[0] = true;
    for (int i = 1; i <= n; i++) {
        if(m[op[i] - ep[i]]) found = true;
        m[op[i] - ep[i]] = true;
    }
    if (found) cout << "YES\n";
    else cout << "NO\n";
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
