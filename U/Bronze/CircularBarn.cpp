//USACO 2016 February Contest, Bronze Problem 2. Circular Barn
//DONE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

int main () {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	int r [n];
	for (int i = 0; i<n; i++) cin>>r[i];

	int ans = 999999999, step, local;
	for (int i = 0; i<n; i++) {
		step = 1; local = 0;
		for (int j = 1; j<n; j++) {
			local+=r[(i+j)%n]*step;
			step++;
		}
		ans = min(local, ans);
	}

	cout<<ans<<'\n';

	return 0;
}
