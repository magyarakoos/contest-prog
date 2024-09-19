#include <iostream>
using namespace std;

void solve() {
    int N, x, prv = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        if (prv && x != prv) {
            cout << 1;
            return;
        }
    }

    cout << N;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
