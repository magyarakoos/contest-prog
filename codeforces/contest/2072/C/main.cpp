#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N, X, i = 0;
    cin >> N >> X;
    int orr = 0;
    for (; N > 1 && ((X | i) == X); i++, N--) {
        cout << i << " ";
        orr |= i;
    }
    if (N > 1) {
        for (; N > 1; N--) { cout << "0 "; }
        cout << X << "\n";
    } else {
        if ((orr | i) == X) {
            cout << i << "\n";
        } else {
            cout << X << "\n";
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
