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

vector<vi> adj;
void solve () {
    int n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        adj[i].clear();
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    adj[n - 1].clear();

    vi degree(n);
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            degree[i]++;
            degree[neighbor]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (degree[i] == 2) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

int main () {
    fastIO;

    int t; cin >> t;
    while (t--) { solve(); }

    return 0;
}
