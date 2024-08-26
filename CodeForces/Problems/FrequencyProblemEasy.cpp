#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n), cnt(101);
    for (int& i : a) cin >> i, cnt[i]++;

    return 0;
}
