/*
3
1 2 1
3 2 1
1 3 1*/

#include <iostream>
#include <fstream>

using namespace std;

bool shells [3];

void swap (int a, int b) {
	bool t = shells[a-1];
	shells[a-1] = shells[b-1];
	shells[b-1] = t;
}
int main () {
	ofstream out;
	ifstream in;
	out.open("shell.out");
	in.open("shell.in");
	
	int n;
	in>>n;
	
	int swaps [n][2];
	int guess [n];
	for (int i = 0; i<n; i++)
		in>>swaps[i][0]>>swaps[i][1]>>guess[i];
	
	int max_score = 0;
	int score;
	for (int j = 0; j<3; j++) {
		score = 0;
		shells[0] = false; shells[1] = false; shells[2] = false;
		shells[j] = true;
	
		//cout<<"Iter"<<endl<<shells[0]<<endl<<shells[1]<<endl<<shells[2]<<endl;
		for (int i = 0; i<n; i++) {
			swap(swaps[i][0], swaps[i][1]);
			if (shells[guess[i]-1] == true) score++;
			/*cout<<"After swap"<<endl<<shells[0]<<endl<<shells[1]<<endl<<shells[2]<<endl;
			cout<<"guess"<<endl<<guess[i]-1<<endl;
			cout<<"score"<<endl<<score<<endl;*/
		}

		if (score>max_score) max_score = score;
	}
	out<<max_score<<endl;
	out.close();
	return 0;
}
