//USACO 2016 January Contest, Bronze Problem 3. Mowing the Field
//DONE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int last[2001][2001];
int main () {
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin>>n;
	char d[n]; int l[n];
	for (int i = 0; i<n; i++) cin>>d[i]>>l[i];

	fill(&last[0][0], &last[0][0] + 2001*2001, -1);

	unsigned int X = 1000,  Y = 1000, dX = 0, dY = 0, ans = INT_MAX, t = 1, local = 0;
	last[Y][X] = 0;
	for (int i = 0; i<n; i++) {
		dX = 0; dY = 0;
		if (d[i] == 'N') dY = 1;
		if (d[i] == 'S') dY = -1;
		if (d[i] == 'W') dX = -1;
		if (d[i] == 'E') dX = 1;
		for (int j = 0; j<l[i]; j++) {
			X+=dX; Y+=dY;
			if (last[Y][X] != -1) {
				local = t-last[Y][X];
				ans = min(ans, local);
			}
			last[Y][X] = t;
			t++;
		}
	}
	if (ans == INT_MAX) cout << -1 << endl;
	else cout<<ans<<'\n';

	return 0;
}
