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
    multiset<array<int, 2>> ms;
    for (int i = 0; i < N; i++) {
        int suf = 0;
        ms.insert({0, i});
        for (int j = N - 1; j >= 0; j--) {}
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
