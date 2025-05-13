#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> b(N), w(M);
    for (int& x : b) cin >> x;
    for (int& x : w) cin >> x;
    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());
    for (int i = 1; i < N; i++) b[i] += b[i - 1];
    for (int i = 1; i < M; i++) w[i] += w[i - 1];

    vector<int> smax = b;
    for (int i = N - 2; i >= 0; i--) {
        smax[i] = max(smax[i], smax[i + 1]);
    }

    int result = 0;
    for (int i = 0; i < N && i < M; i++) {
        result = max(result, w[i] + smax[i]);
    }
    for (int i = 0; i < N; i++) {
        result = max(result, b[i]);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
