#include <algorithm>
#include <array>
#include <cassert>
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

// ** RESET GLOBALS **

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int n, q; cin >> n >> q;
    vpi x(n); for (int i = 0; i < n; i++) x[i] = {i + 1, 0};
    reverse(all(x));

    map<char, pi> m{ {'R', make_pair(1, 0)}, {'L', make_pair(-1, 0)}, {'D', make_pair(0, -1)}, {'U', make_pair(0, 1)}};

    for (int i = 0; i < q; i++) {
        // dbg(x);
        int c; cin >> c;
        dbg(c);
        if (c == 1) {
            int a; char d;
            cin >> a >> d;
            pi de = m[d];
            dbgm(de, d, a);
            pi cur = x.back();
            x.pb({cur.first + de.first, cur.second + de.second});
        }
        else {
            int a; cin >> a;
            pi ans = x[x.size() - a];
            cout << ans.first << sp << ans.second << nl;
        }
    }

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

