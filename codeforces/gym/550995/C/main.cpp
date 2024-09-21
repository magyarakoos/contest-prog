#include <iostream>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    for (long long x = 0; x * P <= 1e7; x++) {
        if (N >= x * P && N - x * P <= x) {
            cout << x;
            exit(0);
        }
    }
    cout << -1;
}
