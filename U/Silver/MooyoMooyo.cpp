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

int n, k, cur = 0;
vector<string> grid;
vector<vpi> comp;
bool visited[101][11];
int dX[]{1, 0, -1, 0}, dY[]{0, 1, 0, -1};

void reset () {
    comp.clear();
    cur = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 10; j++) 
            visited[i][j] = false;
}

bool in (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < 10;
}

void dfs (int i, int j) {
    if (!in(i, j) || visited[i][j]) return;
    visited[i][j] = true;
    comp[cur].pb({i, j});
    for (int a = 0; a < 4; a++) {
        int tempX = i + dX[a], tempY = j + dY[a];
        if (grid[tempX][tempY] == grid[i][j]) 
            dfs(tempX, tempY);
    }
}

bool find_components () {
    reset();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (!visited[i][j] && grid[i][j] != '0') {
                comp.pb(vpi());
                dfs(i, j);
                if (comp[cur].size() < k) { comp[cur].clear(); comp.erase(comp.begin() + cur); }
                else cur++;
            }
        }
    }

    // dbg(comp.size());
    return comp.size() > 0;
}

void delete_components () {
    for (auto& c : comp)
        for (auto& [a, b] : c)
            grid[a][b] = '0';
}

void gravity () {
    for (int i = 0; i < 10; i++) {
        vector<char> col;
        for (int j = 0; j < n; j++) {
            if (grid[j][i] != '0') col.pb(grid[j][i]);
        }
        // dbg(col);
        for (int j = n - 1; j >= 0; j--) {
            if (n - 1 - j < col.size())
                grid[j][i] = col[n - 1 - j];
            else 
                grid[j][i] = '0';
        }
    }
}

int main () {
#ifndef LOCAL
    setIO("mooyomooyo");
#else
    fastIO;
#endif

    cin >> n >> k; grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    while (find_components()) {
        find_components();
        delete_components();
        // dbg(grid);
        gravity();
        // dbg(grid);
    }

    for (auto& s : grid) cout << s << nl;

    return 0;
}
