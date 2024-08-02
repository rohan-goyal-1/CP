#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    set<int> p;
    multiset<int> d;

    auto add = [&] (int a) -> void {
        auto it = p.insert(a).first;
        if (next(it) != p.end() && it != p.begin()) d.erase(d.find(*next(it) - *prev(it)));
        if (next(it) != p.end()) d.insert(*next(it) - *it);
        if (it != p.begin()) d.insert(*it - *prev(it));
    };

    auto remove = [&] (int a) -> void {
        auto it = p.find(a);
        if (next(it) != p.end()) d.erase(d.find(*next(it) - *it));
        if (it != p.begin()) d.erase(d.find(*it - *prev(it)));
        if (it != p.begin() && next(it) != p.end()) d.insert(*next(it) - *prev(it));
        p.erase(it);
    };

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        add(a);
    }

    auto query = [&] () -> int {
        if (d.empty())
            return 0;
        else
            return *prev(p.end()) - *p.begin() - *prev(d.end());
    };

    do {
        cout << query() << '\n';
        if (!q) break;
        int t, x; cin >> t >> x;
        if (t == 0)
            remove(x);
        else
            add(x);
    } while (q--);

    return 0;
}
