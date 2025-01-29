#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;

    vector<int> result(1);
    int al = 0, ar = N - 1, bl = 0, br = M - 1;
    while (1) { int la = ar - al + 1, lb = br - bl + 1; }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
