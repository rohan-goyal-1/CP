//USACO 2019 February Contest, Bronze Problem 3. Measuring Traffic
//NOT DONE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

struct Sensor {
	string ramp;
	int lower, upper;
};

int main () {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	Sensor sensors[n];
	for (int i = 0; i<n; i++) cin>>sensors[i].ramp>>sensors[i].lower>>sensors[i].upper;
	
	int low = -999999999; int up = 999999999;
	for (int i = n-1; i>=0; i--) {
		if (sensors[i].ramp == "none") { low = max(low, sensors[i].lower); up = min(up, sensors[i].upper); }
		if (sensors[i].ramp == "off") { low += sensors[i].lower; up += sensors[i].upper; }
		if (sensors[i].ramp == "on") { low -= sensors[i].lower; up -= sensors[i].upper; low = max(0, low);}
	}
	cout<<low<<" "<<up<<'\n';

	low = -999999999; up = 999999999;
	for (int i = 0; i<n; i++) {
		if (sensors[i].ramp == "none") { low = max(low, sensors[i].lower); up = min(up, sensors[i].upper); }
		if (sensors[i].ramp == "off") { up -= sensors[i].lower; low -= sensors[i].upper; low = max(0, low);}
		if (sensors[i].ramp == "on") { up += sensors[i].lower; low += sensors[i].upper; }
	}
	cout<<low<<" "<<up<<'\n';

	return 0;
}
