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

        if (ro < 3) {
            cout << "-1 -1\n";
            continue;
        }
    }
}
