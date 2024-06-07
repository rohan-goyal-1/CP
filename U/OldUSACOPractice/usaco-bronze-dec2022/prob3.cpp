#include <iostream>
#include <string>
using namespace std;

/*
4

1 3
0 0
0 0
1 1

2 4
00 0
01 1
10 1
11 1

1 2
0 1
0 0

2 4
00 0
01 1
10 1
11 0

*/

void MarkVector (int a[], int index)
{
	a[index] = 1;
}

void ResetVector (int a[], int len)
{
	for (int i=0; i<len; i++) {
		a[i] = 0;
	}
}

void OrVectors (int a[], int b[], int len)
{
	for (int i=0; i<len; i++) {
		a[i] = (a[i]+b[i]);
		if (a[i] == 2) a[i]=1;
	}
}

int PopCount (int a[], int len)
{
	int count=0;
	for (int i=0; i<len; i++) {
		if (a[i] == 1) count++;
	}
	return count;
}

int main () {
	int t;
	// cin>>t;

	int n, m;
	cin>>n>>m;
	string input[m];
	int output[m];
	int input_valid[m];

	ResetVector(input_valid, m);
	
	for (int i = 0; i<m; i++) {
		cin>>input[i];
		cin>>output[i];
	}

	/*for (int i = 0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (input[j]==0
		}
	}*/

	int i=0;
	int temp_input_valid[m];

	ResetVector(temp_input_valid, m);
	OrVectors(temp_input_valid, input_valid, m);

	/*
	for (int j=0; j<n; j++) {
		int in_bit = input[i][j];
		int out_bit = output[i];
		int ambiguity = 0;
		MarkVector(temp_input_valid, i);
		for (int i=1; i<m; i++) {
			if (input_valid[i]==1) continue;
			if (in_bit == input[i][j]) {
				if (out_bit != output[i]) {
					ambiguity = 1;
					break;
				}
				MarkVector(temp_input_valid, i);
			}
		}
		if (ambiguity == 1) {
			ResetVector(temp_input_valid, m);
			i=0;
		} else {
			OrVectors(input_valid, temp_input_valid, m);
			break;
		}
	}
	*/
	char in_bit='0';
	int out_bit;

	for (int j=0; j<n; j++) {
		int ambiguity = 0;
		int first_time = 0;
		for (int i=0; i<m; i++) {
			if (input_valid[i] == 1) continue;
			if (input[i][j] == in_bit) {
				MarkVector(temp_input_valid, i);
				if (first_time==0) {first_time = 1; out_bit = output[i];}
				else {
					if (out_bit != output[i]) {
						ambiguity = 1;
						break;
					}
				}
			}
		}
		if (ambiguity == 1) {
			ResetVector(temp_input_valid, m);
			i=0;
		} else {
			OrVectors(input_valid, temp_input_valid, m);
			break;
		}
	}

	in_bit='1';

	for (int j=0; j<n; j++) {
		int ambiguity = 0;
		int first_time=0;
		for (int i=0; i<m; i++) {
			if (input_valid[i] == 1) continue;
			if (input[i][j] == in_bit) {
				MarkVector(temp_input_valid, i);
				if (first_time==0) {first_time = 1; out_bit = output[i];}
				else {
					if (out_bit != output[i]) {
						ambiguity = 1;
						break;
					}
				}
			}
		}
		if (ambiguity == 1) {
			ResetVector(temp_input_valid, m);
			i=0;
		} else {
			OrVectors(input_valid, temp_input_valid, m);
			break;
		}
	}

	int pop = PopCount(input_valid, m);
	if (m-pop > 1) { cout << "LIE";}
	else { cout << "OK";}
}
