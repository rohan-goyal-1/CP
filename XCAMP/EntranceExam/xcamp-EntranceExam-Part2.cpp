#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;

int n, m;
char maze [1000][1000];
int ans = 0;
inline int solve (int x, int y) {
	if (x>=n || x<0 || y>=n || y<0) return ans;
	if (maze[x][y] == '2') return ans;
        cout << x << " " << y << endl;
	ans++;
	char temp = maze[x][y];
	maze[x][y] = '2';
	if (temp == '0') {
	   if (x<n-1 && maze[x+1][y] == '1') solve(x+1, y);
	   if (x>0 && maze[x-1][y] == '1') solve(x-1, y);
	   if (y<n-1 && maze[x][y+1] == '1') solve(x, y+1);
	   if (y>0 && maze[x][y-1] == '1') solve(x, y-1);
	} else if (temp == '1') {
	   if (x<n-1 && maze[x+1][y] == '0') solve(x+1, y);
	   if (x>0 && maze[x-1][y] == '0') solve(x-1, y);
	   if (y<n-1 && maze[x][y+1] == '0') solve(x, y+1);
	   if (y>0 && maze[x][y-1] == '0') solve(x, y-1);
	}
    return ans;

	
	// if (maze[x+1][y] != temp) solve(x+1, y);
	// if (maze[x-1][y] != temp) solve(x-1, y);
	// if (maze[x][y+1] != temp) solve(x, y+1);
	// if (maze[x][y-1] != temp) solve(x, y-1);
}
int main () {
	cin>>n>>m;
	string t;
	char original[1000][1000];
	for (int i = 0; i<n; i++) {
		cin>>t;
		for (int j = 0; j<n; j++) {
			maze[i][j] = t[j];
			original[i][j] = t[j];
		}
	}
	
	int x, y;
	while (m--) {
		cin>>x>>y;
//		cout<<"CALLING SOLVE with x, y "<<x<<" "<<y<<endl;
		solve(x-1, y-1);
		cout<<ans<<endl;
		ans = 0;
		memcpy(maze, original, sizeof(original));
	}

	return 0;
}
