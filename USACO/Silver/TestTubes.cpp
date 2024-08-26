#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define BOOL(c) (c == '1' ? false : true)

void solve () {
    int n, p; cin >> n >> p;
    auto compress = [&] () {
        string a; cin >> a;
        vector<bool> ret({BOOL(a[0])});
        for (int i = 1; i < n; i++) if (BOOL(a[i]) ^ ret.back()) {
            ret.emplace_back(BOOL(a[i]));
        }
        return ret;
    };
    vector<bool> s = compress(), t = compress(), b;
    int m = s.size() + t.size() - 2;
    m += s.front() == t.front();
    m += m > 1;

    cout << m << '\n';

    if (p == 1) return;
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
