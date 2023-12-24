#include <iostream>
#include <utility>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
using ll = long long;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	vector<pair<int, int> > events;
	int a, b;
	for (int i = 0; i<n; i++) {
		cin>>a>>b;
		events.push_back(make_pair(a, 1));
		events.push_back(make_pair(b, -1));
	}

	sort(events.begin(), events.end());
	
	int x = 0, ans = 0;
	for (pair<int, int> &e : events) {
		x += e.second;
		ans = max(ans, x);
	}

	cout<<ans<<endl;

	return 0;
}
