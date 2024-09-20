#include <iostream>

using namespace std;

int dcnt(int x) {
    for (int d = 2; d <= x && x > 0; d++) {
        while (x > 0) {}
    }
}

int main() {
    int N, P;
    cin >> N >> P;

    for (int x = 0; x <= N; x++) {
        if (N - x * P >= 0 && == x) {
            cout << x;
            exit(0);
        }
    }
    cout << -1;
}
