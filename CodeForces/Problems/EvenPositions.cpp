#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    stack<int> free;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            free.push(i);
        }
        else if (s[i] == '(') {
            ans += 1; i++;
        }
        else {
            assert(free.size() > 0);
            ans += i - free.top();
            free.pop();
        }
    }

    cout << ans << '\n';
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
