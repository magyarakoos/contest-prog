// NOTE: it is recommended to use this even if you don't
// understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    switch (N % 3) {
    case 0:
        for (int i = 0; i < N; i++) { cout << "1"; }
        break;
    }
    cout << "\n";

    return 0;
}

