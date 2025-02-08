#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N), m(N);
    for (int& x : P) cin >> x, x--;
    for (int& x : Q) cin >> x, x--;
    for (int i = 0; i < N; i++) { m[Q[i]] = i; }
    for (int i = 0; i < N; i++) {
        cout << Q[P[m[i]]] + 1 << " ";
    }
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
