#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
#include "dbg.h"
#else
#define dbg(...)
#define dbgm(...)
#endif // DBG

vector<int> adj, ans;
vector<bool> visited;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n); ans.resize(n, -1); visited.resize(n);
    for (int& i : adj) cin >> i, i--;

    for (int i = 0; i < n; i++) {
        int a = i, len = 0;
        while (!visited[a]) {
            visited[a] = true;
            a = adj[a];
            len++;
        }
        int temp = len;
        len += ans[a];
        int b = i;
        bool flag = true;
        for (int j = 0; j < temp; j++) {
            if(a == b)
                flag = false;
            ans[b] = len;
            b = adj[b];
            if (flag)
                len--;
        }
    }

    for (int i = 0; i < n; i++)
        cout << ++ans[i] << " \n"[i == n - 1];

    return 0;
}
