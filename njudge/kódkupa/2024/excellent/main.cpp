#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << "-1";
        exit(0);
    }

    switch (N % 3) {
    case 0:
        for (int i = 0; i < N; i++) { cout << "1"; }
        break;
    case 1:
        cout << "111";
        for (int i = 0; i < N - 3; i += 2) { cout << "15"; }
    }
    cout << "\n";
}

