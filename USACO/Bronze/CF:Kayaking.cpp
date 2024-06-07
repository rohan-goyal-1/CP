#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

#define endl '\n'
#define ll long long

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	int weights[2*n]; for (int i : weights) cin>>i;
	
	sort(weights, weights+n);

	int index, maxD = INT_MIN;
	for (int i = 0; i<2*n-1; i++) {
		if (weights[i+1]-weights[i] > maxD) { maxD = weights[i+1]-weights[i]; index = i+1; }
	}

	vector<int> optimized;
	for (int i = 0; i<2*n; i++) {
		if (i == index) continue;
		optimized.push_back(weights[i]);
	}
	sort(optimized.begin(), optimized.end());
	maxD = INT_MIN;
	for (int i = 0; i<2*n-2; i++) {
		if (optimized[i+1]-optimized[i] > maxD) { maxD = optimized[i+1]-optimized[i]; index = i+1; }
	}

	vector<int> ans;
	for (int i = 0; i<2*n-1; i++) {
		if (i == index) continue;
		ans.push_back(optimized[i]);
	}
	sort(ans.begin(), ans.end());
	maxD = INT_MIN;
	for (int i = 0; i<2*n-3; i++) {
		if (ans[i+1]-ans[i] > maxD) maxD = ans[i+1]-ans[i];
	}

	cout<<maxD<<endl;

	return 0;
}
