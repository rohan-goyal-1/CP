#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

struct Board {
	int x1, y1, x2, y2;
};

int area (pair<int, int> a, pair<int, int> b) {
	int w = abs(a.second - b.second);
	int l = abs(a.first - b.first);
	return l*w;
}
int solve (Board lawn, Board grass) {
	if (lawn.y2<=grass.y2 && lawn.y1>=grass.y1 && lawn.x1>=grass.x1 && lawn.x2<=grass.x2) return 0;
	if (lawn.x1>=grass.x1 && lawn.x2<=grass.x2 && lawn.y1<=grass.y2 && lawn.y1>=grass.y1) return area(make_pair(lawn.x2, lawn.y2), make_pair(lawn.x1, grass.y2));
	if (lawn.x1>=grass.x1 && lawn.x2<=grass.x2 && lawn.y2>=grass.y1 && lawn.y2<=grass.y2) return area(make_pair(lawn.x1, lawn.y1), make_pair(lawn.x2, grass.y1));
	if (lawn.y2<=grass.y2 && lawn.y1>=grass.y1 && lawn.x1<=grass.x2 && lawn.x1>=grass.x1) return area(make_pair(lawn.x2, lawn.y2), make_pair(grass.x2, lawn.y1));
	if (lawn.y1>=grass.y1 && lawn.y2<=grass.y2 && lawn.x2<=grass.x2 && lawn.x2>=grass.x1) return area(make_pair(lawn.x1, lawn.y1), make_pair(grass.x1, lawn.y2));
	return area(make_pair(lawn.x1, lawn.y1), make_pair(lawn.x2, lawn.y2));	
}

int main () {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Board lawn; cin>>lawn.x1>>lawn.y1>>lawn.x2>>lawn.y2;
	Board grass; cin>>grass.x1>>grass.y1>>grass.x2>>grass.y2;

	cout<<solve(lawn, grass)<<endl;
	
	return 0;
}
