#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> lg(N + 1), a(N);
    vector<vector<int>> stmn(25, vector<int>(N));

    for (int& x : a) cin >> x;

    for (int i = 2; i <= N; i++) { lg[i] = lg[i / 2] + 1; }

    for (int i = 1; i < 25; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {}
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
