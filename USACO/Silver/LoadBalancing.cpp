#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const string PROB_NAME = "balancing";

using P = pair<int, int>;

int n;
vector<P> x, y;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    freopen((PROB_NAME + ".in").c_str(), "r", stdin);
    freopen((PROB_NAME + ".out").c_str(), "w", stdout);
#endif // LOCAL

    cin >> n; x.resize(n), y.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> x[i].second;
        y[i] = x[i];
    }
    sort(begin(x), end(x), [] (P a, P b) -> bool { return a.first < b.first; });
    sort(begin(y), end(y), [] (P a, P b) -> bool { return a.second < b.second; });

    int ans = 2e9;
    for (int i = 0; i < n; ) {
        int vert = x[i].first + 1;
        vector<P> left, right;
        for (int i = 0; i < n; i++) {
            if (y[i].first < vert) left.push_back(y[i]);
            else right.push_back(y[i]);
        }
        int l = 0, r = 0;
        while (l + r < n) {
            int hor = y[l + r].second + 1;
            while (l < left.size() && left[l].second < hor) l++;
            while (r < right.size() && right[r].second < hor) r++;
            int arr[] = {l, r, int(left.size() - l), int(right.size() - r)};
            ans = min(ans, *max_element(begin(arr), end(arr)));
        }
        while (i < n && vert - 1 == x[i].first) i++;
    }

    cout << ans << '\n';

    return 0;
}
