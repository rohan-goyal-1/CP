#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;
#define endl '\n'
#define sp ' '
#define nl '\n'
#define fastIO cin.tie(NULL) -> sync_with_stdio(false)
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define max(n, m) ((n > m) ? n : m)
#define min(n, m) ((n < m) ? n : m)

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

inline void setIO (string input = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (input.size()) {
        freopen((input + ".in").c_str(), "r", stdin);
        freopen((input + ".out").c_str(), "w", stdout);
    }
}

int lcs(vector<int>& A, vector<int>& B) {
    int maxLCS = 0;
    int n = A.size();
    vector<int> rotatedA(2 * n);
    copy(A.begin(), A.end(), rotatedA.begin());
    copy(A.begin(), A.end(), rotatedA.begin() + n);

    for (int i = 0; i < n; i++) {
        vector<int> currentA(rotatedA.begin() + i, rotatedA.begin() + i + n);
        maxLCS = max(maxLCS, lcs(currentA, B));
    }

    return maxLCS;
}
int uncommon (vi& arr1, vi& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());
    unordered_set<int> symmetricDifference;

    for (int element : set1) {
        if (set2.find(element) == set2.end()) {
            symmetricDifference.insert(element);
        }
    }

    for (int element : set2) {
        if (set1.find(element) == set1.end()) {
            symmetricDifference.insert(element);
        }
    }

    return symmetricDifference.size();
}

int main () {
    fastIO;

    int n, k; cin >> n >> k;
    vi A(k), B(k);
    for (int& a : A) cin >> a;
    for (int& b : B) cin >> b;

    int result = lcs(A, B);
    int disjoint = uncommon(A, B);
    vi C = B;
    reverse(all(C));
    dbg(C);
    result = max(result, lcs(A, C));
    dbgm(result, disjoint);

    int ans = result;
    ans += max(0, n - k - disjoint);
    cout << ans << nl;

    return 0;
}
