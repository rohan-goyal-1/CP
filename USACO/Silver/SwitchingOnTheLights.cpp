#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const string PROB_NAME = "lightson";

const int MAXN = 105;
const int dx[] {-1, 1, 0, 0};
const int dy[] {0, 0, -1, 1};

bool vis[MAXN][MAXN];
bool on[MAXN][MAXN];
vector<pair<int, int>> switches[MAXN][MAXN];
int n, m;

bool valid (int x, int y) {
    return x < n && x >= 0 && y < n && y >= 0;
}

void dfs (int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = true;

    int s = switches[x][y].size();
    for (int i = 0; i < s; i++) {
        auto j = switches[x][y][i];
        on[j.first][j.second] = true;
        for (int a = 0; a < 4; a++) {
            int nx = j.first + dx[a];
            int ny = j.second + dy[a];
            if (valid(nx, ny) && vis[nx][ny]) {
                dfs(j.first, j.second);
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny) && on[nx][ny])
            dfs(nx, ny);
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    if (PROB_NAME.size()) {
        freopen((PROB_NAME + ".in").c_str(), "r", stdin);
        freopen((PROB_NAME + ".out").c_str(), "w", stdout);
    }
#endif // LOCAL

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b; x--, y--, a--, b--;
        switches[x][y].push_back({a, b});
    }

    on[0][0] = true;
    dfs(0, 0);

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (on[i][j]) ans++;
    cout << ans << '\n';

    return 0;
}
