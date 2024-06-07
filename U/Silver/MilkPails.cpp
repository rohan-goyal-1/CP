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

bool visited[101][101][101];
int X, Y, K, M, ans = INT_MAX;

void dfs (int x, int y, int k) {
    // Check if current config is seen
    // Mark the curr as true
    // make sure we arent overflowing the moves
    // update ans if necessary
    // Simulate all:
    //    - fill each (2 dfs)
    //    - empty each (2 dfs)
    //    - pour one into other for each (2 dfs)
    if (k > K || visited[x][y][k]) return;
    visited[x][y][k] = true;
    ans = min(ans, abs(M - x - y));

    // fill each
    dfs(X, y, k + 1);
    dfs(x, Y, k + 1);

    // empty each 
    dfs(0, y, k + 1);
    dfs(x, 0, k + 1);

    // pour one into the other 
    // X: 5; x: 2; y: 2
    int putY = min(y, X - x);
    int putX = min(x, Y - y);
    dfs(x + putY, y - putY, k + 1);
    dfs(x - putX, y + putX, k + 1);
}

int main () {
#ifndef LOCAL
    setIO("pails");
#else
    fastIO;
#endif

    cin >> X >> Y >> K >> M;
    dfs(0, 0, 0);
    cout << ans << nl;

    return 0;
}
