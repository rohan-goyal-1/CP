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

vector<array<int, 4>> ans;
vector<vector<bool>> visited;
vector<string> grid;
int n;
int dX[]{1, 0, -1, 0}, dY[]{0, 1, 0, -1};

bool in (int x, int y) {
    return x < n && x >= 0 && y < n && y >= 0;
}

void dfs (int x, int y, int i1, int j1, int i2, int j2) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    char c = grid[x][y];
    for (int i : dX) {
        for (int j : dY) {
            int tempX = x + i, tempY = y + j;
            if (in(tempX, tempY) && grid[tempX][tempY] == c && tempX <= i2 && tempY <= j2 && tempX >= i1 && tempY >= j1) dfs(tempX, tempY, i1, j1, i2, j2);
        }
    }
}

bool works (int x1, int y1, int x2, int y2) {
    bool seen[26]; memset(seen, false, sizeof(seen));
    int regions = 0, colors = 0;
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++) {
            visited[i][j] = false;
            if (!seen[grid[i][j] - 'A']) {
                colors++; 
                seen[grid[i][j] - 'A'] = true;
            }
        }

    if (colors != 2) return false;

    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            if (!visited[i][j]) { regions++; dfs(i, j, x1, y1, x2, y2); }

    return regions >= 3;
}

bool contained (int i, int j) {
    return ans[i][0] >= ans[j][0] && ans[i][2] <= ans[j][2] && 
            ans[i][1] >= ans[j][1] && ans[i][3] <= ans[j][3];
}

int main () {
#ifndef LOCAL
    setIO("where");
#else
    fastIO;
#endif

    cin >> n;
    grid.resize(n); for (auto& s : grid) cin >> s;
    visited.resize(n, vector<bool>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int x = i; x < n; x++)
                for (int y = j; y < n; y++) 
                    if (works(i, j, x, y)) { ans.pb({i, j, x, y}); }

    int ret = 0;
    vector<array<int, 4>> actual;
    for (int i = 0; i < ans.size(); i++) {
        bool check = true;
        for (int j = 0; j < ans.size(); j++) {
            if (i != j && contained(i, j)) check = false;
        }
        if (check) actual.pb(ans[i]);
        ret += check ? 1 : 0;
    }
    cout << ret << nl;

    return 0;
}
