#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> a(N + 2);
    while (K--) {
        int L, R;
        cin >> L >> R;
        a[max(1, L - D + 1)]++;
        a[R + 1]--;
    }
    for (int i = 2; i <= N; i++) { a[i] += a[i - 1]; }

    int mn = INF, mx = -INF;
    int ra, rb;
    for (int i = 1; i <= N - D + 1; i++) {
        int x = a[i];
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << mx << " " << mn << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
