#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> st(25, vector<int>(N));
    vector<int> lg(N + 1);
    for (int i = 2; i <= N; i++) { lg[i] = lg[i / 2] + 1; }

    for (int i = 0; i < N; i++) { cin >> st[0][i]; }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
