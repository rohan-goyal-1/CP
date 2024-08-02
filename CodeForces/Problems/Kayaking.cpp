#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

int n, x;

int solve (vector<int>& a) {
    int sum = 0;
    for (int i = 1; i < x - 2; i+= 2) {
        sum += a[i] - a[i - 1];
    }
    return sum;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    x = 2 * n;
    vector<int> w(x); for (int& i : w) cin >> i;
    sort(w.begin(), w.end());

    int ans = INT32_MAX;
    for (int i = 0; i < x; i++) {
        for (int j = i + 1; j < x; j++) {
            auto t = w;
            t.erase(t.begin() + j); t.erase(t.begin() + i);
            ans = min(ans, solve(t));
        }
    }
    cout << ans << '\n';

    return 0;
}
