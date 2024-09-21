#include <iostream>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    for (long long x = 0; x <= 5; x++) {
        cout << x << " " << x * P << " " << N - x * P << " "
             << __popcount(N - x * P) << "\n";
        if (N >= x * P && N - x * P <= x) {
            cout << x;
            exit(0);
        }
    }
    cout << -1;
}
