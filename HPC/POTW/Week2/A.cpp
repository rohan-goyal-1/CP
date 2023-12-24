#include <iostream>

using namespace std;

bool isPalindrome (int n) {
    string val = to_string(n);
    string rev = val; reverse(rev.begin(), rev.end());
    return rev == val;
}

int main () {
    int ans = -1;
    for (int i = 999; i >= 100; i--) {
        for (int j = 999; j >= 100; j--) {
            if (isPalindrome(i * j)) ans = max(ans, i * j);
        }
    }
    cout << ans << '\n';

    return 0;
}
