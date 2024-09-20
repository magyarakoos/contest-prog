#include <iostream>

using namespace std;

int dcnt(int x) {
    int result = 0;
    for (int d = 2; d <= x && x > 0; d++) {
        while (x > 0 && x % d == 0) x /= d, result++;
    }
    return result + x;
}

int main() {
    int N, P;
    cin >> N >> P;

    for (int i = 0; i < N; i++) { cout << i << " " << dcnt(i) << "\n"; }
}
