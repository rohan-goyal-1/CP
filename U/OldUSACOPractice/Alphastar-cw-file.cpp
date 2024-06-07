#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

bool cmp (pair <int, bool> a, pair <int, bool> b) {
	return a.first<b.first;
}

int main () {
	int n, a, b;

	cin>>n>>a>>b;
	
	pair <int, bool> bunnies[n];
	int babies [b-a+1] = {0};

	string temp;
	for (int i = 0; i<n; i++) {
		cin>>bunnies[i].first;
		cin>>temp;
		bunnies[i].second = (temp == "S") ? true : false;
	}

	sort(bunnies, bunnies+n, cmp);

	for (int i = 0; i<n; i++) {
		if (bunnies[i].second) {

	return 0;
}
