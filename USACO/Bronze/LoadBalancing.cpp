//USACO 2016 February Contest, Bronze Problem 3. Load Balancing
//DONE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

#define endl '\n'
#define ll long long

struct Point {
	int x, y;
};
int n, b;
Point points[100];

int calcM(int x, int y) {
	int quadrants[4]; fill(quadrants, quadrants+4, 0);
	for (int i = 0; i<n; i++) {
		if (points[i].x>x && points[i].y>y) quadrants[0]++;
		if (points[i].x>x && points[i].y<y) quadrants[3]++;
		if (points[i].x<x && points[i].y>y) quadrants[1]++;
		if (points[i].x<x && points[i].y<y) quadrants[2]++;
	}
	return max(quadrants[3], max(quadrants[2], max(quadrants[1], quadrants[0])));
}

int main () {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>b;
	for (int i = 0; i<n; i++) cin>>points[i].x>>points[i].y;

	int m = INT_MAX, local = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			local = calcM(points[i].x+1, points[j].y+1);
			if (local<m) m = local;
		}
	}
	cout<<m<<endl;
	
	return 0;
}
