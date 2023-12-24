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

inline void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();

  ll n, x;
  cin >> n >> x;
  vector<pll> nums(n);
  fo(i, n) {
    cin >> nums[i].f;
    nums[i].s = i + 1;
  }

  sort(all(nums));

  fo(i, n) {
    ll l = 0ll;
    ll r = n - 1;
    while (l < r) {
      if (nums[l].f + nums[r].f + nums[i].f == x && r != i && l != i) {
        cout << nums[l].s << ' ' << nums[r].s << ' ' << nums[i].s << endl;
        return 0;
      }

      if (nums[l].f + nums[r].f + nums[i].f > x)
        r--;
      else
        l++;
    }
  }
  cout << "IMPOSSIBLE" << endl;

  return 0;
}
