#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
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
  setIO();

  ll n;
  cin >> n;
  pll movies[n];
  fo(i, n) cin >> movies[i].s >> movies[i].f;

  sort(movies, movies + n);

  ll currTime = -1, ans = 0;
  fo(i, n) {
    if (movies[i].s >= currTime) {
      ans++;
      currTime = movies[i].f;
    }
  }
  cout << ans << endl;

  return 0;
}
