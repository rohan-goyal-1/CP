#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <limits.h>

using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
using ll = long long;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair

using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)

void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

ll N, B, ans = LONG_MAX;
ll tiles[250];
pll boots[250];
bool visited[250][250];

void dfs(ll tile, ll boot) {
  if (visited[tile][boot])
    return;
  visited[tile][boot] = 1;

  if (tile == N - 1) {
    ans = min(ans, boot);
    return;
  }

  for (int i = tile + 1; i < N && i - tile <= boots[boot].s; i++)
    if (boots[boot].f >= tiles[i]) dfs(i, boot);

  for (int b = boot + 1; b < B; b++)
    if (boots[b].f >= tiles[tile]) dfs(tile, b);
}

int main() {
  setIO("snowboots");

  cin >> N >> B;
  fo(i, N) cin >> tiles[i];
  fo(i, B) cin >> boots[i].f >> boots[i].s;

  dfs(0, 0);

  cout << ans << endl;

  return 0;
}
