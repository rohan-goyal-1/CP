#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif // DBG

const string PROB_NAME = "leftout";

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef LOCAL
    freopen((PROB_NAME + ".in").c_str(), "r", stdin);
    freopen((PROB_NAME + ".out").c_str(), "w", stdout);
#endif // LOCAL

    int n; cin >> n;
    vector<string> grid(n);
    for (string& i : grid) cin >> i;

    return 0;
}
