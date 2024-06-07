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

int n, k;
vpi moves;
vector<set<int>> visited;
vi cycle;

int main () {
    fastIO;

    // Input
    cin >> n >> k;
    moves.resize(k), visited.resize(n), cycle.resize(n);
    for (auto& [a, b] : moves) cin >> a >> b, --a, --b;

    // Simulate
    vi cows(n); iota(all(cows), 0);
    for (auto& [a, b] : moves) {
        dbgm(a, b, cows);
        visited[cows[a]].insert(b), visited[cows[b]].insert(a);
        swap(cows[a], cows[b]);
    }
    dbg(cows);
    dbg(visited);
    
    // Represent the cycle
    for (int i = 0; i < n; i++)
        cycle[cows[i]] = i;
    dbg(cycle);

    // DFS thru the cycle to find what positions the cow travels
    return 0;
}
