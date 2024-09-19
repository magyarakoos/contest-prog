#include <iostream>
using namespace std;

void solve() {
    int N, x, prv = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        if (prv && x != prv) {
            cout << "1\n";
            return;
        }
        prv = x;
    }

    cout << N << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
