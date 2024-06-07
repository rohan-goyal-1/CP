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

const int MAXN = 1e3 + 5;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
ll n, area = 0, per = 0, curP = 0, curA = 0;
const int dX[]{1, 0, -1, 0};
const int dY[]{0, 1, 0, -1};
void floodfill (ll r, ll c) {
    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == '.') { curP++; return; }
    if (visited[r][c]) return;
    curA++;
    visited[r][c] = true;
    For (i, 4)
        floodfill(r + dY[i], c + dX[i]);
}

int main () {
#ifndef LOCAL
    setIO("perimeter");
#else
    fastIO;
#endif

    cin >> n;
    For (i, n) 
        For (j, n) 
             cin >> grid[i][j];

    For (i, n) {
        For (j, n) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                curA = 0, curP = 0;
                floodfill(i, j);
                dbgm(curA, curP);
                per = curA == area ? min(per, curP) : per;
                if (curA > area) {
                    area = curA;
                    per = curP;
                }
                dbgm(area, per);
            }
        }
    }
    cout << area sp per nl;

    return 0;
}
