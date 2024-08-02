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
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

int n, m;
// remember the non-existent edges using tree map
map<pi, bool> adj;
vector<bool> visited;

int main () {
    fastIO;

    cin >> n >> m;
    visited.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[{a, b}] = true; adj[{b, a}] = true;
    }

    set<int> left;
    for (int i = 0; i < n; i++)
        left.insert(i);

    vi ans;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int count = 0;
        queue<int> q; q.push(i);
        while (!q.empty()) {
            vi remove;
            int top = q.front(); q.pop();
            if (visited[top]) continue;
            visited[top] = true;
            for (int l : left) {
                if (adj[{l, top}]) continue;
                count++;
                remove.pb(l);
                if (visited[l]) continue;
                q.push(l);
            }
            for (int r : remove) left.erase(r);
        }
        ans.pb(count);
    }
    sort(all(ans));
    cout << ans.size() << nl;
    for (int a : ans) cout << a << sp;
    cout << nl;

    return 0;
}
