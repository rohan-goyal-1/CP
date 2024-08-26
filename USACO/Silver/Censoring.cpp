#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define set_io(x)                                       \
    freopen((string(x) + ".in").c_str(), "r", stdin);   \
    freopen((string(x) + ".out").c_str(), "w", stdout);

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    set_io("censor");
#endif

    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    string ret;

    vector<int> pi(m, 0);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && t[k] != t[i])
            k = pi[k - 1];
        if (t[k] == t[i])
            k++;
        pi[i] = k;
    }

    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && t[q] != s[i])
            q = pi[q - 1];
        if (t[q] == s[i])
            q++;
        ret += s[i];
        if (q == m) {
            ret = ret.substr(0, ret.size() - m);
            int x = ret.size();
            q = 0;
            if (x >= m) {
                q = pi[m - 1];
                for (int j = x - m; j < x; j++) {
                    while (q > 0 && t[q] != ret[j])
                        q = pi[q - 1];
                    if (t[q] == ret[j])
                        q++;
                }
            }
        }
    }

    cout << ret << '\n';

    return 0;
}
