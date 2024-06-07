#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> ind;
int calc (int a, int b, string stalls, int n) {
	stalls[a] = '1';
	stalls[b] = '1';
	int ret = INT_MAX; 
	for (int i = 0; i<n; i++) {
		if (stalls[i] =='1') 
			ind.push_back(i);
	}
	for (int i = 0; i<ind.size()-1; i++) {
		if (ind[i+1]-ind[i]<ret) 
			ret = ind[i+1]-ind[i];
	}
	stalls[a] = '0'; stalls[b] = '0';
	ind.clear();

	return ret;

}
int main () {
	int n;
	cin>>n;
	string stalls;
	cin>>stalls;
	
	int d = INT_MIN;
	int temp;
	for (int i = 0; i<n; i++) {
		if (stalls[i] == '1') continue;
		for (int j = i+1; j<n; j++) {
			if (stalls[j] == '1') continue;
			temp = calc (i, j, stalls, n);
			if (temp>d) d = temp;
		}
	}
	cout<<d<<endl;

	return 0;
}
