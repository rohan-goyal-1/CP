#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

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

int main() {
  setIO("helpcross");

  ll C, N;
  cin >> C >> N;
  vll chickens(C);
  fo(i, C) cin >> chickens[i];
  vector<pll> cows(N);
  fo(i, N) cin >> cows[i].f >> cows[i].s;

  sort(all(cows)), sort(all(chickens));

  ll ans = 0, index = 0;
  priority_queue<ll> valid;
  for (ll c : chickens) {
    while (index < N && cows[index].f <= c) {
      valid.push(-cows[index].s);
      index++;
    }

    while (!valid.empty() && -valid.top() < c)
      valid.pop();

    if (!valid.empty()) {
      ans++;
      valid.pop();
    }
  }
  cout << ans << endl;

  return 0;
}
