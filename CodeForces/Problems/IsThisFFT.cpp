#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    cout << "0\n" << "1\n";
    cout << n << '\n';
    for (int i = 0; i < n + 1; i++) {
        int a; cin >> a;
        cout << a << " \n"[i == n];
    }

    return 0;
}
