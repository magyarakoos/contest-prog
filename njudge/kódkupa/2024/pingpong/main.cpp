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
        if (A <= B) {
            cout << "-1 -1\n";
            continue;
        }
        int ro = A / 11;
        int rem = A % 11;
        vector<array<int, 2>> result;
        for (int i = 0; i < ro; i++) {
            int bsc = min(10, B);
            B -= bsc;
            result.push_back({11, bsc});
        }
    }
}
