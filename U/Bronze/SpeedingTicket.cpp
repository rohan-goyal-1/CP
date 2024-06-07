//USACO 2015 December Contest, Bronze Problem 2. Speeding Ticket
//DONE
#include <iostream>
#include <cstdio>

using namespace std;

struct Segment {
	int dist, speed;
};
int main () {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	int n, m; cin>>n>>m;
	Segment law [n];
	Segment bessie [m];
	for (int i = 0; i<n; i++) cin>>law[i].dist>>law[i].speed;
	for (int i = 0; i<m; i++) cin>>bessie[i].dist>>bessie[i].speed;

	int miles [100];
	int currMile = 0;
	for (int i = 0; i<n; i++) {
		for (int j = currMile; j<currMile+law[i].dist; j++) {
			miles[j] = law[i].speed;
		}
		currMile+=law[i].dist;
	}
	currMile = 0;
	int milesB [100];
	for (int i = 0; i<m; i++) {
		for (int j = currMile; j<currMile+bessie[i].dist; j++) {
			milesB[j] = bessie[i].speed;
		}
		currMile+=bessie[i].dist;
	}

	int ans = 0;
	for (int i = 0; i<100; i++)
		if (milesB[i]-miles[i]>ans) ans = milesB[i]-miles[i];

	cout<<ans<<'\n';

	return 0;
}
