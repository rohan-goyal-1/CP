#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int n; cin >> n;
    vector<int> h(n); for (int& i : h) cin >> i;
    vector<vector<int>> adj(n);
    for (int _ = 0; _ < 2; _++) {
        for (int i = 0; i < n; i++)
            h[i] *= -1;

        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && h[s.top()] < h[i]) {
                adj[s.top()].emplace_back(i);
                s.pop();
            }
            if (!s.empty()) {
                adj[s.top()].emplace_back(i);
                if (h[s.top()] == h[i]) s.pop();
            }

            s.push(i);
        }
    }

    vector<int> dp(n, -1);
    queue<pair<int, int>> q({{0, 0}});
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        if (dp[a] != -1) continue;
        dp[a] = b;
        for (int i : adj[a]) {
            q.push({i, b + 1});
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}
