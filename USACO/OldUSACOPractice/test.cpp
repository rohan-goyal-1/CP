#include <iostream>
using namespace std;

int a () {
  cout<<"a"<<endl;
}

int b () {
  cout<<"b"<<endl;
}

int main() {
  int (*foo[2]) (void);
  int b;
  
  foo[0] = a;
  (foo[0])();
  return 0;
}
	
