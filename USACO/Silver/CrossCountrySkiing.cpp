#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const string PROB_NAME = "ccski";

const int dx[] {-1, 1, 0, 0};
const int dy[] {0, 0, -1, 1};

const int MAXN = 505;
int m, n;
int mid;
int grid[MAXN][MAXN];
bool is_way[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pair<int, int>> ways;

bool is_valid (int x, int y) {
    return x < m && x >= 0 && y < n && y >= 0;
}

void floodfill (int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny) && abs(grid[nx][ny] - grid[x][y]) <= mid)
            floodfill(nx, ny);
    }
}

bool works () {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            vis[i][j] = false;
    floodfill(ways[0].first, ways[0].second);
    int s = ways.size();
    for (int i = 0; i < s; i++) {
        if (!vis[ways[i].first][ways[i].second])
            return false;
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    if (PROB_NAME.size()) {
        freopen((PROB_NAME + ".in").c_str(), "r", stdin);
        freopen((PROB_NAME + ".out").c_str(), "w", stdout);
    }
#endif // LOCAL

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> is_way[i][j];
            if (is_way[i][j])
                ways.push_back({i, j});
        }

    int l = 0, r = 1e9;
    int ans = 1e9;
    while (l <= r) {
        mid = (l + r) / 2;
        if (works()) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
