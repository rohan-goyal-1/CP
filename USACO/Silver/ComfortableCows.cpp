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

const int dX[4]{1, 0, -1, 0}, dY[4]{0, 1, 0, -1};

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server
//
// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

int ans, n;
bool visited[2001][2001];

bool comfy (int a, int b) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int nX = a + dX[i], nY = b + dY[i];
        count += visited[nX][nY] ? 1 : 0;
    }
    return count == 3;
}

pi find_empty (int a, int b) {
    for (int i = 0; i < 4; i++) {
        int nX = a + dX[i], nY = b + dY[i];
        if (!visited[nX][nY]) return {nX, nY};
    }
    return {-1, -1};
}


int main () {
    fastIO;

    cin >> n;
    int cur = 0;
    queue<pi> cows;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        a += 1000, b += 1000;
        queue<pi> q; q.push({a, b});
        while (!q.empty()) {
            pi top = q.front(); q.pop();
            int x = top.first, y = top.second;
            if (visited[x][y]) continue;
            cur++; visited[x][y] = true;
            if (comfy(x, y)) q.push(find_empty(x, y));
            for (int j = 0; j < 4; j++) {
                int nX = x + dX[j], nY = y + dY[j];
                if (comfy(nX, nY) && visited[nX][nY])
                    q.push(find_empty(nX, nY));
            }
        }
        cout << cur - (i + 1) << nl;
    }

    return 0;
}
