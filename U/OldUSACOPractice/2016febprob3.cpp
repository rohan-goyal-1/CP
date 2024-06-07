#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>

using namespace std;
struct cow {
	int x, y;
};
int calcM(int a, int b, cow cows[], int n) {
	int m;
	int quadrants [4] = {0};
	for (int i = 0; i<n; i++) {
		if (cows[i].x<a && cows[i].y>b) quadrants[0]++;
		if (cows[i].x>a && cows[i].y>b) quadrants[1]++;	
		if (cows[i].x<a && cows[i].y<b) quadrants[2]++;
		if (cows[i].x>a && cows[i].y<b) quadrants[3]++;
	}
	sort (quadrants, quadrants+4);
	m = quadrants[3];
	return m;
}
int main () {	
	int n, b;
	cin>>n>>b;
	cow cows[n];
	for (int i = 0; i<n; i++) cin>>cows[i].x>>cows[i].y;
	int minm = INT_MAX;
	int temp;
	int x, y;
	for (int i = 0; i<n; i++) {
		x = cows[i].x+1;
		for (int j = 0; j<n; j++) {
			temp = calcM(x, cows[j].y+1, cows, n);
			if (temp<minm) minm = temp;	
		}
	}
	cout<<minm;

	return 0;
}
