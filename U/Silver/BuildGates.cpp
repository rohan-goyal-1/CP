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

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 1000;
int n; 
bool grid[4 * MAXN + 10][4 * MAXN + 10] = {false};
bool visited[4 * MAXN + 10][4 * MAXN + 10] = {false};
int dX[]{1, 0, -1, 0}, dY[]{0, 1, 0, -1};

bool in (int x, int y) {
    return x >= 0 && x < 4 * MAXN + 10 && y >= 0 && y < 4 * MAXN + 10;
}

void dfs (int x, int y) {
    if (!in(x, y) || visited[x][y] || grid[x][y])
        return;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        dfs(x + dX[i], y + dY[i]);
    }
}

int main () {
#ifndef LOCAL
    setIO("gates");
#else
    fastIO;
#endif

    cin >> n;
    char d;
    int curX = 1000, curY = 1000;
    for (int i = 0; i < n; i++) {
        cin >> d;
        grid[curX][curY] = true;
        if (d == 'N') curY++;
        else if (d == 'E') curX++;
        else if (d == 'W') curX--;
        else curY--;
    }
    grid[curX][curY] = true;

    int ans = 0;
    for (int i = 0; i < 4 * MAXN + 10; i++)
        for (int j = 0; j < 4 * MAXN + 10; j++)
            if (!visited[i][j] && !grid[i][j]) {
                ans++;
                dfs(i, j);
            }

    cout << ans - 1 << nl;

    return 0;
}
