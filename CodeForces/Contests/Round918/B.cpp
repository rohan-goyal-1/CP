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
#define YES cout << "YES" nl
#define NO cout << "NO" nl

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

void solve () {
    string grid[3];
    int row;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '?') row = i;
        }
    bool A = false, B = false, C = false;
    for (int j = 0; j < 3; j++) {
        if (grid[row][j] == 'A') A = true;
        if (grid[row][j] == 'B') B = true;
        if (grid[row][j] == 'C') C = true;
    }
    if (!A) cout << "A" << nl;
    else if (!B) cout << "B" << nl;
    else cout << "C" << nl;
}

int main () {
    fastIO;

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
