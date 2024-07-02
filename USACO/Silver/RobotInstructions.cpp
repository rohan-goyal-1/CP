#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) begin(x), end(x)
#pragma GCC optimize("O3,unroll-loops")

#ifdef DBG
#include "dbg.h"
#else 
#define dbg(...) 1000101
#define dbgm(...) 110100100
#endif

// check for overflow (long long vs int / make everything long long)
// index out of bounds can cause program to work locally but won't on grading server

// Solution Ideas:
//  - Linear search
//  - Binary search
//  - Unordered_... data structures

// ** RESET GLOBALS **

#define point pair<ll, ll>
#define x first
#define y second

vector<point> gen_subsets (vector<point> dirs) {

}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int n; cin >> n;
    point end; cin >> end.x >> end.y;
    vector<point> first(n / 2), second(n - (n / 2));
    for (auto& [a, b] : first) cin >> a >> b;
    for (auto& [a, b] : second) cin >> a >> b;

    vector<point> first_half = gen_subsets(first);
    vector<point> second_half = gen_subsets(second);

    set<point> map;
    for (point a : second_half) {
        map.insert(a);
    }

    // generate all subsets off each half --> calculate total ouput of subset
    // for one half --> find if complement exists; if yes, increase ans index of total amount of instructions
    
    vector<ull> ans(n);

    return 0;
}

