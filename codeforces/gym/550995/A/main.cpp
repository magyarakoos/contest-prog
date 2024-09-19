#include <iostream>

using namespace std;

int N, prv, x;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (prv && x != prv) {
            cout << 1;
            exit(0);
        }
    }
    cout << N;
}
