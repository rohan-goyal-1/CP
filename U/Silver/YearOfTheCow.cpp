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

const int dX[4]{1, 0, -1, 0}, dY[4]{0, 1, 0, -1};

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

int main () {
    fastIO;

    set<int> years;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        years.insert((a / 12) + 1);
    }
    dbg(years);
    int last_year = 0, ans = *--years.end();
    vi unused;
    while (!years.empty()) {
        int gap = *years.begin() - last_year - 1;
        dbg(gap);
        if (gap > 0)
            unused.pb(gap);
        last_year = *years.begin();
        years.erase(*years.begin());
    }
    sort(all(unused), greater<int>());
    for (int i = 0; i < unused.size() && i < k - 1; i++) ans -= unused[i];
    ans *= 12;
    cout << ans << nl;

    return 0;
}
