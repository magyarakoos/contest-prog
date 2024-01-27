#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << (char)('a' + j);
        }
    }
    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
