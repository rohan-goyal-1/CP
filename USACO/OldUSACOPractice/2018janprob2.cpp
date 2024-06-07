#include <iostream>
#include <algorithm> 

using namespace std;

struct guard {
	int start, end;
};
bool compare (guard a, guard b) {
	return a.start<b.start;
}
int main () {
	int n;
	cin>>n;
	guard lifeguards[n];
	for (int i = 0; i<n; i++) {
		cin>>lifeguards[i].start>>lifeguards[i].end;
	}
	sort (lifeguards, lifeguards+n, compare);
	int elim = 0;
	int max = 0;
	int temp = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (elim == j) continue;
			if (j == 0) {
				temp+=lifeguards[j].end-lifeguards[j].start;
				continue;
			}
			if ((j-1)!=elim) {
				if (lifeguards[j].start<lifeguards[j-1].end) {
					temp+=lifeguards[j].end-lifeguards[j].start;
					temp-=lifeguards[j-1].end-lifeguards[j].start;
					continue;
				}
			}
			else {
				if (lifeguards[j].start<lifeguards[j-2].end) {
					temp+=lifeguards[j].end-lifeguards[j].start;
					temp-=lifeguards[j-2].end-lifeguards[j].start;
					continue;
				}
			}
			temp+=lifeguards[j].end-lifeguards[j].start;
		}
		if (temp>max) max = temp;
		elim++;
		temp = 0;
	}
	cout<<max<<endl;

	return 0;
}
