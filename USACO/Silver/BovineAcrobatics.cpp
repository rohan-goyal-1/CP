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

int main () {
    fastIO;

    int n, m, k; cin >> n >> m >> k;
    vpi cows(n);
    for (auto& [a, b] : cows) cin >> a >> b;
    sort(all(cows), greater<pi>());
    
    #define w first
    #define a second
    queue<pll> q; q.push({1e15, m});
    int ans = 0, remaining_in_line = 0;
    for (int i = 0; i < n; i++) {
        remaining_in_line = cows[i].a;
        while (remaining_in_line > 0 && !q.empty() && cows[i].w + k <= q.front().w) {
            ll& cur = q.front().a;
            if (cur > remaining_in_line) {
                cur -= remaining_in_line;
                remaining_in_line = 0;
            }
            else {
                remaining_in_line -= cur;
                q.pop();
            }

        }
        int used = cows[i].a - remaining_in_line;
        if (used) {
            q.push({cows[i].w, used});
            ans += used;
        }
    }
    cout << ans << nl;

    return 0;
}
