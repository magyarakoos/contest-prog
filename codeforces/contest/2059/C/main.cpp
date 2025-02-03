#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int N;
    cin >> N;
    vector A(N, vector<int>(N));
    for (auto& row : A) {
        for (int& x : row) cin >> x;
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
