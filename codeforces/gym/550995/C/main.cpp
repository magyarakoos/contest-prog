#include <iostream>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    for (int x = 0; x <= N; x++) {
        if (N - x * P >= 0 && __popcount(N - x * P) <= x) {
            cout << x;
            exit(0);
        }
    }
    cout << -1;
}
