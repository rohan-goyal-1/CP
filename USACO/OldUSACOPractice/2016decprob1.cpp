#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdin);
	int x [4];
	int y [4];
	for (int i = 0; i<4; i++) {
		cin>>x[i];
		cin>>y[i];
	}

	sort (x,x+4);
	sort (y, y+4);
	int xdim = x[3] - x[0];
	int ydim = y[3] - y[0];
	
	if (xdim>ydim) cout<<xdim*xdim;
	else cout<<ydim*ydim;
	cout<<endl;
	
	return 0;
}
