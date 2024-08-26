#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

string to_lower (string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a') s[i] = s[i] - 'a' + 'A';
    }
    return s;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s, t; cin >> s >> t;
    s = to_lower(s), t = to_lower(t);

    cout << clamp(s.compare(t), -1, 1) << '\n';

    return 0;
}
