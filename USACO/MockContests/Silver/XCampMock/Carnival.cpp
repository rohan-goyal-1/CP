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

    int n, p; cin >> n >> p;
    vi blocks(n);
    priority_queue<pi> pq;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
        pq.push({blocks[i], i});
    }
    vi set(n, 0);
    int turns = 0;
    while (!pq.empty()) {
        dbg(set);
        pi highest = pq.top();
        dbg(highest);
        pq.pop();
        highest.first -= (turns - set[highest.second]);
        if (turns - set[highest.second] > 0) {
            pq.push(highest);
            set[highest.second] = turns;
            continue;
        }
        if (highest.first > 0) { 
            turns++;
        }
        highest.first -= min(highest.first, p);
        if (highest.first > 0) { 
            pq.push(highest);
            set[highest.second] = turns;
        }
    }
    cout << turns << nl;

    return 0;
}
