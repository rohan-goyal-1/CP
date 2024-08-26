#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

bool worked (string s, string t) {
    int j = 0;
    for (int i = 0; i < (int) s.size() && j < (int) t.size(); i++) {
        if (s[i] == t[j]) {
            j++;
        }
    }
    return j == (int) t.size();
}

void solve () {
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (j < m) {
                s[i] = t[j++];
            }
            else {
                s[i] = 'a';
            }
        }
        else if (j < m && s[i] == t[j]) {
            j++;
        }
    }
    if (worked(s, t)) {
        cout << "YES\n";
        cout << s << '\n';
    }
    else {
        cout << "NO\n";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
