#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

int main () {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif

    int l = 1, r = int(1e6);
    while (l < r) {
        int mid = (l + r + 1) / 2;
        cout << mid << endl;
        string s; cin >> s;
        if (s == "<") r = mid - 1;
        else l = mid;
    }

    cout << "! " << l << endl;

    return 0;
}
