#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    if (N == 1) {
        cout << K << "\n";
        return;
    }
    for (int i = (1 << 30) ; i > 1; i /= 2) {
        if (i - 1 <= K) {
            cout << i - 1 << " " << K - (i - 1);
            break;
        }
    }
    for (int i = 2; i < N; i++) cout << " 0";
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
