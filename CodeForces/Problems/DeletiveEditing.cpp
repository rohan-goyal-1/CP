#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

void solve () {
    string a, b; cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    map<char, int> mp;
    for (char c : b) mp[c]++;
    string b2 = "";
    for (char c : a) {
        if (mp[c] > 0) {
            mp[c]--;
            b2 += c;
        }
    }
    cout << (b2 == b ? "YES" : "NO") << '\n';
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
