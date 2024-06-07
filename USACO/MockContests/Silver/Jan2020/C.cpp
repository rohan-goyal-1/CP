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

int n, m, min_w = INT_MAX, max_w = -1;
vi cows;
vector<vpi> holes;

bool works (int width) {
    // run a bfs to find the components that you can reach from each node given a minimum width of edge
    //    - keep the current component counter & the actual array representing the components
    //    - loop thru the cows --> check if it is already not part of a component (-1 or not)
    //    - setup the queue etc. --> push the current cow
    //    - for each node, push each child if above the minimum width and if not already visited
    //        - mark the top node as part of current component
    // then js loop through each cow and check if it is possible to reach the i_th position from the current position 
    vi comp(n, -1);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (comp[i] != -1) continue;
        queue<int> q; q.push(i); 
        while (!q.empty()) {
            int top = q.front(); q.pop();
            comp[top] = cur;
            for (pi& c : holes[top]) {
                if (c.second >= width && comp[c.first] == -1)
                    q.push(c.first);
            }
        }
        cur++;
    }
    for (int i = 0; i < n; i++) {
        if (comp[cows[i]] != comp[i]) return false;
    }
    return true;
}

int main () {
#ifndef LOCAL
    setIO("wormsort");
#else
    fastIO;
#endif

    cin >> n >> m;
    cows.resize(n); for (int& c : cows) cin >> c, --c;
    holes.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        --a, --b;
        holes[a].pb({b, w});
        holes[b].pb({a, w});
        min_w = min(min_w, w), max_w = max(max_w, w);
    }

    if (is_sorted(all(cows))) {
        cout << -1 << nl;
        return 0;
    }

    int l = min_w, r = max_w, ans = min_w;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (works(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << nl;

    return 0;
}
