#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Class {
	int start, end;
};

Class classes[1000];

bool comp (const Class& a, const Class& b) {
	if (a.start == b.start) return a.end<b.end;
	return a.start<b.start;
}

int solve (int n) {
	sort(classes, classes+n, comp);
	
	int currTime;
	int count = 0;
	int max = 0;
	for (int i = 0; i<n; i++) {
		currTime = classes[i].start;
		count = 0;
		for (int j = i; j<n; j++) {
			currTime = classes[j].end;
			if (currTime>classes[j+1].start && j+1 != n) j++;
			count++;
		}
		if (count>max) max = count;
	}
	return max;
}

int main () {
	int n; cin>>n;
	for (int i = 0; i<n; i++) cin>>classes[i].start>>classes[i].end;
	
	cout<<solve(n)<<endl;
	return 0;
}
