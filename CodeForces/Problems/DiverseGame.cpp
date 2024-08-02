#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

void _solve () {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (n * m == 1) {
                cout << "-1\n";
                return;
            }
            grid[i][j]++;
            if (grid[i][j] > n * m) grid[i][j] %= n * m;
            cout << grid[i][j] << " \n"[j == m - 1];
        }
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
