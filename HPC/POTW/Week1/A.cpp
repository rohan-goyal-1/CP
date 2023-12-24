#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans = 0;

void solve (vector<int>& digits, int idx) {
    if (idx == digits.size()) {
        int L = digits[0], A = digits[1], N = digits[2], D = digits[3], W = digits[4], I = digits[5], R = digits[6], T = digits[7], H = digits[8], E = digits[9];

        if (L != 0 && W != 0 && E != 0) {
            int LAND = 1000 * L + 100 * A + 10 * N + D;
            int WIND = 1000 * W + 100 * I + 10 * N + D;
            int EARTH = 10000 * E + 1000 * A + 100 * R + 10 * T + H;

            if (LAND + WIND == EARTH)
                ans += EARTH;
        }
    } else {
        for (int i = idx; i < digits.size(); i++) {
            swap(digits[idx], digits[i]);
            solve(digits, idx + 1);
            swap(digits[idx], digits[i]);
        }
    }
}

int main () {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    solve(digits, 0);

    cout << ans / 2 << '\n';

    return 0;
}
