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
using namespace std;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define For(i, b) FOR(i, 0, b)
#define endl '\n'
#define sp << ' ' <<
#define nl << '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define srt(x) sort(all(x))
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

const int MAXN = 505;
ll m, n, maxE = INT64_MIN, minE = INT64_MAX, startI, startJ;
ll grid[MAXN][MAXN];
bool way[MAXN][MAXN];
bool visited[MAXN][MAXN];
const int dX[]{1, 0, -1, 0};
const int dY[]{0, 1, 0, -1};

void floodfill (ll d, ll r, ll c, ll prev) {
    if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || abs(grid[r][c] - prev) > d) return;
    visited[r][c] = true;
    For (i, 4)
        floodfill(d, r + dY[i], c + dX[i], grid[r][c]);
}

bool works (ll d) {
    floodfill(d, startI, startJ, grid[startI][startJ]);
    For (i, m) {
        For (j, n) {
            if (way[i][j] && !visited[i][j]) return false;
        }
    }
    return true;
}

int main () {
#ifndef LOCAL
    setIO("ccski");
#else
    fastIO;
#endif

    cin >> m >> n;
    For (i, m) {
        For (j, n) {
            cin >> grid[i][j];
            maxE = max(maxE, grid[i][j]);
            minE = min(minE, grid[i][j]);
        }
    }

    For (i, m) {
        For (j, n) {
            cin >> way[i][j];
            if (way[i][j]) startI = i, startJ = j;
        }
    }

    ll lo = 0, hi = maxE - minE, ans = -1;
    while (lo < hi) {
        ll mid = (hi + lo) / 2;
        memset(visited, false, sizeof(visited));
        dbg(sizeof(visited));
        if (works(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans nl;

    return 0;
}
