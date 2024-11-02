#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << "-1\n";
        exit(0);
    }

    if (N % 2 == 0) {
        for (int i = 0; i < N; i += 2) { cout << "15"; }
        cout << "\n";
        exit(0);
    }

    cout << "111";
    for (int i = 0; i < N - 3; i += 2) { cout << "15"; }
    cout << "\n";
}

