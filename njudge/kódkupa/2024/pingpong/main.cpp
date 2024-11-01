#include <iostream>
using namespace std;

void win_a(int B) {
    for (int i = 0; i < 3; i++) {
        cout << "11 " << min(10, B) << "\n";
        B -= min(10, B);
    }
}

void solve() {
    int A, B;
    cin >> A >> B;

    // 3 - 0
    if (A == 33 && B <= 30) {
        win_a(B);
        return;
    }

    // 3 - 1
    if (A >= 33 && A <= 43 && B >= 11 && B <= 41) {
        cout << A - 33 << " 11\n";
        win_a(B - 11);
        return;
    }

    // 3 - 2
    if (A >= 33 && A <= 53 && B >= 22 && B <= 52) {
        A -= 33;
        for (int i = 0; i < 2; i++) {
            cout << min(10, A) << " 11\n";
            A -= min(10, A);
        }
        win_a(B - 22);
        return;
    }

    cout << "-1 -1\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
