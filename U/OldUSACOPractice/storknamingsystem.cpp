#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	string id;
	string name;

	cin>>id;
	
	char map [8][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};

	bool equal = true;
	vector <string> result;
	while (cin>>name) {
		if (name.size() != id.size()) {
			continue;
		}
		equal = true;
		for (int i = 0; i<name.size(); i++) {
			if (name[i] != map[(id[i]-'0')-2][0] && name[i] != map[(id[i]-'0')-2][1] && name[i] != map[(id[i]-'0')-2][2]) {
				equal = false;
				break;
			}
		}
		if (equal) result.push_back(name);
	}

	if (result.size() == 0) 
		cout<<"NONE";
	else 
		for (int i = 0; i<result.size(); i++) cout<<result[i]<<endl;
}
