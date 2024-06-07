#include <iostream>
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
	
	int n, k; cin>>n>>k;
	int a, b;
	int diff[n+1]; fill(diff, diff+n+1, 0);
	for (int i = 0; i<k; i++) {
		cin>>a>>b;
		--a; --b;
		diff[a]++;
		diff[b+1]--;
	}
	
	int prefix[n+1]; prefix[0] = diff[0];
	for (int i = 1; i<n; i++) {
		prefix[i] = prefix[i-1]+diff[i];
	}
	sort(prefix, prefix+n+1);
	cout<<prefix[(n+1)/2]<<endl;

	return 0;
}
