#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  int prefix[n + 1][n + 1];
  char a;

  memset(prefix, 0, sizeof(prefix));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a;
      prefix[i][j] = (a == '*') + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
  }

  for (int i = 0; i < q; i++) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << prefix[y2][x2] - prefix[y2][x1 - 1] - prefix[y1 - 1][x2] + prefix[y1 - 1][x1 - 1] << endl;
  }

  return 0;
}
