//USACO 2016 December Contest, Bronze Problem 3. The Cow-signal
//DONE
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	int m, n, k; cin>>m>>n>>k;
	string signal [m];
	for (int i = 0; i<m; i++) 
		cin>>signal[i];

	vector<string> ans;
	string temp = "";
	for (int i = 0; i<m; i++) {
		temp = "";
		for (int j = 0; j<n; j++)
			temp+=string(k, signal[i][j]);	
		for (int x = 0; x<k; x++) ans.push_back(temp);
	}

	for (int i = 0; i<m*k; i++) cout<<ans[i]<<endl;

	return 0;
}
