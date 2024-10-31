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
        int ro = A / 11;
        int rem = A % 11;
        vector<array<int, 2>> result;

        if (rem) { B -= 11; }

        for (int i = 0; i < ro; i++) {
            int bsc = min(10, B);
            B -= bsc;
            result.push_back({11, bsc});
        }

        if (B != 0) {
            cout << "-1 -1\n";
            cerr << endl;
            continue;
        }

        if (rem) { result.push_back({rem, 11}); }

        int wcnt = 0;
        for (auto [ac, bc] : result) { wcnt += ac > bc; }
        if (wcnt * 2 <= result.size()) {
            cout << "-1 -1\n";
        } else {
            for (auto [ac, bc] : result) {
                cout << ac << " " << bc << "\n";
            }
        }
        cerr << endl;
    }
}
