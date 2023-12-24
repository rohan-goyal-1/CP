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

ll barn[1001][1001];
int main() {
  setIO();

  ll n, k;
  cin >> n >> k;
  fo(i, n) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    barn[x1][y1]++;
    barn[x1][y2]--;
    barn[x2][y1]--;
    barn[x2][y2]++;
  }

  ll ans = 0;
  fo(i, 1000) {
    fo(j, 1000) { 
      if (i) barn[i][j] += barn[i-1][j]; 
      if (j) barn[i][j] += barn[i][j-1]; 
      if (i && j) barn[i][j] -= barn[i-1][j-1];
      ans += barn[i][j] == k;
    }
  }
  cout<<endl<<endl<<ans<<endl;

  return 0;
}
