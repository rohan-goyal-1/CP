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

const int dX[]{1, 0, -1, 0};
const int dY[]{0, 1, 0, -1};
const int MAXN = 105;
int n, m, ans = 1;
bool visited[MAXN][MAXN], lighted[MAXN][MAXN];
vpi switches[MAXN][MAXN];

bool connected (int r, int c) {
    For (i, 4) {
        int x = c + dX[i];
        int y = r + dY[i];
        if (x < 0 || y < 0 || x >= n || y >= n) continue;
        if (visited[x][y]) return true;
    }
    return false;
}

void floodfill (int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || !lighted[r][c] || visited[r][c] || (!connected(r, c) && (r != 0 || c != 0))) return;
    visited[r][c] = true;
    For (i, 4) 
        floodfill(r + dY[i], c + dX[i]);
    for (auto& [a, b] : switches[r][c]) {
        if (!lighted[a][b]) ans++;
        lighted[a][b] = true;
        floodfill(a, b);
    }
}

int main () {
#ifndef LOCAL
    setIO("lightson");
#else
    fastIO;
#endif

    cin >> n >> m;
    while (m--) {
        int x, y, a, b; 
        cin >> x >> y >> a >> b; 
        x--, y--, a--, b--;
        switches[x][y].pb(mp(a, b));
    }

    lighted[0][0] = true;
    floodfill(0, 0);
    cout << ans nl;

    return 0;
}
