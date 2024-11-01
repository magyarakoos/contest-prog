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

        if (A < 33 || A > 53 || (A - 33 > 10 && B < 22) ||
            (A - 33 == 1 && B - 30 > 11) ||
            (A - 33 > 1 && B - 30 > 22)) {
            cout << "-1 -1\n";
            continue;
        }

        if (A == 33 && B <= 30) {
            for (int i = 0; i < 3; i++) {
                cout << "11 " << min(10, B) << "\n";
                B -= min(10, B);
            }
            continue;
        }

        if (A >= 33 && A <= 43 && B >= 11 && B <= 41) {
            A -= 33;
            B -= 11;
            cout << A << " 11\n";
            for (int i = 0; i < 3; i++) {
                cout << "11 " << min(10, B) << "\n";
                B -= min(10, B);
            }
            continue;
        }

        if (A >= 44 && A <= 53 && B >= 22 && B <= 52) {
            A -= 43;
            B -= 22;
            cout << "10 11\n" << A << " 11\n";
        }
    }
}
