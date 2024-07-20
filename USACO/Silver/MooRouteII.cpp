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

const int MAXN = 2e5 + 5;

typedef struct {
    int r, d, s, id;
} Flight;

int n, m;
vector<Flight> adj[MAXN];
int lays[MAXN];
int64_t ans[MAXN];
bool vis[MAXN];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, c--;
        adj[a].push_back({b, c, d, i});
    }
    for (int i = 0; i < n; i++) {
        cin >> lays[i];
    }
    memset(ans, -1, n*sizeof(ans[0]));
    ans[0] = 0;

    queue<pair<int64_t, int>> q;
    for (Flight f : adj[0]) {
        vis[f.id] = true;
        q.push({f.s, f.d});
    }
    while (!q.empty()) {
        auto [t, u] = q.front(); q.pop();
        ans[u] = (ans[u] == -1 ? t : min(ans[u], t));
        t += lays[u];
        for (Flight f : adj[u]) {
            if (!vis[f.id] && f.r >= t) {
                vis[f.id] = true;
                q.push({f.s, f.d});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
