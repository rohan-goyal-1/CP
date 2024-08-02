#include <bits/stdc++.h>

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

using namespace std;
using i64 = int64_t;
#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> s(n); for (int& i : s) cin >> i;

    for (int i = 0; i < n - 1; i++) {
        if (abs(s[i + 1] - s[i]) > m) {
            if (s[i + 1] > s[i]) s[i] = s[i + 1] - m;
            else s[i + 1] = s[i] - m;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (abs(s[i - 1] - s[i]) > m) {
            if (s[i - 1] > s[i]) s[i] = s[i - 1] - m;
            else s[i - 1] = s[i] - m;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << " \n"[i == n - 1];
    }

    return 0;
}
