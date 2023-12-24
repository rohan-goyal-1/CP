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
#include <sys/signal.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define endl '\n'
#define sp << ' ' <<
#define nl << '\n'
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
#define f first
#define s second
#define mp make_pair
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define srt(x) sort(all(x))
#define max(n, m) ((n > m) ? n : m)
#define min(n, m) ((n < m) ? n : m)
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

inline void setIO(string input = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (input.size()) {
    freopen((input + ".in").c_str(), "r", stdin);
    freopen((input + ".out").c_str(), "w", stdout);
  }
}

bool sorted(vll nums, ll n) {
  FOR(i, 0, n - 1)
    if (nums[i + 1] - nums[i] > 1) return false;
  return true;
}

void remove_elements(vll track, vll nums) {
  FOR(i, 0, nums.size()) {
    auto it = nums.begin() + nums[i] - 1;
    track.erase(it);
  }
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vll nums(n);
  FOR(i, 0, n) cin >> nums[i];

  if (nums[0] > 1) {
    cout << 1 nl;
    return;
  }

  if (sorted(nums, n)) {
    cout << (nums[n - 1] + 1) * k nl;
  }

  // priority_queue<ll, vector<ll>, greater<ll>> pq;
  // FOR(i, 0, n) {
  //   if (nums[i+1] - nums[1] == 1) continue;
  //   FOR(j, nums[i] + 1, nums[i+1]) pq.push(j);
  // }
  //
  // ll smallest;
  // while (k--) {
  //   smallest = pq.top();
  //   pq.pop();
  //   pq.push(smallest * 2);
  // }
  //
  // cout << smallest nl;
  
  vll track(nums[n-1]);
  FOR(i, 0, nums[n-1]) track[i] = i+1;

  while (k--) {
    remove_elements(track, nums);
    restore(track);
  }
  cout<<track[0] nl;
}

int main() {
  setIO("");

  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
