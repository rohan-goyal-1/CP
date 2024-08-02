#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define set_io(x)                                       \
    freopen((string(x) + ".in").c_str(), "r", stdin);   \
    freopen((string(x) + ".out").c_str(), "w", stdout);

using P = pair<int, int>;
#define x first
#define y second

const int MXN = 105;
const int dX[4] {1, 0, -1, 0}, dY[4] {0, 1, 0, -1};

int n, k, r;
set<P> roads[MXN][MXN];
P cows[MXN];
bool vis[MXN][MXN];

bool valid (int x, int y, int nx, int ny) {
    return nx < n && nx >= 0 && ny < n && ny >= 0 && !vis[nx][ny] && roads[nx][ny].find({x, y}) == roads[nx][ny].end();
}

void dfs (int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dX[i], ny = y + dY[i];
        if (valid(x, y, nx, ny)) dfs(nx, ny);
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    set_io("countcross");
#endif

    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--, d--;
        roads[a][b].insert({c, d});
        roads[c][d].insert({a, b});
    }
    for (int i = 0; i < k; i++) {
        cin >> cows[i].x >> cows[i].y;
        cows[i].x--, cows[i].y--;
    }

    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) fill(vis[j], vis[j] + n, false);

        dfs(cows[i].x, cows[i].y);
        for (int j = 0; j < k; j++) {
            if (!vis[cows[j].x][cows[j].y]) {
                ans++;
                dbgm(i, j);
            }
        }
    }
    ans /= 2;
    cout << ans << '\n';

    return 0;
}
