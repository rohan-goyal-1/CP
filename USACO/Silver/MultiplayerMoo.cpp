#define PROB_NAME "multimoo"

#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

const int dX[4] {1, 0, -1, 0}, dY[4] {0, 1, 0, -1};
const int MXN = 255;
int grid[MXN][MXN], ids[MXN][MXN];
bool vis1[MXN][MXN], vis2[MXN];
int n, ans = -1;
int cc = 0, t = 0;
vector<pair<int, int>> regions[MXN];
set<int> adj[MXN];
set<tuple<int, int, int>> counted;

bool valid (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
void dfs1 (int x, int y, vector<pair<int, int>> *s) {
    vis1[x][y] = true;
    ids[x][y] = cc;
    s->push_back({x, y});
    for (int i = 0; i < 4; i++) {
        int nx = x + dX[i], ny = y + dY[i];
        if (valid(nx, ny) && !vis1[nx][ny] && grid[nx][ny] == grid[x][y]) dfs1(nx, ny, s);
    }
}

#define NUM(X) grid[regions[(X)][0].first][regions[(X)][0].second]

void dfs2 (pair<int, int> curr, int r) {
    if (vis2[r]) return;
    vis2[r] = true;
    t += regions[r].size();
    counted.insert({curr.first, curr.second, r});
    for (auto i : adj[r]) {
        int j = NUM(i);
        if (curr.first == j || curr.second == j)
            dfs2(curr, i);
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    freopen((string(PROB_NAME) + ".in").c_str(), "r", stdin);
    freopen((string(PROB_NAME) + ".out").c_str(), "w", stdout);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis1[i][j]) {
                vector<pair<int, int>> temp;
                dfs1(i, j, &temp);
                regions[cc] = temp;
                ans = max(ans, (int)temp.size());
                cc++;
            }
        }
    }
    cout << ans << '\n';
    ans = -1;

    for (auto a : regions) {
        for (auto [x, y] : a) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dX[i], ny = y + dY[i];
                if (valid(nx, ny) && ids[x][y] != ids[nx][ny]) adj[ids[x][y]].insert(ids[nx][ny]);
            }
        }
    }

    for (int i = 0; i < cc; i++) {
        for (auto j : adj[i]) {
            int a = min(NUM(i), NUM(j));
            int b = max(NUM(i), NUM(j));
            tuple<int, int, int> cur = {a, b, i};
            if (counted.count(cur) != 0) continue;
            dfs2({a, b}, i);
            ans = max(ans, t);
        }
    }

    cout << ans << '\n';

    return 0;
}
