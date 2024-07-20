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

int adj[52];
bool vis[52];

int to_int (char c) {
    if (c >= 'a') return c - 'a';
    return c - 'A' + 26;
}

void _solve () {
    // reset
    memset(adj, -1, 52*sizeof(adj[0]));
    memset(vis, false, 52*sizeof(vis[0]));

    string a, b; cin >> a >> b;
    int n = a.length();
    set<char> s;
    for (int i = 0; i < n; i++) {
        s.insert(b[i]);
        if (adj[to_int(a[i])] != -1 && adj[to_int(a[i])] != b[i]) {
            cout << -1 << '\n';
            return;
        }
        adj[to_int(a[i])] = to_int(b[i]);
    }
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    else {
        if (s.size() == 52) {
            cout << -1 << '\n';
            return;
        }
    }

    int ans = 0;
    // all edges
    for (int i = 0; i < 52; i++) {
        if (adj[i] != -1 && adj[i] != i) {
            ans++;
        }
    }

    // sum all pure cycles with size > 1
    for (int i = 0; i < 52; i++) {
        if (adj[i] != i && adj[i] != -1) {
            int x = adj[i];
            int y = adj[x];
            while (x != -1 && y != -1 && x != y) {
                x = adj[x];
                y = adj[y];
            }
            x = i;
            while (x != -1 && y != -1 && x != y) {
                x = adj[x];
                y = adj[y];
            }
            if (x == i) ans++;
        }
    }

    cout << ans << '\n';
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
