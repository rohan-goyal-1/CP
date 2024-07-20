#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const string PROB_NAME = "gates";

const int dx[] {-1, 1, 0, 0};
const int dy[] {0, 0, -1, 1};

const int MAXN = 1000;
const int SZ = 4 * MAXN + 5;
bool fence[SZ][SZ];
bool vis[SZ][SZ];
int n;
string dir;
int maxx = 2001, minx = 2001, maxy = 2001, miny = 2001;

bool is_valid (int x, int y) {
    return x <= maxx && x >= minx && y <= maxy && y >= miny && !fence[x][y] && !vis[x][y];
}

void dfs (int x, int y) {
    if (!is_valid(x, y)) return;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        dfs(x+dx[i], y+dy[i]);
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    freopen((PROB_NAME + ".in").c_str(), "r", stdin);
    freopen((PROB_NAME + ".out").c_str(), "w", stdout);
#endif // LOCAL

    cin >> n >> dir;
    int x = 2001, y = 2001;
    map<char, pair<int, int>> dirs;
    dirs['N'] = {1, 0}; dirs['S'] = {-1, 0}; dirs['E'] = {0, 1}; dirs['W'] = {0, -1};
    for (int i = 0; i < n; i++) {
        fence[x + dirs[dir[i]].first][y + dirs[dir[i]].second] = true;
        fence[x + 2*dirs[dir[i]].first][y + 2*dirs[dir[i]].second] = true;
        x += 2 * dirs[dir[i]].first;
        y += 2 * dirs[dir[i]].second;
        minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
    }
    minx--;
	maxx++;
	miny--;
	maxy++;

    int ans = 0;
    for (int i = minx; i <= maxx; i++)
        for (int j = miny; j <= maxy; j++)
            if (!vis[i][j] && !fence[i][j]) {
                dfs(i, j);
                ans++;
            }

    cout << --ans << '\n';

    return 0;
}
