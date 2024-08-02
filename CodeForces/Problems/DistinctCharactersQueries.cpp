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

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    int n = s.length();
    int q; cin >> q;
    vector<set<int>> pos(26);
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].insert(i);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int p; char c; cin >> p >> c; p--;
            pos[s[p] - 'a'].erase(p);
            pos[c - 'a'].insert(p);
            s[p] = c;
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                auto it = pos[i].lower_bound(l);
                if (it != pos[i].end()) {
                    if (*it <= r)
                        ans++;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
