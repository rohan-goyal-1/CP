#include <algorithm>
#include <cstdio>
#include <iostream>
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
  setIO("reststops");

  ll L, N, rF, rB;
  cin >> L >> N >> rF >> rB;
  vector<pll> grass(N);
  fo(i, N) cin >> grass[i].f >> grass[i].s;

  vector<bool> best(N);
  ll max = 0;
  for (ll i = N-1; i>=0; i--) {
    if (grass[i].s>max) {
      best[i] = true;
      max = grass[i].s;
    }
  }

  ll ans = 0, Ftime = 0, Btime = 0, curr = 0;
  fo(i, N) {
    if (best[i]) {
      Btime = (grass[i].f - curr) * rB;
      Ftime = (grass[i].f - curr) * rF;
      ans += (Ftime - Btime) * grass[i].s;
      curr = grass[i].f;
    }
  }
  cout<<ans<<endl;

  return 0;
}
