#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int k [200];
int n, a, b;

int solve () {
	unordered_set<int> visited;
	queue<pair<int, int> > q;
	pair<int, int> temp;

	q.push(temp);
	visited.insert(a);

	while (!q.empty()) {
		int floor = q.front().first;
		int press = q.front().second;
		q.pop();

		if (floor == b) return press; 

		int ki = k[floor];

		int floor_up = floor + ki;
		if (floor_up <= n-1 && visited.find(floor_up) == visited.end()) {
			temp.first = floor_up; temp.second = press+1;
			q.push(temp);
			visited.insert(floor_up);
		}

		int floor_down = floor - ki;
		if (floor_down >= 0 && visited.find(floor_down) == visited.end()) {
			temp.first = floor_down; temp.second = press+1;
			q.push(temp);
			visited.insert(floor_down);
		}
	}
	return -1;
}

int main() {
	cin>>n>>a>>b;
	for (int i = 0; i<n; i++) cin>>k[i];
	int end;
	cin>>end;

	int ans = solve();
	cout<<ans<<endl;
	return 0;
}
