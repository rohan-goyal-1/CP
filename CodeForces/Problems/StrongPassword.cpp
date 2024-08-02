#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

char next_char (char c) {
    int idx = c - 'a';
    idx++;
    idx %= 26;
    return char(idx + 'a');
}

void solve () {
    string s; cin >> s;
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << s.substr(0, i + 1) + next_char(s[i]) + s.substr(i + 1) << '\n';
            return;
        }
    }
    cout << next_char(s[0]) + s << '\n';
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
