#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
//	freopen("blocks.in", "r", stdin);
//	freopen("blocks.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	string a[n], b[n];
	for (int i  = 0; i<n; i++) cin>>a[i]>>b[i];
	
	int t1[26], t2[26], ans[26];
	fill(ans, ans+26, -1);
	for (int i = 0; i<n; i++) {
		fill(t1, t1+26, 0);
		for (auto c : a[i]) t1[int(c)-97]++;
		fill(t2, t2+26, 0);
		for (auto c : b[i]) t2[int(c)-97]++;

		for (int j = 0; j<26; j++) ans[j] = max(ans[j], max(t1[j], t2[j]));
	}
	for (int a : ans) cout<<a<<'\n';
	
	return 0;
}
