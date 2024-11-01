#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;

        if (A < 33 || A > 53) {
            cout << "-1 -1\n";
            continue;
        }

        A -= 33;

        vector<array<int, 2>> result;

        if (A) {
            if (B < 11) {
                cout << "-1 -1\n";
                continue;
            }
            if (A == 1 || B < 22) {
                result.push_back({A, 11});
                B -= 11;
            } else {
                int ra = min(10, A - 1);
                result.push_back({ra, 11});
                result.push_back({A - ra, 11});
                B -= 22;
            }
        }

        for (int i = 0; i < 3; i++) {
            int bsc = min(10, B);
            result.push_back({11, bsc});
            B -= bsc;
        }

        if (B > 0) {
            cout << "-1 -1\n";
            continue;
        }

        for (auto [ac, bc] : result) {
            cout << ac << " " << bc << "\n";
        }
    }
}
