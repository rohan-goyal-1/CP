#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) begin(x), end(x)
#pragma GCC optimize("O3,unroll-loops")

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server

// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

vector<int> a, c;

struct cmp {
    bool operator() (const pair<int, ll>& x, const pair<int, ll>& y) {
        return x.second > y.second;
    }
};

void solve () {
    int h, n; cin >> h >> n;
    a.resize(n); c.resize(n);
    for (int& i : a) cin >> i;
    for (int& i : c) cin >> i;

    priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> pq;
    for (int i = 0; i < n; i++) {
        pq.push({i, 1});
    }
    ll t;
    while (h > 0) {
        pair<int, ll> top = pq.top(); pq.pop();
        // dbg(top);
        t = top.second;
        h -= a[top.first];
        pq.push({top.first, top.second + c[top.first]});
    }

    cout << t << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
