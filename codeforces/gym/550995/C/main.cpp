#include <iostream>

using namespace std;

int dcnt(int x) {
    int result = 0;
    for (int d = 2; d <= x && x > 0; d++) {
        while (x > 0 && x % d == 0) x /= d, result++;
    }
    return result;
}

int main() {
    int N, P;
    cin >> N >> P;

    for (int x = 0; x <= N; x++) {
        if (N - x * P >= 0 && dcnt(N - x * P) == x) {
            cout << x;
            exit(0);
        }
    }
    cout << -1;
}
