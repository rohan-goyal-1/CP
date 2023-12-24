#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
using ll = long long;

void solve () {
	int n; cin>>n;
	string nums; cin>>nums;
	
	int prefix[n+1]; prefix[0] = 0;
	for (int i = 0; i<n; i++)
		prefix[i+1] = prefix[i] + (nums[i] - '0');
	
//	for (int i = 0; i<n+1; i++) cout<<prefix[i]<<' ';
//	cout<<endl;
	int ans = 0;
	for (int i = 1; i<n+1; i++) {
		for (int j = i; j<n+1; j++) {
			if (prefix[j]-prefix[i-1] == j-i+1) ans++;
		}
	}
	cout<<ans<<endl;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin>>t;
	while (t--)
		solve();
	
	return 0;
}
