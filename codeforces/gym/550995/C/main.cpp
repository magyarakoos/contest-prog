#include <iostream>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    for (long long x = 0; x < 32; x++) {
        if (N >= x * (P + 1) && __popcount(N - x * P) <= x) {
            cout << x;
            exit(0);
        }
    }
    cout << -1;
}
