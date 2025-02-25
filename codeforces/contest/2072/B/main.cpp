#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    int M = 0;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        M += c == '_';
    }
    N -= M;
    cout << M * (N / 2) * (N / 2 + N % 2) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
