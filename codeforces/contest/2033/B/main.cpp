#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { cin >> a[i][j]; }
    }

    vector kpS(2 * N - 1, array<int, 2>{0, 0});
    for (int i = 0; i < N; i++) { kpS[i] = {0, i}; }
    for (int j = 1; j < N; j++) { kpS[N + j - 1] = {j, 0}; }

    ll result = 0;

    for (auto [ki, kj] : kpS) {
        int mn = INF;
        for (; ki < N && kj < N; ki++, kj++) {
            mn = min(mn, a[ki][kj]);
        }
        if (mn >= 0) continue;
        result += mn * -1;
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
