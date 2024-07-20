#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server

// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

void _solve () {
    int n; cin >> n;

    vector<pair<int, int>> ans;
    string s = "";
    for (int i = 1; i <= 10000; i++) {
        s += to_string(n);
		for (int j = max(1, (int) s.size()-6); j <= min(10000, i*100) && j < s.size(); j++) {
            if (to_string(n*i - j) == s.substr(0, s.size() - j)) {
				ans.push_back({i, j});
			}
        }
    }

    cout << ans.size() << '\n';
    for (auto& [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
