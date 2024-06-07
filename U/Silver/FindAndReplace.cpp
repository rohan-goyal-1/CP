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

int char_to_int (char c) {
    if (c >= 'a') return c - 'a';
    return c - 'A' + 26;
}

vi visited(52, -1), ins(52, 0);
int ans = 0;
vi adj(52, -1);
vector<bool> seen(52, false);

void solve () {
    string a, b; cin >> a >> b;
    dbgm(a, b);
    if (a == b) { cout << 0 << nl; return; }
    int count = 0;
    // initial processing, generation of adj, checking for impossible cases
    for (int i = 0; i < a.size(); i++) {
        int x = char_to_int(a[i]);
        int y = char_to_int(b[i]);
        if (!seen[y]) {
            count++;
            seen[y] = true;
        } 
        if (adj[x] != -1 && adj[x] != y) { cout << -1 << nl; return; }
        if (x == y) continue;
        adj[x] = y;
        // dbgm(a[i], out[i]);
    }
    if (count == 52) { cout << -1 << nl; return; }
    // dfs on each character (w/ visited to ensure no double counting)--> for each cycle ans++ since you need to in reality 
    //                       --> otherwise just number of edges as js the number of moves you need to take to make everything good :):
    dbg(adj);

    // sum of edges
    for (int i = 0; i < 52; i++)
        if (adj[i] != -1) ans++;

    // +1 for each cycle
    for (int i = 0; i < 52; i++) {
        if (adj[i] != -1) ins[adj[i]]++;
    }

    for (int i = 0; i < 52; i++) {
        if (visited[i] != -1) continue;
        int t = i;
        while (t != -1 && visited[t] == -1) {
            visited[t] = i;
            t = adj[t];
        }
        if (t != -1 && visited[t] == i) {
            int s = t;
            bool pass = ins[t] > 1;
            visited[t] = 1; t = adj[t];
            while (t != s) {
                visited[t] = 1;
                pass = ins[t] > 1;
                t = adj[t];
            }
            ans += (pass ? 0 : 1);
        }
    }
    
    cout << ans << nl;
}

void reset () {
    ans = 0;
    fill(all(visited), -1);
    fill(all(ins), 0);
    fill(all(adj), -1);
    fill(all(seen), false);
}

int main () {
    fastIO;

    int t; cin >> t;
    while (t--) { reset(); solve(); }

    return 0;
}
