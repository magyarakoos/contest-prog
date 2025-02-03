#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int N;
    cin >> N;
    vector A(N, vector<int>(N));
    for (auto& row : A) {
        for (int& x : row) cin >> x;
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    return;
    multiset<int> s;
    for (int i = 0; i < N; i++) {
        int suf = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (A[i][j] != 1) break;
            suf += A[i][j];
        }
        s.insert(suf);
    }
    int result = 1;
    while (!s.empty()) {
        int x = *s.begin();
        if (x >= result) x++;
        s.erase(x);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
