#include <algorithm>
#include <array>
#include <cassert>
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
#pragma GCC optimize("O3,unroll-loops")

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

// ** RESET GLOBALS **

vector<vi> adj;
vector<vi> paths;
vector<bool> visited;
int num_leaves = 0;
vector<int> pots;

const int NIL = 0;
const int INF = INT_MAX;

// A class to represent Bipartite graph for Hopcroft Karp implementation
class BipGraph {
    int m;    // Number of sets
    int n;    // Number of numbers across all sets
    vector<int> *adj; // Adjacency list
    vector<int> pairU, pairV, dist;

public:
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    int hopcroftKarp();
};

BipGraph::BipGraph(int m, int n) {
    this->m = m;
    this->n = n;
    adj = new vector<int>[m + 1];
}

void BipGraph::addEdge(int u, int v) {
    adj[u].push_back(v); // Add u to v’s list.
}

bool BipGraph::bfs() {
    queue<int> Q;
    for (int u = 1; u <= m; u++) {
        if (pairU[u] == NIL) {
            dist[u] = 0;
            Q.push(u);
        } else {
            dist[u] = INF;
        }
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL]) {
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = *i;
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool BipGraph::dfs(int u) {
    if (u != NIL) {
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = *i;
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v]) == true) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int BipGraph::hopcroftKarp() {
    pairU = vector<int>(m + 1, NIL);
    pairV = vector<int>(n + 1, NIL);
    dist = vector<int>(m + 1);

    int result = 0;
    while (bfs()) {
        for (int u = 1; u <= m; u++)
            if (pairU[u] == NIL && dfs(u))
                result++;
    }
    return result;
}

int maximizeSetsPick(vector<set<int>> &numberSets) {
    int m = numberSets.size();
    map<int, int> numberMap;
    int numberCounter = 1;

    // Create a bipartite graph
    for (const auto &s : numberSets) {
        for (int num : s) {
            if (numberMap.find(num) == numberMap.end()) {
                numberMap[num] = numberCounter++;
            }
        }
    }

    BipGraph g(m, numberCounter - 1);
    for (int i = 0; i < m; i++) {
        for (int num : numberSets[i]) {
            g.addEdge(i + 1, numberMap[num]);
        }
    }

    return g.hopcroftKarp();
}

void count_leaves (int v, vi& path) {
    if (visited[v]) return;
    visited[v] = true;
    path.pb(v);
    if (adj[v].size() == 1 && v != 0) { num_leaves++; paths.pb(path); }
    else {
        for (int i : adj[v]) count_leaves(i, path);
    }
    path.pop_back();
}

int main () {
    fastIO;
#ifdef LOCAL
    clock_t tStart = clock();
#endif

    int n; cin >> n; adj.resize(n); visited.resize(n, false); pots.resize(n, 0);
    vi temp2(n);
    for (int i = 0; i < n; i++) {
        cin >> temp2[i];
        temp2[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].pb(b); adj[b].pb(a);
    }
    vi temp;
    count_leaves(0, temp);
    for (int i = 0; i < num_leaves; i++) pots[temp2[i]] = 1;
    vector<set<int>> paths2;
    for (vi& p : paths) {
        paths2.pb(set<int>());
        for (int i : p) if (pots[i]) paths2.back().insert(i);
    }
    dbgm(paths2);
    cout << maximizeSetsPick(paths2) << nl;

#ifdef LOCAL
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << '\n';
#endif

    return 0;
}

