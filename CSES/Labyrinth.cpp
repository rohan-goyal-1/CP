#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;
#define endl '\n'
#define sp ' '
#define nl '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define max(n, m) ((n > m) ? n : m)
#define min(n, m) ((n < m) ? n : m)

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

// paths stores the path we took to reach a cell during the bfs/floodfill
// break the bfs whenever we reach the end point (always the shortest path)
int n, m;
vector<vector<char>> grid, paths;
vector<vector<bool>> visited;
int startX, startY;
int endX, endY;

const int dX[4]{1, 0, -1, 0}, dY[4]{0, 1, 0, -1};
char dirs[4]{'D', 'R', 'U', 'L'};
map<char, pi> mp{ {'D', {-1, 0}}, {'U', {1, 0}}, {'R', {0, -1}}, {'L', {0, 1}} };

bool valid (int i, int j) {
    return i < n && i >= 0 && j < m && j >= 0 && grid[i][j] == '.' && !visited[i][j];
}

int main () {
    fastIO;

    cin >> n >> m;
    grid.resize(n, vector<char>(m)); paths.resize(n, vector<char>(m)); 
    visited.resize(n, vector<bool>(m, false));
    // Input and find start/end
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a; cin >> a;
            if (a == 'A') startX = i, startY = j;
            if (a == 'B') endX = i, endY = j;
            grid[i][j] = a;
        }
    }
    grid[endX][endY] = '.';

    queue<pi> q; q.push({startX, startY});
    while (!q.empty()) {
        pi cur = q.front(); q.pop();
        if (visited[cur.first][cur.second]) continue;
        visited[cur.first][cur.second] = true;
        if (cur == make_pair(endX, endY)) break;
        for (int i = 0; i < 4; i++) {
            int nX = cur.first + dX[i];
            int nY = cur.second + dY[i];
            if (valid(nX, nY)) {
                q.push({nX, nY});
                paths[nX][nY] = dirs[i];
            }
        }
    }

    if (!visited[endX][endY]) {
        cout << "NO" << nl;
    }
    else {
        string ret = "";
        int x = endX, y = endY;
        while (x != startX || y != startY) {
            ret += paths[x][y];
            auto t = mp[paths[x][y]];
            x += t.first, y += t.second;
        }
        reverse(all(ret));
        cout << "YES" << nl << ret.size() << nl << ret << nl;
    }

    return 0;
}
