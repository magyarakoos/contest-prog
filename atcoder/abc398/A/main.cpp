#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    if (N & 1) {
        cout << string(N / 2, '-') << '='
             << string(N / 2, '-') << "\n";
    } else {
        cout << string(N / 2 - 1, '-')
             << "==" << string(N / 2 - 1, '-') << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
