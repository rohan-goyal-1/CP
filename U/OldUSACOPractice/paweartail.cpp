#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol = 0;

void update (int a [], int b [], int i, int n) {
	sol = max(sol, a[i] + b[n] - b[i]);
}

int main () {
	int n;
	cin>>n;
	
	int e[n+1], p[n+1], t[n+1];
	for (int i = 0; i<=n; i++) {
		e[i] = 0; 
		p[i] = 0;
		t[i] = 0;
	}

	char cur;
	for (int i = 0; i<n; i++) {
		e[i+1] = e[i];
		p[i+1] = p[i];
		t[i+1] = t[i];
		
		cin>>cur;
		if (cur == 'E') e[i+1]++;
		else if (cur == 'P') p[i+1]++;
		else t[i+1]++;
	}
	
	for (int i = 1; i <= n; i++) {
		update(e, p, i, n);
		update(e, t, i, n);
		update(p, t, i, n);
		update(p, e, i, n);
		update(t, e, i, n);
		update(t, p, i, n);

	}
	
	cout<<sol<<endl;

	return 0;
}
