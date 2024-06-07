#include <iostream>

using namespace std;

struct point {
	int x, y;
};

int main () {
	point g1, g2, l1, l2;
	
	cin>>l1.x>>l1.y>>l2.x>>l2.y>>g1.x>>g1.y>>g2.x>>g2.y;
	
	int ans = 0;

	if (g2.y >= l2.y && g2.x >= l2.x && g1.y <= l1.y && g1.x <=l1.x) {
		ans = 0;
	}
	else if (g2.y>=l2.y && g1.y<=l1.y && l1.x<g2.x && g1.x<l1.x && l2.x>g2.x) {
		ans = (l2.y-l1.y) * (l2.x-g2.x);
	}
	else if (g2.y>=l2.y && g1.y<=l1.y && l2.x>g1.x && l2.x<g2.x && l1.x<g1.x) {
		ans = (l2.y-l1.y) * (g1.x-l1.x);
	}
	else if (g2.x>=l2.x && g1.x<=l1.x && l2.y>g1.y && l2.y<g2.y && l1.y<g1.y) {
		ans = (l2.x-l1.x) * (g1.y-l1.y);
	}
	else if (g2.x>=l2.x && g1.x<=l1.x && l1.y<g2.y && l1.y>g1.y && l2.y>g2.y) {
		ans = (l2.x-l1.x) * (l2.y-g2.y);
	}
	else {
		ans = (l2.x-l1.x) * (l2.y-l1.y);
	}

	cout<<ans;

	return 0;
}
