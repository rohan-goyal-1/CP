#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
using ll = long long;
using ull = unsigned long long;

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

  ll n, x;
  cin >> n >> x;
  ll nums[n];

  map<ll, ll> track;
  track[0] = 1;
  ll sum = 0;
  ll ans = 0;
  fo(i, n) {
    cin >> nums[i];
    sum += nums[i];
    if (track.count(sum - x))
      ans += track[sum - x];
    track[sum]++;
  }
  cout << ans << endl;

  return 0;
}
