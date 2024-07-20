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

int n, k;
vector<vi> adj;
vi line, ans;

void simulate () {
    // Add initial positions
    for (int i = 0; i < n; i++) {
        adj[i].pb(i);
    }
    // Simulate the k swaps
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[line[a]].pb(b);
        adj[line[b]].pb(a);
        swap(line[a], line[b]);
    }
}

void cycle () {
    for (int i = 0; i < n; i++) {
        vi cycle;
        int j = i;
        while (line[j] != -1) {
            cycle.pb(j);
            j = line[j];
            line[cycle[cycle.size() - 1]] = -1;
        }
        set<int> viewed;
        for (int c : cycle)
            for (int a : adj[c])
                viewed.insert(a);
        for (int c : cycle)
            ans[c] = viewed.size();
    }
}

int main () {
    fastIO;

    cin >> n >> k; adj.resize(n), line.resize(n), ans.resize(n);
    iota(all(line), 0);
    simulate();
    cycle();

    for (auto a : ans) cout << a << nl;

    return 0;
}
