#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server

// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

typedef struct {
    int64_t x, y, t;
} Event;

#define SQ(x) ((x) * (x))

bool operator < (const Event& a, const Event& b) {
    return a.t < b.t;
}

bool works (Event c, Event g) {
    return SQ(g.x - c.x) + SQ(g.y - c.y) <= SQ(g.t - c.t);
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int g, n; cin >> g >> n;
    vector<Event> gs(g); for (auto& [a, b, c] : gs) cin >> a >> b >> c;
    vector<Event> cs(n); for (auto& [a, b, c] : cs) cin >> a >> b >> c;

    sort(begin(gs), end(gs));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool innocent = false;
        int idx = lower_bound(begin(gs), end(gs), cs[i]) - gs.begin();

        if (idx >= 0 && idx < g) {
            innocent |= !works(cs[i], gs[idx]);
        }
        idx--;
        if (idx >= 0 && idx < g) {
            innocent |= !works(cs[i], gs[idx]);
        }

        ans += innocent;
    }
    cout << ans << '\n';

    return 0;
}
