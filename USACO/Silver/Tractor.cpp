#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define set_io(x)                                       \
    freopen((string(x) + ".in").c_str(), "r", stdin);   \
    freopen((string(x) + ".out").c_str(), "w", stdout);

const int dx[] {-1, 1, 0, 0}, dy[] {0, 0, -1, 1};

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
    set_io("tractor");
#endif

    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto& i : grid)
        for (int& j : i)
            cin >> j;

    int area = 0;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    auto valid = [&] (int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y];
    };

    auto dfs = [&] (auto&& self, int x, int y, int d) -> void {
        area++;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) && abs(grid[nx][ny] - grid[x][y]) <= d)
                self(self, nx, ny, d);
        }
    };

    auto works = [&] (int d) -> bool {
        for (auto& i : vis)
            i = vector<bool>(n, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    area = 0;
                    dfs(dfs, i, j, d);
                    if (area * 2 >= n * n) return true;
                }
            }
        }
        return false;
    };

    int l = 0, r = int(1e6);
    int ans = int(1e6);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (works(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
