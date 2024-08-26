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

    int n; cin >> n;

    vector<int> p(n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        auto query = [&] (int a, int b) -> int {
            cout << "? " << a + 1 << ' ' << b + 1 << endl;
            int c; cin >> c;
            return c;
        };
        int x = query(i, j);
        int y = query(j, i);
        if (x > y) {
            p[i] = x;
        }
        else {
            p[j] = y;
            j = i;
        }
    }
    p[j] = n;

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;

    return 0;
}
